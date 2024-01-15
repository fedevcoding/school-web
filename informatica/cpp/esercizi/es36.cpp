#include <iostream>

using namespace std;

int inserisciInCoda(int A[], int ll, int lf, int x);
int inserisci(int A[], int ll, int lf, int x, int pos);
int rimuoviValore(int A[], int ll, int x);
int rimuoviPosizione(int A[], int ll, int pos);
int accoda(int A[], int llA, int lfA, int B[], int llB);
int inserisci(int A[], int llA, int lfA, int B[], int llB, int pos);
bool arrayCrescente(int A[], int ll);
int inserisciOrdinatoCrescente(int A[], int ll, int lf, int x);
int search(int A[], int ll, int x);
void printArr(int arr[], int length);

const int LENGTH = 10;

int main()
{
    int arr[LENGTH], ll, lf;

    lf = LENGTH;

    // Menu di test

    return 0;
}

int inserisciInCoda(int A[], int ll, int lf, int x)
{
    if (ll >= lf)
        return -1;

    A[ll] = x;

    return ++ll;
}

int inserisci(int A[], int ll, int lf, int x, int pos)
{
    if (ll >= lf)
        return -1;

    for (int i = ll; i > pos; i--)
    {
        A[i] = A[i - 1];
    }
    A[pos] = x;

    ll++;

    return ++ll;
}

int rimuoviValore(int A[], int ll, int x)
{

    int pos = search(A, ll, x);

    if (pos == -1)
        return -1;

    return rimuoviPosizione(A, ll, pos);
}

int rimuoviPosizione(int A[], int ll, int pos)
{
    if (pos == ll - 1)
        return --ll;

    if (pos >= ll || pos < 0)
        return -1;

    for (int i = pos; i <= ll; i++)
    {
        A[i] = A[i + 1];
    }

    return --ll;
}

int accoda(int A[], int llA, int lfA, int B[], int llB)
{
    if (llA + llB >= lfA)
    {
        return -1;
    }

    for (int i = 0; i < llB; i++)
    {
        A[i + llA] = B[i];
    }

    return llA + llB;
}

int inserisci(int A[], int llA, int lfA, int B[], int llB, int pos)
{
    if (llA + llB >= lfA)
    {
        return -1;
    }

    for (int i = llA - 1; i >= pos; i--)
    {
        A[i + llB] = A[i];
    }

    for (int i = 0; i < llB; i++)
    {
        A[i + pos] = B[i];
    }

    return llA + llB;
}

bool arrayCrescente(int A[], int ll)
{
    int prev = A[0];
    for (int i = 1; i < ll; i++)
    {
        if (A[i] < prev)
            return false;
        prev = A[i];
    }
    return true;
}

int inserisciOrdinatoCrescente(int A[], int ll, int lf, int x)
{
    if (ll >= lf || !arrayCrescente(A, ll))
    {
        return -1;
    }

    int pos = 0;
    for (int i = 0; i < ll; i++)
    {
        pos = i;
        if (A[i] > x)
        {
            break;
        }
    }

    for (int i = ll; i > pos; i--)
    {
        A[i] = A[i - 1];
    }
    A[pos] = x;

    return ++ll;
}

// helper
void printArr(int arr[], int length)
{
    cout << "[ ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << ", ";
    cout << " ]" << endl;
}

int search(int A[], int ll, int x)
{
    for (int i = 0; i < ll; i++)
        if (A[i] == x)
            return i;
    return -1;
}
