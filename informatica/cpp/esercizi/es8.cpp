#include <iostream>

using namespace std;

int main(void)
{

    float nums = 5.0;

    int num1, num2, num3, num4, num5 = 0;

    cout << "Inserisci 5 numeri per sapere se la media e' sufficente o da recuperare\n";
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;
    cin >> num5;

    int tot = num1 + num2 + num3 + num4 + num5;
    int media = tot / nums;

    if (media >= 6)
        cout << "Materia suffieciente\n";
    else
        cout << "Materia da recuperare\n";

    return 0;
}