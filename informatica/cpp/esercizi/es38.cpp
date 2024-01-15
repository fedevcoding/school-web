#include <iostream>

using namespace std;

int getOrderedPos(int arr[], int ll, int num);
bool rightShift(int arr[], int ll, int lf, int pos);
void visualizza(int occupati[], int ll);
bool inserisci(int occupati[], int &ll, int lf, int nuovo);
bool leftShift(int arr[], int ll, int pos);
bool ricerca(int occupati[], int ll, int numero, int &posizione);
bool rimuovi(int occupati[], int &ll, int numero);
int armadiettiPari(int occupati[], int ll);
int liberi(int ll, int lf);

int main(void)
{
    const int MAX = 30;
    int occupati[MAX], ll = 5, lf = MAX;
    occupati[0] = 1;
    occupati[1] = 2;
    occupati[2] = 5;
    occupati[3] = 7;
    occupati[4] = 8;

    while (true)
    {
        cout << "MENU\n";
        cout << "1) Inserisci un numero di armadietto\n";
        cout << "2) Per trovare la posizione di un armadietto\n";
        cout << "3) Per rimuovere un'armadietto\n";
        cout << "4) Per visualizzare gli armadietti occupati\n";
        cout << "5) Per visualizzare la quantita' di armadietti liberi\n";
        cout << "6) Per visualizzare la quantita' di armatieddi pari occupati\n";

        int scelta;
        cin >> scelta;
        switch (scelta)
        {
        case 1:
        {
            int num;
            cout << "Inserisci il valore da aggiungere\n";
            cin >> num;
            inserisci(occupati, ll, lf, num);
            break;
        }
        case 2:
        {
            int num, pos;
            cout << "Inserisci l'armadietto da cercare\n";
            cin >> num;
            bool found = ricerca(occupati, ll, num, pos);
            if (found)
            {
                cout << "L'armadietto numero " << num << " si trova in posizione " << pos << endl;
            }
            else
            {
                cout << "L'armadietto non e' occupato\n";
            }
            break;
        }
        case 3:
        {
            int num;
            cout << "Inserisci l'armadietto da rimuovere\n";
            cin >> num;
            bool removed = rimuovi(occupati, ll, num);
            if (removed)
            {
                cout << "Armadietto " << num << " restituito\n";
            }
            else
                cout << "L'armadietto " << num << " non e' occupato\n";
            break;
        }
        case 4:
        {
            visualizza(occupati, ll);
            break;
        }
        case 5:
        {
            int armLiberi = liberi(ll, lf);
            cout << "Ci sono " << armLiberi << " armadietti liberi\n";
            break;
        }
        case 6:
        {
            int pariOccupati = armadiettiPari(occupati, ll);
            cout << "Ci sono " << pariOccupati << " armadietti pari occupati\n";
            break;
        }

        default:
            break;
        }
    }

    return 0;
}

bool inserisci(int occupati[], int &ll, int lf, int nuovo)
{
    int pos = getOrderedPos(occupati, ll, nuovo);
    rightShift(occupati, ll, lf, pos);
    occupati[pos] = nuovo;
    ll++;

    return true;
}

int getOrderedPos(int arr[], int ll, int num)
{
    if (ll == 0)
        return 0;

    for (int i = 0; i < ll; i++)
    {
        if (arr[i] >= num)
        {
            return i;
        }
    }

    return ll;
}

// ricerca del numero usando binary search (visto che larray e' ordinato)
// O(log n)
bool ricerca(int occupati[], int ll, int numero, int &posizione)
{
    int l = 0, r = ll;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (occupati[mid] == numero)
        {
            posizione = mid;
            return true;
        }

        if (occupati[mid] < numero)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return false;
}

bool rightShift(int arr[], int ll, int lf, int pos)
{
    if (ll == 0)
        return true;
    if (ll >= lf)
        return false;

    for (int i = ll; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    return true;
}

bool rimuovi(int occupati[], int &ll, int numero)
{
    int pos;
    bool found = ricerca(occupati, ll, numero, pos);
    if (!found)
        return false;

    leftShift(occupati, ll, pos);

    ll--;
    return true;
}

bool leftShift(int arr[], int ll, int pos)
{
    if (ll == 0)
        return true;
    for (int i = pos; i <= ll; i++)
    {
        arr[i] = arr[i + 1];
    }

    return true;
}

void visualizza(int occupati[], int ll)
{
    if (ll == 0)
    {
        cout << "Non ci sono armadietti occupati\n";
        return;
    }

    cout << "[";
    for (int i = 0; i < ll; i++)
    {
        cout << occupati[i] << ", ";
    }
    cout << "]\n";
}

int liberi(int ll, int lf)
{
    return lf - ll;
}

int armadiettiPari(int occupati[], int ll)
{
    int sum = 0;
    for (int i = 0; i < ll; i++)
    {
        if (occupati[i] % 2 == 0)
            sum++;
    }

    return sum;
}
