#include <iostream>
#define ARRAY_SIZE 10

using namespace std;

int getSum(int arr[], int size);
int getMax(int arr[], int size);
void printArr(int arr[], int size);

int main(void)
{
    int *myArr = (int *)malloc(ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int num;
        cout << "Insert a number\n";
        cin >> num;
        myArr[i] = num;
    }

    int sum = getSum(myArr, ARRAY_SIZE);
    int max = getMax(myArr, ARRAY_SIZE);

    cout << "La somma dei numeri e': " << sum << endl;
    cout << "Il numero piu' grande e': " << max << endl;
    cout << "Array stampato: ";
    printArr(myArr, ARRAY_SIZE);

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