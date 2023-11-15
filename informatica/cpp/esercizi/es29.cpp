#include <iostream>

int tipoTriangolo(int l1, int l2, int l3);
void swap(int &a, int &b);
bool validDate(int &day, int &month, int &year);
void robinHood(int &x, int &y);
void riduciMinimiTermini(int &num, int &den);
void promptMenu();

using namespace std;

int main(void)
{
    promptMenu();

    return 0;
}

// 0: equilatero, 1: isoscele, 2: scaleno
int tipoTriangolo(int l1, int l2, int l3)
{
    if (l1 == l2 && l1 == l3)
        return 0; // equilatero

    if (l1 == l2 || l1 == l3 || l2 == l3)
        return 1; // isoscele

    if (l1 != l2 && l1 != l3 && l2 != l3)
        return 2; // scaleno

    return -1;
}

// In place swap without temp
void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

bool validDate(int &day, int &month, int &year)
{

    // inexistent month
    if (month <= 0 || month > 12)
        return false;

    if (year < 0)
        return false;

    int maxDays = 0;

    switch (month)
    {
    case 1:
        maxDays = 31;
        break;
    case 2:
        maxDays = 28;
        break;
    case 3:
        maxDays = 31;
        break;
    case 4:
        maxDays = 30;
        break;
    case 5:
        maxDays = 31;
        break;
    case 6:
        maxDays = 30;
        break;
    case 7:
        maxDays = 31;
        break;
    case 8:
        maxDays = 31;
        break;
    case 9:
        maxDays = 30;
        break;
    case 10:
        maxDays = 31;
        break;
    case 11:
        maxDays = 30;
        break;
    case 12:
        maxDays = 31;
        break;
    default:
        return false;
    }

    if (day > maxDays)
        return false;

    // modify date based on day or month
    if (day == maxDays && month == 12)
    {
        day = 1;
        month = 1;
        year++;
    }
    else if (day == maxDays)
    {
        day = 1;
        month++;
    }
    else
        day++;

    return true;
}

void robinHood(int &x, int &y)
{
    float avg = (x + y) / 2;
    x = avg;
    y = avg;
}

// 6/3 => 3/1
void riduciMinimiTermini(int &num, int &den)
{
    int max = num > den ? num : den;

    for (int i = max; i > 1; i--)
    {
        if (num % i == 0 && den % i == 0)
        {
            num /= i;
            den /= i;
        }
    }
}

void promptMenu()
{
    while (true)
    {

        int decisione;

        cout << "##################### MENU' #####################\n";
        cout << "## DIGITA -1 PER USCIRE ##\n";
        cout << "## DIGITA 1 PER SAPERE IL TIPO DI TRIANGOLO DATI I 3 LATI ##\n";
        cout << "## DIGITA 2 PER SCAMBIARE IL VALORE DI DUE VARIABILI ##\n";
        cout << "## DIGITA 3 PER SAPERE SE UNA DATA E' VALIDA E SAPERE IL GIORNO SUCCESSIVO ##\n";
        cout << "## DIGITA 4 PER BILANCIARE IL VALORE DI 2 VARIABILI ##\n";
        cout << "## DIGITA 5 PER RIDURRE UNA FRAZIONE AI MINIMI TERMINI ##\n";

        cin >> decisione;

        if (decisione == -1)
            break;

        switch (decisione)
        {
        case 1:
        {
            int l1, l2, l3;
            cout << "Inserisci i 3 lati del triangolo: \n";
            cin >> l1 >> l2 >> l3;

            int tipo = tipoTriangolo(l1, l2, l3);

            if (tipo == 0)
                cout << "Il triangolo e' equilatero\n";
            else if (tipo == 1)
                cout << "Il triangolo e' isoscele\n";
            else if (tipo == 2)
                cout << "Il triangolo e' scaleno\n";

            break;
        }
        case 2:
        {
            int a, b;
            cout << "Inserisci i due valori: \n";
            cin >> a >> b;

            swap(a, b);

            cout << "I valori scambiati sono: " << a << " " << b << "\n";

            break;
        }
        case 3:
        {
            int day, month, year;
            cout << "Inserisci la data (giorno, mese, anno): \n";
            cin >> day >> month >> year;

            if (validDate(day, month, year))
                cout << "La data e' valida e il giorno successivo e': " << day << "/" << month << "/" << year << "\n";
            else
                cout << "La data non e' valida\n";

            break;
        }
        case 4:
        {
            int x, y;
            cout << "Inserisci i due valori: \n";
            cin >> x >> y;

            robinHood(x, y);

            cout << "I valori bilanciati sono: " << x << " " << y << "\n";

            break;
        }
        case 5:
        {
            int num, den;
            cout << "Inserisci il numeratore e il denominatore: \n";
            cin >> num >> den;

            riduciMinimiTermini(num, den);

            cout << "La frazione ridotta ai minimi termini e': " << num << "/" << den << "\n";

            break;
        }
        }
    }

    cout << "Arrivederci!\n";
}
