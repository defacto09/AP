// UnitTest_06_3.cpp
// Unit-тест функцій SumEven та SumEvenT з Лабораторної роботи № 6.3

#define UNIT_TEST
#include "Lab_06_3.cpp"

int passed = 0, failed = 0;

// аналог Assert::AreEqual для цілих чисел
void AreEqual(const char* name, long long expected, long long actual)
{
    if (expected == actual)
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
    int a[10] = { 0, -6, -9, 5, -7, 16, -18, 9, -10, -14 };   // парні: 0, -6, 16, -18, -10, -14
    int odd[4] = { 1, -3, 5, 7 };                             // парних немає
    long long b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };      // парні: 2 + 4 + 6 + 8 + 10

    AreEqual("TestMethod1: SumEven(a) = -32", -32, SumEven(a, 10));
    AreEqual("TestMethod2: SumEvenT<int>(a) = -32", -32, SumEvenT<int>(a, 10));
    AreEqual("TestMethod3: SumEven(odd) = 0", 0, SumEven(odd, 4));
    AreEqual("TestMethod4: SumEvenT<long long>(b) = 30", 30, SumEvenT<long long>(b, 10));

    cout << "Tests passed: " << passed << ", failed: " << failed << endl;
    return failed;
}
