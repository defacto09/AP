#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include "train.h"

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

void ReadTrain(Train& t)
{
    cout << "  пункт призначення: ";
    cin >> t.punkt;
    t.type = (TrainType)ReadInt("  тип (0 - звичайний, 1 - комфорт, "
                                "2 - експрес): ", 0, 2);
    t.hour = ReadInt("  година відправлення: ", 0, 23);
    t.minute = ReadInt("  хвилини: ", 0, 59);
}

void Create(Train* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Електричка № " << i + 1 << ":" << endl;
        ReadTrain(p[i]);
    }
}

void PrintHeader()
{
    cout << string(40, '=') << endl;
    cout << "| No | Destination  | Type     | Time  |" << endl;
    cout << string(40, '-') << endl;
}

void PrintRow(Train t, const int no)
{
    string typeStr[] = { "ordinary", "comfort", "express" };
    cout << "| " << setw(2) << no
         << " | " << setw(12) << left << t.punkt
         << " | " << setw(8) << typeStr[t.type] << right
         << " | " << setfill('0') << setw(2) << t.hour << ":"
         << setw(2) << t.minute << setfill(' ') << " |" << endl;
}

void Print(Train* p, const int N)
{
    cout << "Розклад електричок" << endl;
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(p[i], i + 1);
    cout << string(40, '=') << endl;
}

void Add(Train*& p, int& N, const Train t)
{
    Train* q = new Train[N + 1];
    for (int i = 0; i < N; i++)
        q[i] = p[i];
    q[N] = t;
    delete[] p;
    p = q;
    N++;
}

void Remove(Train*& p, int& N, const int k)
{
    Train* q = new Train[N - 1];
    int j = 0;
    for (int i = 0; i < N; i++)
        if (i != k)
        {
            q[j] = p[i];
            j++;
        }
    delete[] p;
    p = q;
    N--;
}

int Minutes(Train t)
{
    return t.hour * 60 + t.minute;
}

void SortByPunkt(Train* p, const int N)
{
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (p[i1].punkt > p[i1 + 1].punkt)
                swap(p[i1], p[i1 + 1]);
}

void SortByTime(Train* p, const int N)
{
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (Minutes(p[i1]) > Minutes(p[i1 + 1]))
                swap(p[i1], p[i1 + 1]);
}

void PrintAfter(Train* p, const int N, const int hour, const int minute)
{
    cout << "Електрички, що відходять після " << setfill('0') << setw(2)
         << hour << ":" << setw(2) << minute << setfill(' ') << endl;
    PrintHeader();
    for (int i = 0; i < N; i++)
        if (Minutes(p[i]) > hour * 60 + minute)
            PrintRow(p[i], i + 1);
    cout << string(40, '=') << endl;
}

bool SaveToFile(Train* p, const int N, const string filename)
{
    ofstream fout(filename);
    if (!fout)
        return false;
    fout << N << endl;
    for (int i = 0; i < N; i++)
        fout << p[i].punkt << " " << p[i].type << " "
             << p[i].hour << " " << p[i].minute << endl;
    return true;
}

bool LoadFromFile(Train*& p, int& N, const string filename)
{
    ifstream fin(filename);
    if (!fin)
        return false;
    int type;
    delete[] p;
    fin >> N;
    p = new Train[N];
    for (int i = 0; i < N; i++)
    {
        fin >> p[i].punkt >> type >> p[i].hour >> p[i].minute;
        p[i].type = (TrainType)type;
    }
    return true;
}
