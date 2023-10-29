#include <iostream>

using namespace std;

int main(void)
{

    int num1, num2, num3, tot = 0;

    cout << "Questo programma calcola la somma e la media di 3 numeri. Inserisci i 3 numeri." << endl;
    cin >> num1;
    cin >> num2;
    cin >> num3;

    tot = num1 + num2 + num3;

    float avg = (tot) / 3.0;

    cout << "La somma dei 3 numeri e'" << tot << " e la media e' " << avg << endl;

    return 0;
}