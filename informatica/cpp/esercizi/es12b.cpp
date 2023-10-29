#include <iostream>

using namespace std;

int main()
{
    int scontoUno, scontoDue, costoLitro, bottiglie, bottiglieTotali, nOrdini, i, scontoApplicato;
    double prezzoScontato, prezzoTotale;

    prezzoTotale = 0;
    bottiglieTotali = 0;
    cout << "Inserisci il costo al litro" << endl;
    cin >> costoLitro;
    cout << "Inserisci lo sconto per ordini da 20 a 39 bottiglie" << endl;
    cin >> scontoUno;
    cout << "Inserisci lo sconto per ordini superiori a 40 bottiglie" << endl;
    cin >> scontoDue;
    if (scontoUno < 0 || scontoDue < 0 || (scontoUno > 100 || scontoDue > 100))
    {
        cout << "Lo sconto deve essere compreso tra 0 e 100" << endl;
    }
    else
    {
        if (scontoUno > scontoDue)
        {
            cout << "Lo sconto uno deve essere minore dello sconto due" << endl;
        }
        else
        {
            cout << "Inserisci il numbero di ordini" << endl;
            cin >> nOrdini;
            for (i = 0; i <= nOrdini - 1; i++)
            {
                cout << "Inserisci le bottiglie da ordinare" << endl;
                cin >> bottiglie;
                if (bottiglie < 20)
                {
                    scontoApplicato = 0;
                }
                else
                {
                    if (bottiglie >= 40)
                    {
                        scontoApplicato = scontoDue;
                    }
                    else
                    {
                        scontoApplicato = scontoUno;
                    }
                }
                prezzoScontato = 5 * costoLitro * bottiglie - (double)(5 * costoLitro * bottiglie) / 100 * scontoApplicato;
                prezzoTotale = prezzoTotale + prezzoScontato;
                bottiglieTotali = bottiglieTotali + bottiglie;
            }
        }
        cout << "Sono state vendute  " << bottiglieTotali << " bottiglie per un valore di " << prezzoTotale << " euro" << endl;
    }
    return 0;
}
