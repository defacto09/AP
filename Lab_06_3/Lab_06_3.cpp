#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int SumEven(int* a, const int size);
int QuantityEven(int* a, const int size);

template <typename T>
void CreateT(T* a, const int size, const T Low, const T High);
template <typename T>
void PrintT(T* a, const int size);
template <typename T>
T SumEvenT(T* a, const int size);
template <typename T>
int QuantityEvenT(T* a, const int size);

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));     // ініціалізація генератора випадкових чисел
    const int n = 10;
    int a[n];
    Create(a, n, -20, 20);
    Print(a, n);

    cout << "SumEven(a, n)            = " << SumEven(a, n) << endl;             // звичайна функція
    cout << "SumEvenT<int>(a, n)      = " << SumEvenT<int>(a, n) << endl;       // шаблон, T = int
    cout << "QuantityEven(a, n)       = " << QuantityEven(a, n) << endl;
    cout << "QuantityEvenT<int>(a, n) = " << QuantityEvenT<int>(a, n) << endl;

    long long b[n];                                                         // ті самі шаблони для іншого типу
    CreateT<long long>(b, n, -20, 20);
    PrintT<long long>(b, n);
    cout << "SumEvenT<long long>(b, n)      = " << SumEvenT<long long>(b, n) << endl;
    cout << "QuantityEvenT<long long>(b, n) = " << QuantityEvenT<long long>(b, n) << endl;
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

int QuantityEven(int* a, const int size)
{
    int c = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0)
            c += 1;
    return c;
}

template <typename T>
void CreateT(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void PrintT(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
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

template <typename T>
int QuantityEvenT(T* a, const int size)
{
    int c = 0;                       // кількість завжди ціла, тому int, а не T
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0)
            c += 1;
    return c;
}