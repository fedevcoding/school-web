#include <iostream>

using namespace std;

int multiply(int a, int b);
int divide(int a, int b);
int power(int a, int b);

int main(void)
{

    while (true)
    {

        int decisione;

        cout << "##################### MENU' #####################\n";
        cout << "##################### DIGITA -1 PER USCIRE #####################\n";
        cout << "##################### DIGITA 1 per moltiplicare 2 numeri #####################\n";
        cout << "##################### DIGITA 2 per dividere 2 numeri #####################\n";
        cout << "##################### DIGITA 3 per fare esguire la potenza tra 2 numeri #####################\n";

        cin >> decisione;

        if (decisione == -1)
            break;

        int a, b = 0;
        cout << "Inserisci a e b\n";
        cin >> a;
        cin >> b;

        switch (decisione)
        {
        case 1:
        {
            cout << "Il risultato della moltiplicazione tra a e b e': " << multiply(a, b) << endl;
            break;
        }
        case 2:
        {
            cout << "Il risultato della divisione tra a e b e': " << divide(a, b) << endl;
            break;
        }
        case 3:
        {
            cout << "Il risultato della potenza tra a e b e': " << power(a, b) << endl;
            break;
        }
        default:
            cout << "Scelta non valida\n";
            break;
        }
    }

    cout << "Bye bye :)\n";

    return 0;
}

int multiply(int a, int b)
{
    int res = 0;

    for (int i = 0; i < b; i++)
    {
        res += a;
    }

    return res;
}

int divide(int a, int b)
{
    int res = 0;

    while (a >= b)
    {
        a -= b;
        res++;
    }

    return res;
}

int power(int a, int b)
{
    int res = 1;

    for (int i = 0; i < b; i++)
    {
        res *= a;
    }

    return res;
}