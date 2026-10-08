// Lab_04_1.cpp
// Саламаха Роман, РІ-12
// Лабораторна робота № 4.1 «Цикли»
// Варіант 25

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int N, k;
    const int k_max = 19;
    double p;

    cout << "N = "; cin >> N;
    cout << fixed << setprecision(5);

    // спосіб 1: while
    p = 1;
    k = N;
    while (k <= k_max)
    {
        p *= 1. * (k - N) / (k + N) + 1;
        k++;
    }
    cout << "Result 1: " << p << endl;

    // спосіб 2: do ... while
    p = 1;
    k = N;
    do
    {
        p *= 1. * (k - N) / (k + N) + 1;
        k++;
    } while (k <= k_max);
    cout << "Result 2: " << p << endl;

    // спосіб 3: for з наростанням параметра
    p = 1;
    for (k = N; k <= k_max; k++)
        p *= 1. * (k - N) / (k + N) + 1;
    cout << "Result 3: " << p << endl;

    // спосіб 4: for зі спаданням параметра
    p = 1;
    for (k = k_max; k >= N; k--)
        p *= 1. * (k - N) / (k + N) + 1;
    cout << "Result 4: " << p << endl;

    return 0;
}
