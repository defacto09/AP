#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double alpha; // вхідний параметр (кут у радіанах)
    double z1;    // результат обчислення 1-го виразу
    double z2;    // результат обчислення 2-го виразу

    cout << "alpha = "; cin >> alpha;

    z1 = cos(3 * M_PI / 8 - alpha / 4) * cos(3 * M_PI / 8 - alpha / 4)
       - cos(11 * M_PI / 8 + alpha / 4) * cos(11 * M_PI / 8 + alpha / 4);
    z2 = sqrt(2.) / 2 * sin(alpha / 2);

    cout << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    return 0;
}
