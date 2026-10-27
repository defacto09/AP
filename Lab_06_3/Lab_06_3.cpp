// Lab_06_3.cpp
// Сума парних елементів масиву: звичайна функція та шаблон функції
// (ітераційний спосіб)
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int SumEven(int* a, const int size);
template <typename T>
T SumEvenT(T* a, const int size);

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));     // ініціалізація генератора випадкових чисел
    const int n = 10;
    int a[n];
    Create(a, n, -20, 20);
    Print(a, n);

    cout << "SumEven(a, n)       = " << SumEven(a, n) << endl;        // звичайна функція
    cout << "SumEvenT<int>(a, n) = " << SumEvenT<int>(a, n) << endl;  // шаблон, T = int

    long long b[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };               // той самий шаблон для іншого типу
    cout << "SumEvenT<long long>(b, n) = " << SumEvenT<long long>(b, n) << endl;
    return 0;
}
#endif

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int SumEven(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0)
            s += a[i];
    return s;
}

template <typename T>
T SumEvenT(T* a, const int size)
{
    T s = T();                       // нульове значення типу T
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0)
            s += a[i];
    return s;
}
