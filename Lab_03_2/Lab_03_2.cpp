// Lab_03_2.cpp
// Саламаха Роман
// Лабораторна робота № 3.2
// Розгалуження, задане формулою: функція з параметрами.
// Варіант 27

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c; // параметри
    double x;       // аргумент
    double F;       // результат обчислення функції

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "x = "; cin >> x;

    // спосіб 1: розгалуження в скороченій формі
    if (x < 5 && c != 0)
        F = -a * x * x - b;
    if (x > 5 && c == 0)
        F = (x - a) / x;
    if (!(x < 5 && c != 0) && !(x > 5 && c == 0))
        F = -x / c;

    cout << endl;
    cout << "1) F = " << F << endl;

    // спосіб 2: розгалуження в повній формі
    if (x < 5 && c != 0)
        F = -a * x * x - b;
    else
        if (x > 5 && c == 0)
            F = (x - a) / x;
        else
            F = -x / c;

    cout << "2) F = " << F << endl;

    return 0;
}
