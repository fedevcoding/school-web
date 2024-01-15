#include <iostream>

using namespace std;

int main(void)
{
    int prezzo, sconto = 0;

    cout << "Inserisci un prezzo per saperne il prezzo scontato\n";
    cin >> prezzo;

    if (prezzo < 100)
        sconto = 2;
    if (prezzo >= 100 && prezzo < 1000)
        sconto = 5;
    if (prezzo >= 1000)
        sconto = 7;

    double prezzoScontato = prezzo - ((double)prezzo / 100 * sconto);
    cout << "Lo sconto e' del " << sconto << "%\n";
    cout << "Il prezzo scontato e' " << prezzoScontato << " euro\n";

    return 0;
}