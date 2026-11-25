#include <iostream>
#include "student.h"

int passed = 0, failed = 0;

void Check(const string& name, bool ok)
{
    cout << (ok ? "[ PASSED ] " : "[ FAILED ] ") << name << endl;
    if (ok) passed++; else failed++;
}

Student Make(string prizv, Spec spec, int matematyka)
{
    Student s;
    s.prizv = prizv;
    s.kurs = 1;
    s.spec = spec;
    s.fizyka = 5;
    s.matematyka = matematyka;
    s.pedahohika = 5;
    return s;
}

int main()
{
    Student p[5];
    p[0] = Make("Shevchuk", INF, 4);
    p[1] = Make("Bondar", KN, 5);
    p[2] = Make("Koval", INF, 4);
    p[3] = Make("Melnyk", KN, 3);
    p[4] = Make("Tkachuk", TN, 5);

    Check("Less: KN before INF", Less(p[1], p[2]));
    Check("Less: same spec, math 3 before 5", Less(p[3], p[1]));
    Check("Less: same spec and math, Koval before Shevchuk",
          Less(p[2], p[0]) && !Less(p[0], p[2]));

    int* I = IndexSort(p, 5);
    Check("IndexSort: I = 3 1 2 0 4", I[0] == 3 && I[1] == 1 &&
          I[2] == 2 && I[3] == 0 && I[4] == 4);
    Check("IndexSort: array not changed", p[0].prizv == "Shevchuk");
    delete[] I;

    Sort(p, 5);
    Check("Sort: Melnyk Bondar Koval Shevchuk Tkachuk",
          p[0].prizv == "Melnyk" && p[1].prizv == "Bondar" &&
          p[2].prizv == "Koval" && p[3].prizv == "Shevchuk" &&
          p[4].prizv == "Tkachuk");

    Check("BinSearch: Koval INF 4 -> 2",
          BinSearch(p, 5, "Koval", INF, 4) == 2);
    Check("BinSearch: Koval INF 5 -> -1",
          BinSearch(p, 5, "Koval", INF, 5) == -1);
    Check("BinSearch: Petrenko KN 5 -> -1",
          BinSearch(p, 5, "Petrenko", KN, 5) == -1);

    cout << endl << passed << " passed, " << failed << " failed" << endl;
    return failed;
}
