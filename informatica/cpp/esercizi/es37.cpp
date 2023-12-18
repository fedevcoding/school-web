#include <iostream>
#define LENGTH 5

using namespace std;

bool append(int arr[], int &ll, int lf, int valDaInserire);
bool removeLast(int arr[], int &ll, int lf);
void printArray(int arr[], int ll);
void printReverse(int arr[], int ll);
void emptyArray(int &ll);
int sum(int arr[], int ll);
float avgArray(int arr[], int ll);
int countEven(int arr[], int ll);
void printArrIndex(int arr[], int ll, int i);
void printOdd(int arr[], int ll);
int maxArray(int arr[], int ll);
int minArray(int arr[], int ll);
int sumArray(int arr[], int ll);

int main(void)
{

    int arr[LENGTH];
    int ll = 0;
    int lf = LENGTH;

    while (true)
    {

        int num;

        cout << "######### MENU #########\n";
        cout << "0) PER USCIRE\n";
        cout << "1) PER AGGIUNGERE UN NUMERO ALL array\n";
        cout << "2) PER RIMUOVERE LULTIMO ELEMENTO DALL ARRAY\n";
        cout << "3) PER STAMPARE LARRAY\n";
        cout << "4) PER STAMPARE LARRAY AL CONTRARIO\n";
        cout << "5) PER SVUOTARE LARRAY\n";
        cout << "6) PER VISUALIZZARE LA SOMMA DEI NUMERI NELLARRAY\n";
        cout << "7) PER VISUALIZZARE LA MEDIA DEI NUMERI NELLARRAY\n";
        cout << "8) PER VISUALIZZARE LA QUANTITA DI NUMERI PARI NELLARRAY\n";
        cout << "9) PER VISUALIZZARE IL NUMERO PIU GRANDE NELLARRAY\n";
        cout << "10) PER VISUALIZZARE IL NUMERO PIU PICCOLO NELLARRAY\n";
        cout << "11) PER VISUALIZZARE UN determinato elemento dell’array\n";
        cout << "12) PER VISUALIZZARE solo gli elementi in posizione dispari\n";

        cin >> num;
        if (num == 0)
            break;

        switch (num)
        {
        case 1:
        {
            int num;
            cout << "Inserisci il numero\n";
            cin >> num;
            bool success = append(arr, ll, lf, num);
            if (success)
                cout << "Numero aggiunto\n";
            else
                cout << "Array pieno\n";
            break;
        }
        case 2:
        {
            bool success = removeLast(arr, ll, lf);
            if (success)
                cout << "Numero rimosso\n";
            else
                cout << "Array vuoto\n";
            break;
        }
        case 3:
        {
            printArray(arr, ll);
            break;
        }
        case 4:
        {
            printReverse(arr, ll);
            break;
        }
        case 5:
        {
            emptyArray(ll);
            break;
        }
        case 6:
        {
            cout << "La somma dei numeri e': " << sumArray(arr, ll) << endl;
        }
        case 7:
        {
            cout << "La media dei numeri e': " << avgArray(arr, ll) << endl;
        }
        case 8:
        {
            cout << "I numeri pari sono: " << countEven(arr, ll) << endl;
        }
        case 9:
        {
            cout << "Il numero piu' grande e': " << maxArray(arr, ll) << endl;
        }
        case 10:
        {
            cout << "Il numero piu' piccolo e': " << minArray(arr, ll) << endl;
        }
        case 11:
        {
            int i;
            cout << "Inserisci la posizione dellarray da stampare\n";
            cin >> i;
            printArrIndex(arr, ll, i);
        }
        case 12:
        {
            printOdd(arr, ll);
        }
        default:
        {
            cout << "Valore non valido\n";
        }
        }
    }
    return 0;
}

void printArrIndex(int arr[], int ll, int i)
{
    if (i > ll)
        cout << "Posizione invalida\n";

    cout << arr[i];
}

void printOdd(int arr[], int ll)
{
    if (ll == 0)
    {
        cout << "Array vuoto\n";
        return;
    }

    cout << "[ ";
    for (int i = 0; i < ll; i++)
        if (arr[i] % 2 == 1)
            cout << arr[i] << ", ";
    cout << " ]\n";
}

int maxArray(int arr[], int ll)
{
    if (ll == 0)
        return 0;
    int max = arr[0];
    for (int i = 1; i < ll; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int minArray(int arr[], int ll)
{
    if (ll == 0)
        return 0;
    int min = arr[0];
    for (int i = 1; i < ll; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
int countEven(int arr[], int ll)
{
    int sum = 0;
    for (int i = 0; i < ll; i++)
        if (arr[i] % 2 == 0)
            sum++;
    return sum;
}

float avgArray(int arr[], int ll)
{
    return sumArray(arr, ll) / ll;
}

int sumArray(int arr[], int ll)
{
    int sum = 0;
    for (int i = 0; i < ll; i++)
        sum += arr[i];
    return sum;
}

bool append(int arr[], int &ll, int lf, int valDaInserire)
{
    if (ll >= lf)
        return false;
    arr[ll] = valDaInserire;
    ll++;
    return true;
}

bool removeLast(int arr[], int &ll, int lf)
{
    if (ll <= 0)
        return false;
    ll--;
    return true;
}

void printArray(int arr[], int ll)
{
    if (ll == 0)
    {
        cout << "Array vuoto\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < ll; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void printReverse(int arr[], int ll)
{
    if (ll == 0)
    {
        cout << "Array vuoto\n";
        return;
    }
    cout << "[";
    for (int i = ll - 1; i >= 0; i--)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void emptyArray(int &ll)
{
    ll = 0;
}