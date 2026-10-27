// Lab_06_3_rec.cpp
// Сума парних елементів масиву: звичайна функція та шаблон функції
// (рекурсивний спосіб)
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
int SumEven(int* a, const int size, int i);
template <typename T>
T SumEvenT(T* a, const int size, int i);

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));     // ініціалізація генератора випадкових чисел
    const int n = 10;
    int a[n];
    Create(a, n, -20, 20, 0);
    Print(a, n, 0);

    cout << "SumEven(a, n, 0)       = " << SumEven(a, n, 0) << endl;        // звичайна функція
    cout << "SumEvenT<int>(a, n, 0) = " << SumEvenT<int>(a, n, 0) << endl;  // шаблон, T = int

    long long b[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };                     // той самий шаблон для іншого типу
    cout << "SumEvenT<long long>(b, n, 0) = " << SumEvenT<long long>(b, n, 0) << endl;
    return 0;
}
#endif

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int SumEven(int* a, const int size, int i)
{
    if (i == size)                   // усі елементи переглянуто
        return 0;
    if (a[i] % 2 == 0)
        return a[i] + SumEven(a, size, i + 1);
    return SumEven(a, size, i + 1);
}

template <typename T>
T SumEvenT(T* a, const int size, int i)
{
    if (i == size)
        return T();                  // нульове значення типу T
    if (a[i] % 2 == 0)
        return a[i] + SumEvenT<T>(a, size, i + 1);
    return SumEvenT<T>(a, size, i + 1);
}
