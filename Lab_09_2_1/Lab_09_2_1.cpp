#include <iostream>
#include "macros.h"

using namespace std;

double W(double x, double y)
{
#if Z == 1
    return MAX(SQR(x - y), ABS(y - x));
#else
    return MIN(x + SQR(y), Z + SQR(x));
#endif
}

#ifndef UNIT_TEST
int main()
{
    double x, y;

#if Z == 1
    cout << "z = " << Z << ": w = max((x - y)^2, |y - x|)" << endl;
#else
    cout << "z = " << Z << ": w = min(x + y^2, z + x^2)" << endl;
#endif

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    double w = W(x, y);
    PRINT(w);

    return 0;
}
#endif
