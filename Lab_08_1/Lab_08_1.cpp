// Лабораторна робота 8.1, варіант 25. Ітераційний спосіб.
// Дано літерний рядок s[0], ..., s[n], ...
// 1. Вияснити, чи є в рядку такі елементи s[i], s[i+1], що s[i] - кома (','),
//    а s[i+1] - тире ('-'), та обчислити їх кількість.
// 2. Замінити кожну групу символів ",-" зірочкою "*".
#include <iostream>
using namespace std;

bool ScanCommaDash(const char* s)
{
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++)
        if (s[i] == ',' && s[i + 1] == '-')
            return true;
    return false;
}

int QtyCommaDash(const char* s)
{
    int q = 0;
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++)
        if (s[i] == ',' && s[i + 1] == '-')
            q++;
    return q;
}

void ReplaceCommaDash(const char* s, char* result)
{
    int i = 0;      // позиція в s
    int j = 0;      // позиція в result
    while (s[i] != '\0')
    {
        if (s[i + 1] != '\0' && s[i] == ',' && s[i + 1] == '-')
        {
            result[j++] = '*';
            i += 2;
        }
        else
        {
            result[j++] = s[i];
            i++;
        }
    }
    result[j] = '\0';
}

#ifndef UNIT_TEST
int main()
{
    char s[101];
    char result[101];
    cout << "Введіть рядок: ";
    cin.getline(s, 101);
    if (ScanCommaDash(s))
        cout << "Пари \",-\" є, їх кількість: " << QtyCommaDash(s) << endl;
    else
        cout << "Пар \",-\" немає" << endl;
    ReplaceCommaDash(s, result);
    cout << "Змінений рядок: " << result << endl;
    return 0;
}
#endif
