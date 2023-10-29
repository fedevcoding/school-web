#include <iostream>

using namespace std;

int main(void)
{

    int base, altezza = 0;

    cout << "Inserisci la base e altezza di un quadrilatero per saperne l'area e il perimetro\n";
    cin >> base;
    cin >> altezza;

    bool quadrato = false;

    int perimetro = (base * 2) + (altezza * 2);
    int area = base * altezza;

    cout << "L'area e' " << area << " e il perimetro e' " << perimetro << endl;

    if (base == altezza)
        cout << "E' un quadrato\n";
    else
        cout << "Non è un quadrato\n";

    return 0;
}