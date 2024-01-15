#include <iostream>

using namespace std;

void printArr(int arr[], int length);
float totEuro(const int monete[], int arr[], int length);
void printTotMonete(const int monete[], int arr[], int length);
int mostFrequentCoin(const int monete[], int arr[], int length);
bool canPay(float euro, const int monete[], int arr[], int length);

int main(void)
{

    const int DIM = 5;
    int A[DIM];
    const int monete[DIM] = {10, 20, 50, 100, 200};

    for (int i = 0; i < DIM; i++)
    {
        int moneta = monete[i];

        int monete;
        cout << "Inserisci quante monete da " << moneta << " vuoi usare: ";
        cin >> monete;

        A[i] = monete;
        int val = moneta * monete;
    }

    float tot = totEuro(monete, A, DIM);
    cout << "Il totale inserito e' " << tot << " euro\n";

    printTotMonete(monete, A, DIM);

    int mostUsedCoin = mostFrequentCoin(monete, A, DIM);
    cout << "La moneta piu' usata e' da " << mostUsedCoin << endl;

    float euro;
    cout << "Inserisci una quantita' da massimo 10 auro: ";
    cin >> euro;

    bool resCanPay = canPay(euro, monete, A, DIM);
    if (resCanPay)
    {
        cout << "Si, puoi pagare\n";
    }
    else
    {
        cout << "No, non puoi pagare\n";
    }

    return 0;
}

void printArr(int arr[], int length)
{
    cout << "[";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

float totEuro(const int monete[], int arr[], int length)
{

    float tot = 0;
    for (int i = 0; i < length; i++)
    {
        tot += (float)(monete[i] * arr[i]) / 100;
    }

    return tot;
}

void printTotMonete(const int monete[], int arr[], int length)
{
    int tot = 0;

    for (int i = 0; i < length; i++)
    {
        tot += arr[i];
        cout << "Ci sono " << arr[i] << " monete da " << monete[i] << endl;
    }
    cout << "In totale ci sono " << tot << " monete\n";
}

int mostFrequentCoin(const int monete[], int arr[], int length)
{

    int mostCoinIndex = 0;

    for (int i = 1; i < length; i++)
    {
        if (arr[i] > arr[mostCoinIndex])
            mostCoinIndex = i;
    }

    return monete[mostCoinIndex];
}

// bool canPay(float euro, const int monete[], int arr[], int length)
// {
//     float tot = euro * 100;

//     for (int i = length - 1; i >= 0; i--)
//     {
//         int nMonete = arr[i];
//         int moneta = monete[i];

//         for (int j = 0; j < nMonete; j++)
//         {
//             if (tot - moneta >= 0)
//             {
//                 tot -= moneta;
//             }
//             else if (tot == 0)
//             {
//                 return true;
//             }
//             else if (tot < 0)
//             {
//                 return false;
//             }
//         }
//     }

//     return false;
// }