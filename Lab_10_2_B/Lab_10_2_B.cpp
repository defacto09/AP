#include <iostream>
#include "student.h"

int main()
{
    int N = ReadInt("Кількість студентів N = ", 1, 100);
    Student* p = new Student[N];
    Create(p, N);

    bool sorted = false;
    int menuItem, spec, mat, found;
    int* I;
    string prizv;
    do
    {
        cout << endl << "Виберіть дію:" << endl;
        cout << " [1] - вивід даних на екран" << endl;
        cout << " [2] - фізичне впорядкування" << endl;
        cout << " [3] - індексне впорядкування" << endl;
        cout << " [4] - бінарний пошук студента" << endl;
        cout << " [0] - вихід" << endl;
        menuItem = ReadInt("Введіть значення: ", 0, 4);
        cout << endl;

        switch (menuItem)
        {
        case 1:
            Print(p, N);
            break;
        case 2:
            Sort(p, N);
            sorted = true;
            Print(p, N);
            break;
        case 3:
            I = IndexSort(p, N);
            PrintIndexSorted(p, I, N);
            delete[] I;
            break;
        case 4:
            if (!sorted)
                cout << "Спочатку впорядкуйте масив (пункт 2)" << endl;
            else
            {
                cout << "  прізвище: ";
                cin >> prizv;
                spec = ReadInt("  спеціальність (0 - KN, 1 - INF, "
                               "2 - ME, 3 - FI, 4 - TN): ", 0, 4);
                mat = ReadInt("  оцінка з математики: ", 1, 5);
                found = BinSearch(p, N, prizv, (Spec)spec, mat);
                if (found != -1)
                    cout << "Студента знайдено, позиція " << found + 1
                         << endl;
                else
                    cout << "Такого студента немає" << endl;
            }
            break;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}
