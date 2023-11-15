#include <iostream>

#define DISTANCE_CASE 32
#define DISTANCE 26

const int START_UPPER = 65;
const int FINISH_UPPER = 90;
const int START_LOWER = 97;
const int FINISH_LOWER = 122;

bool isUpper(char charachter);
char invertCase(char charachter);
char isLetter(char charachter);
char shiftChar(char charachter, int shiftAmount, bool isLeftShift);

using namespace std;

int main(void)
{

    while (true)
    {

        int decisione;

        cout << "##################### MENU' #####################\n";
        cout << "## DIGITA -1 PER USCIRE ##\n";
        cout << "## DIGITA 1 PER INVERTIRE IN MAIUSCOLO/MINUSCOLO UN CARATTERE ##\n";
        cout << "## DIGITA 2 PER FARE LO SHIFT DI UN CARATTERE ##\n";

        cin >> decisione;

        if (decisione == -1)
            break;

        switch (decisione)
        {
        case 1:
        {
            char charachter;
            cout << "Inserisci il carattere: \n";
            cin >> charachter;

            if (!isLetter(charachter))
            {
                cout << "Il carattere inserito non e' una lettera\n";
                break;
            }

            char newChar = invertCase(charachter);

            cout << "Il carattere invertito e': " << newChar << "\n";

            break;
        }
        case 2:
        {
            char charachter;
            int shiftAmount;
            bool isLeftShift;

            cout << "Inserisci il carattere: \n";
            cin >> charachter;

            if (!isLetter(charachter))
            {
                cout << "Il carattere inserito non e' una lettera\n";
                break;
            }

            cout << "Inserisci la quantita' di shift: \n";
            cin >> shiftAmount;

            cout << "Inserisci 0 per shiftare a destra, 1 per shiftare a sinistra: \n";
            cin >> isLeftShift;

            char newChar = shiftChar(charachter, shiftAmount, isLeftShift);

            cout << "Il carattere shiftato e': " << newChar << "\n";

            break;
        }
        }
    }

    cout << "Arrivederci!\n";

    return 0;
}

bool isUpper(char charachter)
{
    return (charachter >= START_UPPER && charachter <= FINISH_UPPER);
}

char invertCase(char charachter)
{
    bool charIsUpper = isUpper(charachter);

    char newChar;
    if (charIsUpper)
        newChar = charachter + DISTANCE_CASE;
    else
        newChar = charachter - DISTANCE_CASE;

    return newChar;
}

char isLetter(char charachter)
{
    return (charachter >= START_UPPER && charachter <= FINISH_UPPER) || (charachter >= START_LOWER && charachter <= FINISH_LOWER);
}

char shiftChar(char charachter, int shiftAmount, bool isLeftShift)
{

    bool charIsUpper = isUpper(charachter);

    if (charIsUpper)
        charachter = invertCase(charachter);

    char newChar;
    int realShiftAmount = shiftAmount % DISTANCE;

    if (!isLeftShift)
    {
        int position = (charachter - START_LOWER) % DISTANCE;

        newChar = START_LOWER + ((position + realShiftAmount) % DISTANCE);
    }
    else
    {
        int position = ((START_LOWER - charachter) + DISTANCE) - 1;

        newChar = FINISH_LOWER - (((DISTANCE + (position + realShiftAmount)) % DISTANCE));
    }

    if (charIsUpper)
        newChar = invertCase(newChar);

    return newChar;
}