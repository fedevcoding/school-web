#include <iostream>
#define ARRAY_SIZE 10

using namespace std;

int getSum(int arr[], int size);
int getMax(int arr[], int size);
void printArr(int arr[], int size);

int main(void)
{
    int *myArr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    bool defined = false;

    while (true)
    {
        int num;

        cout << "###### MENU ######\n";
        cout << "###### 0 - per uscire ######\n";
        cout << "###### 1 - inserisci 10 numeri ######\n";
        cout << "###### 2 - calcolare la somma ######\n";
        cout << "###### 3 - stampa i contenuti dell'array ######\n";
        cout << "###### 4 - stampa il numero più grande dell'array ######\n";

        cin >> num;

        if (num == 0)
            break;
        if (!defined && (num == 2 || num == 3 || num == 4))
        {
            cout << "Array not initialized yet!\n";
            continue;
        }

        defined = true;

        switch (num)
        {
        case 1:
        {
            for (int i = 0; i < ARRAY_SIZE; i++)
            {
                int num;
                cout << "Insert number " << i + 1 << endl;
                cin >> num;
                myArr[i] = num;
            }
            break;
        }
        case 2:
        {
            int sum = getSum(myArr, ARRAY_SIZE);
            cout << "La somma e' " << sum << endl;
            break;
        }
        case 3:
        {
            printArr(myArr, ARRAY_SIZE);
            break;
        }
        case 4:
        {
            int max = getMax(myArr, ARRAY_SIZE);
            cout << "Il piu' grande e' " << max << endl;
            break;
        }
        }
    }

    return 0;
}

int getSum(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int getMax(int arr[], int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void printArr(int arr[], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << "]\n";
}
