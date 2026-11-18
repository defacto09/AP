#define UNIT_TEST
#include "Lab_09_2_1.cpp"

int passed = 0, failed = 0;

void Check(const char* name, bool ok)
{
    cout << (ok ? "[ PASSED ] " : "[ FAILED ] ") << name << endl;
    if (ok) passed++; else failed++;
}

int main()
{
    Check("SQR(1 + 2) == 9", SQR(1 + 2) == 9);
    Check("ABS(-4) == 4", ABS(-4) == 4);
    Check("MAX(3, 7) == 7", MAX(3, 7) == 7);
    Check("MIN(3, 7) == 3", MIN(3, 7) == 3);
    Check("IS_ONE(Z)", IS_ONE(Z));
    Check("W(5, 2) == 9", W(5, 2) == 9);
    Check("W(1, 1.5) == 0.5", W(1, 1.5) == 0.5);

    cout << passed << " passed, " << failed << " failed" << endl;
    return failed;
}
