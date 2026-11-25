// UnitTest_08_1.cpp
// Unit-тест функцій ScanCommaDash, QtyCommaDash, ReplaceCommaDash з Лабораторної роботи № 8.1

#define UNIT_TEST
#include "Lab_08_1.cpp"
#include <cstring>

int passed = 0, failed = 0;

void Check(const char* name, bool ok)
{
    if (ok)
    {
        cout << "[ PASSED ] " << name << endl;
        passed++;
    }
    else
    {
        cout << "[ FAILED ] " << name << endl;
        failed++;
    }
}

int main()
{
    char r[101];

    Check("TestMethod1", ScanCommaDash("a,-b") == true);          // пара є
    Check("TestMethod2", ScanCommaDash("a-,b, -c") == false);  // "-," і ", -" не пари
    Check("TestMethod3", QtyCommaDash("x,-y,-z") == 2);
    Check("TestMethod4", QtyCommaDash(",,--") == 1);
    ReplaceCommaDash("x,-y,-z", r);
    Check("TestMethod5", strcmp(r, "x*y*z") == 0);
    ReplaceCommaDash("abc,", r);
    Check("TestMethod6", strcmp(r, "abc,") == 0);           // кома в кінці

    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
