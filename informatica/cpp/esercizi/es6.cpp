#include <iostream>

using namespace std;

int main(void)
{

    int num1, num2 = 0;

    cout << "Inserisci due numeri per capire se il primo numero e' multiplo del secondo\n";
    cin >> num1;
    cin >> num2;

    if (num1 % num2 == 0)
        cout << "Il numero " << num1 << " è multiplo del numero " << num2 << endl;
    else
        cout << "Il numero " << num1 << " NON è multiplo del numero " << num2 << endl;

    return 0;
}