#include <iostream>
#define LENGTH 5

using namespace std;

bool append(int arr[], int &ll, int lf, int valDaInserire);
bool removeLast(int arr[], int &ll, int lf);
void printArray(int arr[], int ll);
void printReverse(int arr[], int ll);
void emptyArray(int &ll);

int main(void)
{

    int arr[LENGTH];
    int ll = 0;
    int lf = LENGTH;

    while (true)
    {

        int num;

        cout << "######### MENU #########\n";
        cout << "######### INSERISCI -1 PER USCIRE #########\n";
        cout << "######### INSERISCI 1 PER AGGIUNGERE UN NUMERO ALL array #########\n";
        cout << "######### INSERISCI 2 PER RIMUOVERE LULTIMO ELEMENTO DALL ARRAY #########\n";
        cout << "######### INSERISCI 3 PER STAMPARE LARRAY #########\n";
        cout << "######### INSERISCI 4 PER STAMPARE LARRAY AL CONTRARIO #########\n";
        cout << "######### INSERISCI 5 PER SVUOTARE LARRAY #########\n";

        cin >> num;
        if (num == -1)
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
                cout << "Aggiunto\n";
            else
                cout << "Errore\n";
            break;
        }
        case 2:
        {
            bool success = removeLast(arr, ll, lf);
            if (success)
                cout << "Aggiunto\n";
            else
                cout << "Errore\n";
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
        default:
        {
            cout << "Valore non valido\n";
        }
        }
    }
    return 0;
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
    cout << "[";
    for (int i = 0; i < ll; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void printReverse(int arr[], int ll)
{
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