// UnitTest_06_4.cpp
// Unit-тест функцій з Лабораторної роботи № 6.4

#define UNIT_TEST
#include "Lab_06_4.cpp"

int passed = 0, failed = 0;

// аналог Assert::AreEqual для дійсних чисел (з точністю eps)
void AreEqual(const char* name, double expected, double actual, double eps = 1e-9)
{
    if (fabs(expected - actual) < eps)
    {
        cout << "[ PASSED ] " << name << endl;
        passed++;
    }
    else
    {
        cout << "[ FAILED ] " << name << ": expected " << expected
             << ", actual " << actual << endl;
        failed++;
    }
}

int main()
{
    const int n = 8;
    double* p = new double[n];
    double init[n] = { 1.5, -3.0, 4.2, -0.5, 2.0, -6.1, 0.8, -2.5 };
    for (int i = 0; i < n; i++) p[i] = init[i];

    AreEqual("TestMethod1: Max = 4.2", 4.2, Max(p, n));
    AreEqual("TestMethod2: LastPositive = 6", 6, LastPositive(p, n));
    // 1.5 - 3.0 + 4.2 - 0.5 + 2.0 - 6.1 = -1.9
    AreEqual("TestMethod3: SumBefore(6) = -1.9", -1.9, SumBefore(p, 6));

    double neg[3] = { -1.0, -2.0, -3.0 };
    AreEqual("TestMethod4: no positive -> LastPositive = -1", -1, LastPositive(neg, 3));

    // |x| в [1; 3] видаляються: 1.5, -3.0, 2.0, -2.5
    Compress(p, n, 1, 3);
    double expected[n] = { 4.2, -0.5, -6.1, 0.8, 0, 0, 0, 0 };
    bool same = true;
    for (int i = 0; i < n; i++)
        if (fabs(p[i] - expected[i]) > 1e-9) same = false;
    AreEqual("TestMethod5: Compress(1, 3)", 1, same);

    delete[] p;
    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
