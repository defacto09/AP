#include <iostream>
#include "student.h"

int main()
{
    int N;
    cout << "Кількість студентів N = ";
    cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);

    cout << "Процент студентів, які вчаться на відмінно: "
         << PercentExcellent(p, N) << "%" << endl;
    PrintPhysicsFive(p, N);

    delete[] p;
    return 0;
}
