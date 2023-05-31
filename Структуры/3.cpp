#include <math.h>
#include <iostream>
#include <conio.h>
using namespace std;
struct complex
{
    long double Re, Im, Modul, Argum;
};
complex input_alg() { //ввод в алг форме
    complex numb1;
    cout << "Введите число\n";
    cout << "Введите Действительную часть: "; cin >> numb1.Re;
    cout << "Введите Мнимую часть: "; cin >> numb1.Im;
    return numb1;
}
complex input_trig() {//ввод в триг форме
    complex numb1;
    cout << "Введите число\n";
    cout << "Введите модуль: "; cin >> numb1.Modul;
    cout << "Введите аргумень: "; cin >> numb1.Im;
    return numb1;
}
complex conv_to_trig(complex numb1) {//перевод в триг форму
    complex temp;
    temp.Modul = sqrt(numb1.Re * numb1.Re + numb1.Im * numb1.Im);//формула модуля комплексного числа
    temp.Argum = atan(numb1.Im / numb1.Re);//формула аргумента комплексного числа
    return temp;
}
complex conv_to_alg(complex numb1) {//перевод в алг форму
    complex temp;
    temp.Re = numb1.Modul * cos(numb1.Argum);//формула действительой части
    temp.Im = numb1.Modul * sin(numb1.Argum);//формула мнимой части
    return temp;
}
complex plus_alg(complex numb1, complex numb2) {//сложение в алг форме
    complex temp;
    temp.Re = numb1.Re + numb2.Re;
    temp.Im = numb1.Im + numb2.Im;
    return temp;
}
complex minus_alg(complex numb1, complex numb2) {//вычитание в алг форме
    complex temp;
    temp.Re = numb1.Re - numb2.Re;
    temp.Im = numb1.Im - numb2.Im;
    return temp;
}
complex mult_alg(complex numb1, complex numb2) {//умножение в алг форме
    complex temp;
    temp.Re = numb1.Re * numb2.Re - numb1.Im * numb2.Im;
    temp.Im = numb1.Im * numb2.Re + numb1.Re * numb2.Im;
    return temp;
}
complex div_alg(complex numb1, complex numb2) {//деление в алг форме
    complex temp;
    temp.Re = (numb1.Re * numb2.Re + numb1.Im * numb2.Im) / (numb2.Re * numb2.Re + numb2.Im * numb2.Im);
    temp.Im = (numb1.Im * numb2.Re - numb1.Re * numb2.Im) / (numb2.Re * numb2.Re + numb2.Im * numb2.Im);
    return temp;
}
complex pow_alg(complex numb1, int n) {//возведение в степень в алг форме
    complex temp;
    temp.Re = numb1.Re;
    temp.Im = numb1.Im;
    for (int i = 1; i < n; i++) {
        temp = mult_alg(temp, numb1);
    }
    return temp;
}
complex output_trig(complex numb1, complex numb2, int n) {//вывод в триг форме
    complex temp;
    temp = plus_alg(numb1, numb2);
    temp = conv_to_trig(temp);
    cout << "Сложение: " << temp.Modul << " ( cos ( " << temp.Argum << " ) + i sin ( " << temp.Argum << " ) ) " << endl;
    temp = minus_alg(numb1, numb2);
    temp = conv_to_trig(temp);
    cout << "Вычитание: " << temp.Modul << " ( cos ( " << temp.Argum << " ) + i sin ( " << temp.Argum << " ) ) " << endl;
    temp = mult_alg(numb1, numb2);
    temp = conv_to_trig(temp);
    cout << "Умножение: " << temp.Modul << " ( cos ( " << temp.Argum << " ) + i sin ( " << temp.Argum << " ) ) " << endl;
    temp = div_alg(numb1, numb2);
    temp = conv_to_trig(temp);
    cout << "Деление: " << temp.Modul << " ( cos ( " << temp.Argum << " ) + i sin ( " << temp.Argum << " ) ) " << endl;
    temp = pow_alg(numb1, n);
    temp = conv_to_trig(temp);
    cout << "Возведение в " << n << " степень: " << temp.Modul << " ( cos ( " << temp.Argum << " ) + i sin ( " << temp.Argum << " ) ) " << endl;
    return temp;
}
complex output_alg(complex numb1, complex numb2, int n) {//вывод в алг форме
    complex temp;
    temp = plus_alg(numb1, numb2);
    cout << "Сложение: " << temp.Re << " + " << temp.Im << "i" << endl;
    temp = minus_alg(numb1, numb2);
    cout << "Вычитание: " << temp.Re << " + " << temp.Im << "i" << endl;
    temp = mult_alg(numb1, numb2);
    cout << "Умножение: " << temp.Re << " + " << temp.Im << "i" << endl;
    temp = div_alg(numb1, numb2);
    cout << "Деление: " << temp.Re << " + " << temp.Im << "i" << endl;
    temp = pow_alg(numb1, n);
    cout << "Возведение в " << n << " степень " << temp.Re << " + " << temp.Im << "i" << endl;
    return temp;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int k, x, n;
    complex numb1, numb2, res;
    cout << "В какую степень возвести? \n";
    cin >> n;
    cout << "В какой форме вводить данные? \n"; cout << "1 - в алгебраической форме\n"; cout << "2 - в тригонометрической форме\n"; cin >> k;
    switch (k) {
    case(1): {
        numb1 = input_alg();
        numb2 = input_alg();
        cout << "В какой форме ввыводить данные? \n"; cout << "1 - в алгебраической форме\n"; cout << "2 - в тригонометрической форме\n"; cin >> x;
        switch (x) {
        case(1): {
            output_alg(numb1, numb2, n);
            break;
        }
        case(2): {
            output_trig(numb1, numb2, n);
            break;
        }
        }
        break;
    }
    case(2): {
        numb1 = input_trig();
        numb1 = conv_to_alg(numb1);
        numb2 = input_trig();
        numb2 = conv_to_alg(numb2);
        cout << "В какой форме ввыводить данные? \n"; cout << "1 - в алгебраической форме\n"; cout << "2 - в тригонометрической форме\n"; cin >> x;
        switch (x) {
        case(1): {
            output_alg(numb1, numb2, n);
            break;
        }
        case(2): {

            output_trig(numb1, numb2, n);
            break;
        }
               break;
        }

    }
    }
}