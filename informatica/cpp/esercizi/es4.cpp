#include <iostream>

using namespace std;

int main(void)
{

    int num = 0;

    cout << "Scrivi un numero intero per sapere se è positivo o negativo (o neutro)\n";
    cin >> num;

    if (num >= 0)
    {
        if (num == 0)
            cout << "Il numero " << num << " è zero\n";
        else
            cout << "Il numero " << num << " è positivo\n";
    }
    else
        cout << "Il numero " << num << " è negativo\n";

    return 0;
}