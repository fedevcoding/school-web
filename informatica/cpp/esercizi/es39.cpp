#include <iostream>

using namespace std;

bool binarySearch(int arr[], int length, int target);
bool linearSearch(int arr[], int length, int target);
bool inizializzaArray(int ar[], int &ll, int lf, int qtaDaValorizzare);
bool inserimentoOrdinato(int ar[], int &ll, int lf, int valDaInserire);
bool rightShift(int arr[], int ll, int lf, int pos);
int getOrderedPos(int arr[], int ll, int num);
bool binarySearch(int arr[], int length, int target, int &numIterazioni);
bool linearSearch(int arr[], int length, int target, int &numIterazioni);
void stampaArray(int arr[], int ll);
void stampaRisultatiRicerca(int arr[], int ll, int target);

int main(void)
{
    srand(time(NULL));
    const int DIM = 100;
    int arr[DIM], ll = 0, lf = DIM;

    int qtaDaValorizzare = 0;
    cout << "Inserisci quantita da valorizzare\n";
    cin >> qtaDaValorizzare;

    inizializzaArray(arr, ll, DIM, qtaDaValorizzare);
    stampaArray(arr, ll);
    stampaRisultatiRicerca(arr, ll, 23);
}

bool inizializzaArray(int ar[], int &ll, int lf, int qtaDaValorizzare)
{
    if (qtaDaValorizzare > lf)
        return false;

    for (int i = 0; i < qtaDaValorizzare; i++)
    {
        int valRandom = rand() % 30;
        inserimentoOrdinato(ar, ll, lf, valRandom);
    }

    return true;
}

bool inserimentoOrdinato(int ar[], int &ll, int lf, int valDaInserire)
{
    if (ll >= lf)
        return false;

    int pos = getOrderedPos(ar, ll, valDaInserire);
    rightShift(ar, ll, lf, pos);
    ar[pos] = valDaInserire;
    ll++;

    return true;
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

bool binarySearch(int arr[], int length, int target, int &numIterazioni)
{
    int left = 0, right = length;
    int iterazioni = 0;

    while (left <= right)
    {
        iterazioni++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            numIterazioni = iterazioni;
            return true;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}

bool linearSearch(int arr[], int length, int target, int &numIterazioni)
{
    for (int i = 0; i < length; i++)
        if (arr[i] == target)
        {
            numIterazioni = i + 1;
            return true;
        }
    return false;
}

void stampaArray(int arr[], int ll)
{
    cout << "[";
    for (int i = 0; i < ll; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]\n";
}

void stampaRisultatiRicerca(int arr[], int ll, int target)
{
    int iterazioniLineari = 0;
    bool found = linearSearch(arr, ll, target, iterazioniLineari);

    int iterazioniBinary = 0;
    binarySearch(arr, ll, target, iterazioniBinary);

    cout << boolalpha;

    if (found)
    {
        cout << "Il numero e' stato trovato\n";
        cout << "Totale iterazioni lineari: " << iterazioniLineari << "\n";
        cout << "Totale iterazioni binarie: " << iterazioniBinary << "\n";
    }
    else
    {
        cout << "Il numero non e' stato trovato\n";
    }
}