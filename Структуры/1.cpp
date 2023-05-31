#include<iostream>
#include<string>
#include <fstream>
#include <cmath>
using namespace std;
struct hotel {
    string fio, datein, days;
    int d, m, y, d1, m1, y1, day;
};
int vis(int n) {
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
        return 1;
    }
    return 0;
}
int D_I_M(int month, int year)
{
    static const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && vis(year))
        return 29;

    return daysInMonth[month - 1];
}

void A_Date(int n_days, int d1, int m1, int y1, int& d, int& m, int& y)
{
    d = d1;
    m = m1;
    y = y1;
    int dm = D_I_M(m, y);

    if (dm - d >= n_days) {
        d += n_days;
        return;
    }
    else {
        n_days -= (dm - d + 1);
        d = 1;
        ++m;
    }

    while (true)
    {
        int dm = D_I_M(m, y);

        if (dm - d >= n_days) {
            d += n_days;
            break;
        }
        else
            n_days -= (dm - d + 1);

        if (++m > 12) {
            m = 1;
            ++y;
        }
    }
}

int corr(int d, int m, int y) {//Корректность данных
    if (m == 2) {
        if (vis(y) == 1) {
            if (d > 0 && d <= 29) {
                return 1;
            }
        }
        else {
            if (d > 0 && d <= 28) {
                return 1;
            }
        }
    }
    if (m == 1 || m == 5 || m == 8 || m == 10 || m == 12 || m == 3) {
        if (d > 0 && d <= 31) {
            return 1;
        }
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 0 && d <= 30) {
            return 1;
        }
    }
    return 0;
}
int date(int& x, int& y, int& z, string s) {
    string s1;
    for (int i = 0; i < s.size(); i++) {
        if (i == s.find('.')) {
            x = stoi(s1);
            s1.erase();
            i++;
        }
        if (i == s.find('.', s.find('.') + 1)) {
            y = stoi(s1);
            s1.erase();
            i++;
        }
        if (i == s.size() - 1) {
            s1 += s[i];
            z = stoi(s1);
            s1.erase();
        }
        s1 += s[i];
    }
    return 1;
}
string strdate(int d, int m, int y) {
    string xs;
    xs += to_string(y);
    if (m < 10) {
        xs += "0" + to_string(m);
    }
    else {
        xs += to_string(m);
    }
    if (d < 10) {
        xs += "0" + to_string(d);
    }
    else {
        xs += to_string(d);
    }
    return xs;
}
int res(int d, int y, int m, int d1, int m1, int y1, int xd, int yd, int zd) {
    string s, s1, s2;
    int fs, sd, td;

    s = strdate(d, m, y);
    s1 = strdate(d1, m1, y1);
    s2 = strdate(xd, yd, zd);
    fs = stoi(s);
    sd = stoi(s1);
    td = stoi(s2);
    if (fs - td <= 0 && sd - td >= 0) {
        return 1;
    }
    return 0;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int i, n;
    string s, s1;
    int xd, yd, zd;
    cout << "Коллическтво турристов = "; cin >> n;
    hotel* m = new hotel[n];
    for (i = 0; i < n; i++) {
        cout << "Турист (Фио,дата прибытия,дней в отеле)" << " " << i + 1 << ": ";
        getline(cin, m[i].fio, ',');
        getline(cin, m[i].datein, ',');
        date(m[i].d, m[i].m, m[i].y, m[i].datein);
        getline(cin, m[i].days);
        m[i].day = stoi(m[i].days);
        A_Date(m[i].day, m[i].d, m[i].m, m[i].y, m[i].d1, m[i].m1, m[i].y1);
    }
    cout << "Нужный день ";
    getline(cin, s);
    date(xd, yd, zd, s);
    if (corr(xd, yd, zd) == 0) {
        cout << "Данные не корректны \n";
        system("pause");
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (res(m[i].d, m[i].y, m[i].m, m[i].d1, m[i].m1, m[i].y1, xd, yd, zd) == 1 && corr(m[i].d, m[i].m, m[i].y) == 1) {
            cout << m[i].fio << endl;
        }
    }
    system("pause");
}
// a a a, 31.12.2022, 40
// b b b, 15.01.2023, 20
// c c c, 20.01.2023, 15
// 18.01.2023