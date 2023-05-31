#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
ifstream input("C:\\Users\\contest.W12-415-005.000.001\\Downloads\\13032023\\Сортировка_ввод.txt"); //файл из которого берем данные 
ofstream output("C:\\Users\\contest.W12-415-005.000.001\\Downloads\\13032023\\Сортировка_вывод.txt"); //файл в который будем записыать даннные
int tmp = 0;
struct date { //структура для даты
    int day, mon, year;
};

struct people { //структура для информации о человеке
    string name;
    string job;
    int exp;
    date dob;
    int pay;
};

date str_to_date(string s) { //перевод из строки в date
    date x;
    string t = s.substr(0, 2);//день
    x.day = atoi(t.c_str());//перевод
    t = s.substr(3, 2);//месяц
    x.mon = atoi(t.c_str());//перевод
    t = s.substr(6, 4);//год
    x.year = atoi(t.c_str());//перевод
    return x;
}
string str_to_data(string x) { //перевод из строки в информацию
    string s;
    while (tmp != min(x.size(), x.find(',', tmp))) { //т.к данные указаны через "," то применяем цикл
        s += x[tmp];
        tmp++;
    }
    tmp += 2;
    return s;
}
vector <people> inFile() { //заполняем вектор информацией о людях 
    vector<people> x;
    people temp;
    string s;
    while (input.peek() != EOF) {
        getline(input, s);
        temp.name = str_to_data(s); //получаем имя
        temp.job = str_to_data(s); //получаем профессию 
        temp.dob = str_to_date(str_to_data(s)); //получаем дату рождения
        temp.exp = atoi(str_to_data(s).c_str()); //получаем стаж
        temp.pay = atoi(str_to_data(s).c_str()); //получаем зарплату 
        tmp = 0; //обнуляем счетчик 
        x.push_back(temp); //записываем информацию 

    }
    return x; //возвращаем вектор 
}

void OutFile(vector<people> x) { //Функция записи данных в файл
    for (int i = 0; i < x.size(); i++) {
        output << x[i].name << ", ";
        output << x[i].job << ", ";
        if (x[i].dob.day < 10) output << '0' << x[i].dob.day << '.';
        else output << x[i].dob.day << '.';
        if (x[i].dob.mon < 10) output << '0' << x[i].dob.mon << '.';
        else output << x[i].dob.mon << '.';
        output << x[i].dob.year << ", ";
        output << x[i].exp << ", ";
        output << x[i].pay << '\n';
    }

}
bool operator <(people x, people y) { //переопределяем оператор "<"
    if (x.name < y.name) return true;
    if (x.name == y.name && x.job < y.job) return true;
    return false;
}
void Shell_sort(vector<people>& x, int size) { //Функция сортировки
    int n = size;
    int s = 0;
    int step = n / (pow(2, s));
    while (step > 1) {
        int step = n / (pow(2, s));
        for (int i = 0; i < n - step; i++) {
            int j = i;
            while ((j >= 0) && (x[j + step] < x[j])) {
                swap(x[j], x[j + step]);
                j -= step;
            }
        }
        s++;
        if (step == 0) {
            break;
        }
    } 
}
int main()
{
    setlocale(LC_ALL, "rus");
    vector<people> x;
    x = inFile();
    Shell_sort(x, x.size());
    OutFile(x);
}





