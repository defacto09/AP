// Lab_03_3.cpp
// Саламаха Роман
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 27

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x; // аргумент
    double R; // радіус кола (0 < R < 6)
    double y; // значення функції

    cout << "R = "; cin >> R;
    cout << "x = "; cin >> x;

    if (x <= -R)
        y = R;                                    // горизонтальна пряма y = R
    else
        if (x <= R)
            y = R - sqrt(R * R - x * x);          // нижнє півколо з центром (0; R)
        else
            if (x <= 6)
                y = R + (x - R) * (-3 - R) / (6 - R); // відрізок (R; R) - (6; -3)
            else
                y = x - 9;                        // пряма через (6; -3) і (9; 0)

    cout << endl;
    cout << "y = " << y << endl;

    return 0;
}
