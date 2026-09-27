// Lab_03_4.cpp
// Саламаха Роман
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 27

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

    // круг з центром (-R; R) радіуса R  або  прямокутник 0<=x<=2R, -R<=y<=0
    if ((x + R) * (x + R) + (y - R) * (y - R) <= R * R ||
        (x >= 0 && x <= 2 * R && y <= 0 && y >= -R))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
