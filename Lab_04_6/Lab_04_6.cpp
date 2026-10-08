// Lab_04_6.cpp
// Саламаха Роман, РІ-12
// Лабораторна робота № 4.6 «Вкладені цикли»
// Варіант 25

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int i_max = 15;
    int i, k;
    double p, s;          // p - внутрішній добуток, s - сума

    cout << setprecision(16);

    // спосіб 1: while { while }
    s = 0;
    i = 1;
    while (i <= i_max)
    {
        p = 1;
        k = 1;
        while (k <= i)
        {
            p *= k * k + 1;
            k++;
        }
        s += p / (1 + p * p);
        i++;
    }
    cout << "Result 1: " << s << endl;

    // спосіб 2: do { do ... while } while
    s = 0;
    i = 1;
    do
    {
        p = 1;
        k = 1;
        do
        {
            p *= k * k + 1;
            k++;
        } while (k <= i);
        s += p / (1 + p * p);
        i++;
    } while (i <= i_max);
    cout << "Result 2: " << s << endl;

    // спосіб 3: for (n++) { for (k++) }
    s = 0;
    for (i = 1; i <= i_max; i++)
    {
        p = 1;
        for (k = 1; k <= i; k++)
            p *= k * k + 1;
        s += p / (1 + p * p);
    }
    cout << "Result 3: " << s << endl;

    // спосіб 4: for (n--) { for (k--) }
    s = 0;
    for (i = i_max; i >= 1; i--)
    {
        p = 1;
        for (k = i; k >= 1; k--)
            p *= k * k + 1;
        s += p / (1 + p * p);
    }
    cout << "Result 4: " << s << endl;

    return 0;
}
