#include <iostream>
#define ARRAY_SIZE 100

using namespace std;

void inserisciPeso(float arr[], int position, float value);
void setCost(int &costoAlKilo, int newCost);
float costoTotale(float arr[], int length, int costoAlKilo);
int quantitaSopraPeso(float arr[], int length, int prezzoLimite, int costoAlKilo);
float getPrice(int costoAlKilo, float peso);
float costoMedio(float costoTotale, int length);

int main(void)
{

    int ll = 0;

    float *myArr = (float *)malloc(ARRAY_SIZE * sizeof(float));

    int costoAlKilo = -1;

    while (true)
    {
        int num;

        cout << "MENU\n";
        cout << "##### 1 - Inserisci il peso di un pacco #####\n";
        cout << "##### 2 - Inserisci il costo al Kg della spedizione #####\n";
        cout << "##### 3 - Visualizza le informazioni relative ai costi di spedizione #####\n";
        cout << "##### 4 - Inizia un nuova spedizione #####\n";
        cout << "##### 5 - Esci #####\n";

        cin >> num;

        if (num == 5)
            break;

        if (costoAlKilo == -1 && num != 2)
        {
            cout << "Devi prima mettere un peso di spedizione!\n";
            continue;
        }

        switch (num)
        {
        case 1:
        {
            float val;
            cout << "Inserisci il valore \n";
            cin >> val;
            inserisciPeso(myArr, ll, val);
            ll++;
            break;
        }
        case 2:
        {
            int costo;
            cout << "Inserisci il costo \n";
            cin >> costo;

            setCost(costoAlKilo, costo);
            cout << "Il nuovo costo e': " << costoAlKilo << " euro al kilo\n";
            break;
        }
        case 3:
        {
            float costoTot = costoTotale(myArr, ll, costoAlKilo);
            cout << "Il costo totale e' " << costoTot << endl;
            int pacchiSopraLimite = quantitaSopraPeso(myArr, ll, 50, costoAlKilo);
            cout << "I pacchi sopra il peso limite sono " << pacchiSopraLimite << endl;
            float costoMed = costoMedio(costoTot, ll);
            cout << "Il costo medio e' " << costoMed << endl;
            break;
        }
        case 4:
        {
            ll = 0;
            break;
        }
        }
    }

    return 0;
}

void inserisciPeso(float arr[], int position, float value)
{
    arr[position] = value;
}

void setCost(int &costoAlKilo, int newCost)
{
    costoAlKilo = newCost;
}

float costoTotale(float arr[], int length, int costoAlKilo)
{
    float tot = 0;

    for (int i = 0; i < length; i++)
    {
        tot += getPrice(costoAlKilo, arr[i]);
    }

    return tot;
}

int quantitaSopraPeso(float arr[], int length, int prezzoLimite, int costoAlKilo)
{
    int tot = 0;

    for (int i = 0; i < length; i++)
    {
        if (getPrice(costoAlKilo, arr[i]) > prezzoLimite)
            tot++;
    }

    return tot;
}

float getPrice(int costoAlKilo, float peso)
{
    return costoAlKilo * peso;
}

float costoMedio(float costoTotale, int length)
{
    return costoTotale / length;
}