// Lab_02_1.cpp
// Саламаха Роман
// Лабораторна робота № 2.1
// Лінійні програми.
// Варіант 25

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double alpha; // вхідний параметр (кут у радіанах)
    double z1;    // результат обчислення 1-го виразу
    double z2;    // результат обчислення 2-го виразу

    cout << "alpha = "; cin >> alpha;

    z1 = 1 - 1. / 4 * sin(2 * alpha) * sin(2 * alpha) + cos(2 * alpha);
    z2 = cos(alpha) * cos(alpha) + pow(cos(alpha), 4);

    cout << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    cin.get();
    return 0;
}
