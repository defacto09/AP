#include <iostream>
#include <iomanip>
#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    do { cout << "x_p = "; cin >> x_p; } while (!(-1 < x_p && x_p < 1));
    do { cout << "x_k = "; cin >> x_k; } while (!(-1 < x_k && x_k < 1));
    do { cout << "dx = "; cin >> dx; } while (dx <= 0);
    do { cout << "e = "; cin >> e; } while (e <= 0);
    cout << endl;

    cout << "Таблиця значень ln((1 + x) / (1 - x))" << endl;
    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(10) << "ln(...)" << " |"
         << setw(10) << "S" << " |"
         << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = x_p;
    while (x <= x_k + 1e-9)
    {
        sum();
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(10) << setprecision(5) << log((1 + x) / (1 - x)) << " |"
             << setw(10) << setprecision(5) << s << " |"
             << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-----------------------------------------" << endl;

    return 0;
}
