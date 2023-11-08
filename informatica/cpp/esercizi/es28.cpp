#include <iostream>

int quantitaTempoSecondi(int ore, int minuti, int secondi);
bool primaMaggioreDellaSeconda(int oreT1, int minutiT1, int secondiT1, int oreT2, int minutiT2, int secondiT2);

using namespace std;

int main(void)
{

    int oreT1, minutiT1, secondiT1, oreT2, minutiT2, secondiT2;
    cout << "Inserisci 2 tempi in fomato ore, minuti e secondi per sapere quale e' il piu' grande\n";

    cout << "Inserisci le ore del tempo 1\n";
    cin >> oreT1;
    cout << "Inserisci i minuti del tempo 1\n";
    cin >> minutiT1;
    cout << "Inserisci i secondi del tempo 1\n";
    cin >> secondiT1;

    cout << "Inserisci le ore del tempo 2\n";
    cin >> oreT2;
    cout << "Inserisci i minuti del tempo 2\n";
    cin >> minutiT2;
    cout << "Inserisci i secondi del tempo 2\n";
    cin >> secondiT2;

    bool primoMaggiore = primaMaggioreDellaSeconda(oreT1, minutiT1, secondiT1, oreT2, minutiT2, secondiT2);

    if (primoMaggiore)
        cout << "Il primo tempo e' maggiore del secondo\n";
    else
        cout << "Il secondo tempo e' maggiore del primo\n";

    return 0;
}

int quantitaTempoSecondi(int ore, int minuti, int secondi)
{
    int oreASecondi = ore / 3600;

    int minutiASecondi = minuti / 60;

    int secondiTot = secondi + minutiASecondi + oreASecondi;

    return secondiTot;
}

bool primaMaggioreDellaSeconda(int oreT1, int minutiT1, int secondiT1, int oreT2, int minutiT2, int secondiT2)
{
    int tot1 = quantitaTempoSecondi(oreT1, minutiT1, secondiT1);
    int tot2 = quantitaTempoSecondi(oreT2, minutiT2, secondiT2);

    return tot1 > tot2;
}