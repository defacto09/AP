#include <iostream>
#include <cmath>
#include "student.h"

int passed = 0, failed = 0;

void Check(const string& name, bool ok)
{
    cout << (ok ? "[ PASSED ] " : "[ FAILED ] ") << name << endl;
    if (ok) passed++; else failed++;
}

Student Make(string prizv, Spec spec, int fizyka, int matematyka, int third)
{
    Student s;
    s.prizv = prizv;
    s.kurs = 1;
    s.spec = spec;
    s.fizyka = fizyka;
    s.matematyka = matematyka;
    switch (spec)
    {
    case KN:
        s.prohramuvannia = third;
        break;
    case INF:
        s.chyselni_metody = third;
        break;
    default:
        s.pedahohika = third;
        break;
    }
    return s;
}

int main()
{
    Student p[4];
    p[0] = Make("Bondar", KN, 5, 5, 5);
    p[1] = Make("Koval", INF, 5, 4, 5);
    p[2] = Make("Melnyk", TN, 3, 5, 4);
    p[3] = Make("Shevchuk", ME, 5, 5, 5);

    Check("ThirdMark: KN -> programming", ThirdMark(p[0]) == 5);
    Check("ThirdMark: TN -> pedagogy", ThirdMark(p[2]) == 4);
    Check("IsExcellent: 5 5 5 -> true", IsExcellent(p[0]));
    Check("IsExcellent: 5 4 5 -> false", !IsExcellent(p[1]));
    Check("PercentExcellent = 50%", fabs(PercentExcellent(p, 4) - 50) < 1e-9);
    p[3].pedahohika = 4;
    Check("After change = 25%", fabs(PercentExcellent(p, 4) - 25) < 1e-9);

    cout << endl << passed << " passed, " << failed << " failed" << endl;
    return failed;
}
