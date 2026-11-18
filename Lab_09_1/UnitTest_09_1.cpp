#include <iostream>
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsVar;

int passed = 0, failed = 0;

void Check(const char* name, bool ok)
{
    cout << (ok ? "[ PASSED ] " : "[ FAILED ] ") << name << endl;
    if (ok) passed++; else failed++;
}

int main()
{
    x = 0.5; n = 1; a = 0.5;
    nsDod::dod();
    Check("dod: x=0.5, n=1", fabs(a - 0.5 * 0.25 / 3) < 1e-12);

    n = 2; a = pow(0.5, 3) / 3;
    nsDod::dod();
    Check("dod: x=0.5, n=2", fabs(a - pow(0.5, 5) / 5) < 1e-12);

    x = 0; e = 1e-6;
    nsSum::sum();
    Check("sum: x=0", fabs(s) < 1e-12);

    double xs[] = { 0.5, -0.3, 0.9 };
    for (double v : xs)
    {
        x = v; e = 1e-8;
        nsSum::sum();
        Check(v == 0.5 ? "sum: x=0.5" : (v < 0 ? "sum: x=-0.3" : "sum: x=0.9"),
              fabs(s - log((1 + v) / (1 - v))) < 1e-6);
    }

    cout << passed << " passed, " << failed << " failed" << endl;
    return failed;
}
