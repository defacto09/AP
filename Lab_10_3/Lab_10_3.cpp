#include <iostream>
#include "train.h"

int main()
{
    int N = ReadInt("Кількість електричок N (0 - зчитати з файлу) = ",
                    0, 100);
    Train* p = new Train[N];
    Create(p, N);

    int menuItem, k, hour, minute;
    Train t;
    string filename;
    do
    {
        cout << endl << "Виберіть дію:" << endl;
        cout << " [1] - вивід розкладу на екран" << endl;
        cout << " [2] - додати електричку" << endl;
        cout << " [3] - вилучити електричку" << endl;
        cout << " [4] - редагувати електричку" << endl;
        cout << " [5] - сортувати за станцією призначення" << endl;
        cout << " [6] - сортувати за часом відправлення" << endl;
        cout << " [7] - електрички після вказаного часу" << endl;
        cout << " [8] - запис у файл" << endl;
        cout << " [9] - зчитування з файлу" << endl;
        cout << " [0] - вихід" << endl;
        menuItem = ReadInt("Введіть значення: ", 0, 9);
        cout << endl;

        switch (menuItem)
        {
        case 1:
            Print(p, N);
            break;
        case 2:
            ReadTrain(t);
            Add(p, N, t);
            break;
        case 3:
            if (N == 0)
                cout << "Розклад порожній" << endl;
            else
            {
                k = ReadInt("  номер електрички: ", 1, N);
                Remove(p, N, k - 1);
            }
            break;
        case 4:
            if (N == 0)
                cout << "Розклад порожній" << endl;
            else
            {
                k = ReadInt("  номер електрички: ", 1, N);
                ReadTrain(p[k - 1]);
            }
            break;
        case 5:
            SortByPunkt(p, N);
            Print(p, N);
            break;
        case 6:
            SortByTime(p, N);
            Print(p, N);
            break;
        case 7:
            hour = ReadInt("  година: ", 0, 23);
            minute = ReadInt("  хвилини: ", 0, 59);
            PrintAfter(p, N, hour, minute);
            break;
        case 8:
            cout << "  ім'я файлу: ";
            cin >> filename;
            if (SaveToFile(p, N, filename))
                cout << "Розклад записано у файл" << endl;
            else
                cout << "Не вдалося відкрити файл" << endl;
            break;
        case 9:
            cout << "  ім'я файлу: ";
            cin >> filename;
            if (LoadFromFile(p, N, filename))
                cout << "Розклад зчитано з файлу" << endl;
            else
                cout << "Не вдалося відкрити файл" << endl;
            break;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}
