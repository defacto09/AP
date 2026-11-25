#include <iostream>
#include <cstdio>
#include "train.h"

int passed = 0, failed = 0;

void Check(const string& name, bool ok)
{
    cout << (ok ? "[ PASSED ] " : "[ FAILED ] ") << name << endl;
    if (ok) passed++; else failed++;
}

int main()
{
    int N = 3;
    Train* p = new Train[N];
    p[0] = { "Lviv", EXPRESS, 9, 15 };
    p[1] = { "Kyiv", ORDINARY, 7, 40 };
    p[2] = { "Odesa", COMFORT, 18, 5 };

    Check("Minutes: 09:15 -> 555", Minutes(p[0]) == 555);

    Add(p, N, { "Brody", ORDINARY, 12, 0 });
    Check("Add: N = 4, last is Brody",
          N == 4 && p[3].punkt == "Brody" && p[0].punkt == "Lviv");

    SortByTime(p, N);
    Check("SortByTime: Kyiv Lviv Brody Odesa",
          p[0].punkt == "Kyiv" && p[1].punkt == "Lviv" &&
          p[2].punkt == "Brody" && p[3].punkt == "Odesa");

    SortByPunkt(p, N);
    Check("SortByPunkt: Brody Kyiv Lviv Odesa",
          p[0].punkt == "Brody" && p[1].punkt == "Kyiv" &&
          p[2].punkt == "Lviv" && p[3].punkt == "Odesa");

    Remove(p, N, 1);
    Check("Remove No 2: N = 3, Brody Lviv Odesa",
          N == 3 && p[0].punkt == "Brody" && p[1].punkt == "Lviv" &&
          p[2].punkt == "Odesa");

    int M = 0;
    Train* q = new Train[M];
    Check("SaveToFile: true", SaveToFile(p, N, "test_10_3.txt"));
    Check("LoadFromFile: same data",
          LoadFromFile(q, M, "test_10_3.txt") && M == 3 &&
          q[2].punkt == "Odesa" && q[2].type == COMFORT &&
          q[2].hour == 18 && q[2].minute == 5);
    Check("LoadFromFile: no file -> false",
          !LoadFromFile(q, M, "no_dir/no_file.txt"));
    remove("test_10_3.txt");

    delete[] p;
    delete[] q;
    cout << endl << passed << " passed, " << failed << " failed" << endl;
    return failed;
}
