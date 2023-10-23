#include <iostream>

using namespace std;

int main(void)
{

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout << "Inserisci 3 numeri interi per sapere quale e' il piu' grande\n";
    cin >> num1;
    cin >> num2;
    cin >> num3;

    int max = std::max(num1, std::max(num2, num3));

    // if(num1 < num2) {
    //     if(num2 < num3) max = num3;
    //     else max = num2;
    // }
    // else{
    //     if(num1 < num3) max = num3;
    //     else max = num1;
    // }

    cout << "Il numero piu' grande e' " << max;
    return 0;
}