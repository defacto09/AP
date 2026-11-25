#include <iostream>
#include <cmath>
#include "student.h"

int passed = 0, failed = 0;

void Check(const string& name, bool ok)
{
    cout << (ok ? "[ PASSED ] " : "[ FAILED ] ") << name << endl;
    if (ok) passed++; else failed++;
}

int main()
{
    Student p[4] = {
        { "Bondar", 1, KN, 5, 5, 5 },
        { "Koval", 2, INF, 5, 4, 5 },
        { "Melnyk", 1, TN, 3, 5, 4 },
        { "Shevchuk", 3, ME, 5, 5, 5 }
    };

    Check("IsExcellent: 5 5 5 -> true", IsExcellent(p[0]));
    Check("IsExcellent: 5 4 5 -> false", !IsExcellent(p[1]));
    Check("IsExcellent: 3 5 4 -> false", !IsExcellent(p[2]));
    Check("PercentExcellent = 50%", fabs(PercentExcellent(p, 4) - 50) < 1e-9);
    p[3].informatyka = 4;
    Check("After change = 25%", fabs(PercentExcellent(p, 4) - 25) < 1e-9);

    cout << endl << passed << " passed, " << failed << " failed" << endl;
    return failed;
}
