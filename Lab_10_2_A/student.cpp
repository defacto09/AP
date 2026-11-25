#include <iostream>
#include <iomanip>
#include <utility>
#include "student.h"

int ReadInt(const string prompt, const int min, const int max)
{
    int x;
    cout << prompt;
    while (!(cin >> x) || x < min || x > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Помилка! Введіть число від " << min << " до " << max
             << ": ";
    }
    return x;
}

void Create(Student* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << "  прізвище: ";
        cin >> p[i].prizv;
        p[i].kurs = ReadInt("  курс: ", 1, 6);
        p[i].spec = (Spec)ReadInt("  спеціальність (0 - KN, 1 - INF, "
                                  "2 - ME, 3 - FI, 4 - TN): ", 0, 4);
        p[i].fizyka = ReadInt("  фізика: ", 1, 5);
        p[i].matematyka = ReadInt("  математика: ", 1, 5);
        p[i].informatyka = ReadInt("  інформатика: ", 1, 5);
    }
}

void PrintHeader()
{
    cout << string(54, '=') << endl;
    cout << "| No | Surname    | Kurs | Spec "
         << "| Phys | Math | Inf  |" << endl;
    cout << string(54, '-') << endl;
}

void PrintRow(Student s, const int no)
{
    string specStr[] = { "KN", "INF", "ME", "FI", "TN" };
    cout << "| " << setw(2) << no
         << " | " << setw(10) << left << s.prizv << right
         << " | " << setw(4) << s.kurs
         << " | " << setw(4) << specStr[s.spec]
         << " | " << setw(4) << s.fizyka
         << " | " << setw(4) << s.matematyka
         << " | " << setw(4) << s.informatyka << " |" << endl;
}

void Print(Student* p, const int N)
{
    cout << "Список студентів" << endl;
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(p[i], i + 1);
    cout << string(54, '=') << endl;
}

bool Less(Student a, Student b)
{
    if (a.spec != b.spec)
        return a.spec < b.spec;
    if (a.matematyka != b.matematyka)
        return a.matematyka < b.matematyka;
    return a.prizv < b.prizv;
}

void Sort(Student* p, const int N)
{
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (Less(p[i1 + 1], p[i1]))
                swap(p[i1], p[i1 + 1]);
}

int* IndexSort(Student* p, const int N)
{
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;
    for (int i = 1; i < N; i++)
    {
        int value = I[i];
        int j = i - 1;
        while (j >= 0 && Less(p[value], p[I[j]]))
        {
            I[j + 1] = I[j];
            j--;
        }
        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{
    cout << "Список студентів (індексне впорядкування)" << endl;
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(p[I[i]], i + 1);
    cout << string(54, '=') << endl;
}

int BinSearch(Student* p, const int N, const string prizv,
              const Spec spec, const int matematyka)
{
    Student key;
    key.prizv = prizv;
    key.spec = spec;
    key.matematyka = matematyka;
    int L = 0, R = N - 1, m;
    while (L <= R)
    {
        m = (L + R) / 2;
        if (p[m].prizv == prizv && p[m].spec == spec &&
            p[m].matematyka == matematyka)
            return m;
        if (Less(p[m], key))
            L = m + 1;
        else
            R = m - 1;
    }
    return -1;
}
