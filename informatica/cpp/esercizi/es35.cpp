#include <iostream>
#define LENGTH 10

using namespace std;

bool addNumToIndex(int arr[], int i, int valDaInserire, int length);
bool printArrIndex(int arr[], int i, int length);
void printArray(int arr[], int ll);
bool swapAtIndex(int arr[], int i, int j, int length);
bool copyAtIndex(int arr[], int i, int j, int length);
void inizializzaArray(int arr[], int length);

int main(void)
{
    int arr[LENGTH];

    inizializzaArray(arr, LENGTH);

    while (true)
    {

        int num;

        cout << "######### MENU #########\n";
        cout << "######### INSERISCI -1 PER USCIRE #########\n";
        cout << "######### INSERISCI 1 PER INIZIALIZZARE LARRAY (tutti i valori a 0) #########\n";
        cout << "######### INSERISCI 2 PER AGGIUNGERE UN NUMERO ALL ARRAY #########\n";
        cout << "######### INSERISCI 3 PER COPIARE UN ELEMENTO DI POSIZIONE I IN POSIZIONE J #########\n";
        cout << "######### INSERISCI 4 PER SCAMBIARE UN ELEMENTO DI POSIZIONE I CON POSIZIONE J #########\n";
        cout << "######### INSERISCI 5 PER VISUALIZZARE UN ELEMENTO IN POSIZIONE I #########\n";
        cout << "######### INSERISCI 6 PER VISUALIZZARE TUTTO LARRAY #########\n";

        cin >> num;
        if (num == -1)
            break;

        switch (num)
        {
        case 1:
        {
            inizializzaArray(arr, LENGTH);
            cout << "Array inizializzato\n";
            break;
        }
        case 2:
        {
            int num;
            cout << "Inserisci il numero\n";
            cin >> num;
            int i;
            cout << "Inserisci la posizione\n";
            cin >> i;
            bool valid = addNumToIndex(arr, i, num, LENGTH);
            if (valid)
            {
                cout << "Numero aggiunto\n";
            }
            else
            {
                cout << "Posizione non valida\n";
            }
            break;
        }
        case 3:
        {
            int i, j;
            cout << "Inserisci I e poi J\n";
            cin >> i >> j;

            bool valid = copyAtIndex(arr, i, j, LENGTH);
            if (valid)
            {
                cout << "Copiato il valore in posizione I nella posizione J\n";
            }
            else
            {
                cout << "Posizione di I o J non valida\n";
            }
            break;
        }
        case 4:
        {
            int i, j;
            cout << "Inserisci I e poi J\n";
            cin >> i >> j;

            bool valid = swapAtIndex(arr, i, j, LENGTH);
            if (valid)
            {
                cout << "Scambiato il valore in posizione I coon la posizione J\n";
            }
            else
            {
                cout << "Posizione di I o J non valida\n";
            }
            break;

            break;
        }
        case 5:
        {
            int i;
            cout << "Inserisci la posizione\n";
            cin >> i;
            bool valid = printArrIndex(arr, i, LENGTH);
            if (!valid)
            {
                cout << "Posizione non valida\n";
            }
            break;
        }
        case 6:
        {
            printArray(arr, LENGTH);
            break;
        }
        default:
        {
            cout << "Valore non valido\n";
            break;
        }
        }
    }
    return 0;
}

// Assegna tutti gli elementi di un array a 0
void inizializzaArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = 0;
    }
}

bool addNumToIndex(int arr[], int i, int valDaInserire, int length)
{
    if (i > length)
        return false;

    arr[i - 1] = valDaInserire;
    return true;
}

bool copyAtIndex(int arr[], int i, int j, int length)
{
    if (i > length || j > length)
        return false;

    arr[j - 1] = arr[i - 1];
    return true;
}

bool swapAtIndex(int arr[], int i, int j, int length)
{
    if (i > length || j > length)
        return false;
    i--;
    j--;

    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    return true;
}

bool printArrIndex(int arr[], int i, int length)
{
    if (i > length)
        return false;
    cout << "Larray in posizione " << i << " ha valore " << arr[i - 1] << endl;
    return true;
}

void printArray(int arr[], int ll)
{

    if (ll == 0)
    {
        cout << "Larray e' vuoto\n";
    }

    cout << "[";
    for (int i = 0; i < ll; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << "]" << endl;
}
