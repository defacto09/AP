// Lab_06_4_rec.cpp
// Опрацювання та впорядкування одновимірних динамічних масивів
// (рекурсивний спосіб)
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void Create(double* p, const int n, const double Low, const double High, int i);
void Print(double* p, const int n, int i);
double Max(double* p, const int n, int i, double max);
int LastPositive(double* p, int i);
double SumBefore(double* p, const int last, int i);
void Compress(double* p, const int n, const double a, const double b, int i, int k);
void FillZeros(double* p, const int n, int k);

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
    Create(p, n, -10, 10, 0);
    Print(p, n, 0);

    cout << "max = " << Max(p, n, 1, p[0]) << endl;
    int last = LastPositive(p, n - 1);
    if (last == -1)
        cout << "there are no positive elements" << endl;
    else
        cout << "sum before last positive = " << SumBefore(p, last, 0) << endl;

    Compress(p, n, a, b, 0, 0);
    Print(p, n, 0);

    delete[] p;                      // знищення динамічного масиву
    return 0;
}
#endif

void Create(double* p, const int n, const double Low, const double High, int i)
{
    p[i] = Low + (High - Low) * rand() / RAND_MAX;
    if (i < n - 1)
        Create(p, n, Low, High, i + 1);
}

void Print(double* p, const int n, int i)
{
    cout << fixed << setprecision(2) << setw(7) << p[i];
    if (i < n - 1)
        Print(p, n, i + 1);
    else
        cout << endl;
}

double Max(double* p, const int n, int i, double max)
{
    if (i == n)                      // усі елементи переглянуто
        return max;
    if (p[i] > max)
        max = p[i];
    return Max(p, n, i + 1, max);
}

// іде з кінця масиву (перший виклик з i = n - 1);
// повертає індекс останнього додатного елемента або -1
int LastPositive(double* p, int i)
{
    if (i < 0)
        return -1;
    if (p[i] > 0)
        return i;
    return LastPositive(p, i - 1);
}

// сума елементів з індексами i .. last-1
double SumBefore(double* p, const int last, int i)
{
    if (i >= last)
        return 0;
    return p[i] + SumBefore(p, last, i + 1);
}

// i – індекс елемента, який перевіряємо; k – куди записати наступний елемент, що залишається
void Compress(double* p, const int n, const double a, const double b, int i, int k)
{
    if (i == n)                      // масив переглянуто – хвіст заповнюємо нулями
    {
        FillZeros(p, n, k);
        return;
    }
    if (!(fabs(p[i]) >= a && fabs(p[i]) <= b))
    {
        p[k] = p[i];
        Compress(p, n, a, b, i + 1, k + 1);
    }
    else
        Compress(p, n, a, b, i + 1, k);
}

void FillZeros(double* p, const int n, int k)
{
    if (k == n)
        return;
    p[k] = 0;
    FillZeros(p, n, k + 1);
}
