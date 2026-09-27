// Lab_03_4.cpp
// Саламаха Роман
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 25

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y; // координати точки
    double R;    // радіус кола

    cout << "R = "; cin >> R;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    // заштрихована область складається з трьох частин:
    // 1) чверть круга в I чверті:   x >= 0, y >= 0, x^2 + y^2 <= R^2
    // 2) трикутник у II чверті:      x <= 0, y >= 0, y <= x + R
    // 3) чверть круга в III чверті: x <= 0, y <= 0, x^2 + y^2 <= R^2
    if ((x >= 0 && y >= 0 && x * x + y * y <= R * R) ||
        (x <= 0 && y >= 0 && y <= x + R) ||
        (x <= 0 && y <= 0 && x * x + y * y <= R * R))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cin.get();
    return 0;
}
