// Lab_06_4.cpp
// Опрацювання та впорядкування одновимірних динамічних масивів
// (ітераційний спосіб)
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void Create(double* p, const int n, const double Low, const double High);
void Print(double* p, const int n);
double Max(double* p, const int n);
int LastPositive(double* p, const int n);
double SumBefore(double* p, const int last);
void Compress(double* p, const int n, const double a, const double b);

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL));     // ініціалізація генератора випадкових чисел
    int n;
    double a, b;
    cout << "n = "; cin >> n;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    if (n <= 0)
    {
        cout << "n must be > 0" << endl;
        return 1;
    }

    double* p = new double[n];       // створення динамічного масиву
    Create(p, n, -10, 10);
    Print(p, n);

    cout << "max = " << Max(p, n) << endl;
    int last = LastPositive(p, n);
    if (last == -1)
        cout << "there are no positive elements" << endl;
    else
        cout << "sum before last positive = " << SumBefore(p, last) << endl;

    Compress(p, n, a, b);
    Print(p, n);

    delete[] p;                      // знищення динамічного масиву
    return 0;
}
#endif

// заповнює масив випадковими дійсними числами з [Low; High]
void Create(double* p, const int n, const double Low, const double High)
{
    for (int i = 0; i < n; i++)
        p[i] = Low + (High - Low) * rand() / RAND_MAX;
}

void Print(double* p, const int n)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
        cout << setw(7) << p[i];
    cout << endl;
}

double Max(double* p, const int n)
{
    double max = p[0];
    for (int i = 1; i < n; i++)
        if (p[i] > max)
            max = p[i];
    return max;
}

// повертає індекс останнього додатного елемента або -1, якщо таких немає
int LastPositive(double* p, const int n)
{
    for (int i = n - 1; i >= 0; i--)
        if (p[i] > 0)
            return i;
    return -1;
}

// сума елементів з індексами 0 .. last-1
double SumBefore(double* p, const int last)
{
    double s = 0;
    for (int i = 0; i < last; i++)
        s += p[i];
    return s;
}

// видаляє елементи, модуль яких лежить в [a; b], зберігаючи порядок решти;
// місця, що звільнилися в кінці, заповнює нулями
void Compress(double* p, const int n, const double a, const double b)
{
    int k = 0;                       // куди записати наступний елемент, що залишається
    for (int i = 0; i < n; i++)
        if (!(fabs(p[i]) >= a && fabs(p[i]) <= b))
            p[k++] = p[i];
    for (int i = k; i < n; i++)
        p[i] = 0;
}
