#include <iostream>
#include <iomanip>
#include "student.h"

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << "  прізвище: ";
        cin >> p[i].prizv;
        cout << "  курс: ";
        cin >> p[i].kurs;
        cout << "  спеціальність (0 - KN, 1 - INF, 2 - ME, 3 - FI, 4 - TN): ";
        cin >> spec;
        p[i].spec = (Spec)spec;
        cout << "  фізика: ";
        cin >> p[i].fizyka;
        cout << "  математика: ";
        cin >> p[i].matematyka;
        switch (p[i].spec)
        {
        case KN:
            cout << "  програмування: ";
            cin >> p[i].prohramuvannia;
            break;
        case INF:
            cout << "  чисельні методи: ";
            cin >> p[i].chyselni_metody;
            break;
        default:
            cout << "  педагогіка: ";
            cin >> p[i].pedahohika;
            break;
        }
    }
}

void Print(Student* p, const int N)
{
    string specStr[] = { "KN", "INF", "ME", "FI", "TN" };
    cout << "Список студентів" << endl;
    cout << string(67, '=') << endl;
    cout << "| No | Surname    | Kurs | Spec "
         << "| Phys | Math | Prog | NumM | Ped |" << endl;
    cout << string(67, '-') << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << i + 1
             << " | " << setw(10) << left << p[i].prizv << right
             << " | " << setw(4) << p[i].kurs
             << " | " << setw(4) << specStr[p[i].spec]
             << " | " << setw(4) << p[i].fizyka
             << " | " << setw(4) << p[i].matematyka << " | ";
        switch (p[i].spec)
        {
        case KN:
            cout << setw(4) << p[i].prohramuvannia << " |      |     |";
            break;
        case INF:
            cout << "     | " << setw(4) << p[i].chyselni_metody
                 << " |     |";
            break;
        default:
            cout << "     |      | " << setw(3) << p[i].pedahohika << " |";
            break;
        }
        cout << endl;
    }
    cout << string(67, '=') << endl;
}

int ThirdMark(Student s)
{
    switch (s.spec)
    {
    case KN:
        return s.prohramuvannia;
    case INF:
        return s.chyselni_metody;
    default:
        return s.pedahohika;
    }
}

bool IsExcellent(Student s)
{
    return s.fizyka == 5 && s.matematyka == 5 && ThirdMark(s) == 5;
}

double PercentExcellent(Student* p, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (IsExcellent(p[i]))
            k++;
    return 100.0 * k / N;
}

void PrintPhysicsFive(Student* p, const int N)
{
    cout << "Студенти з оцінкою 5 з фізики:" << endl;
    for (int i = 0; i < N; i++)
        if (p[i].fizyka == 5)
            cout << "  " << p[i].prizv << endl;
}
