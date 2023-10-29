#include <iostream>

using namespace std;

int main(void)
{

    int num1, num2, num3 = 0;

    cout << "Inserisci 3 numeri interi per sapere quale e' il piu' grande\n";
    cin >> num1;
    cin >> num2;
    cin >> num3;

    int max = std::max(num1, std::max(num2, num3));

    cout << "Il numero piu' grande e' " << max;
    return 0;
}