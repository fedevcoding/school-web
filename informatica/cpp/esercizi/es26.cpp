#include <iostream>
#include <math.h>

using namespace std;

void promptMenu();
int iquadrante(int x, int y);
int is_origine(int x, int y);
int is_asseX(int x, int y);
int is_asseY(int x, int y);
float distanza(int x1, int y1, int x2, int y2);
void medio(int x1, int y1, int x2, int y2);

// Main
int main(void)
{
    promptMenu();

    return 0;
}

void promptMenu()
{
    while (true)
    {

        int decisione;

        cout << "##################### MENU' #####################\n";
        cout << "##################### DIGITA -1 PER USCIRE #####################\n";
        cout << "##################### DIGITA 1 per sapere il quagrande in cui si trova il punto(x, y) #####################\n";
        cout << "##################### DIGITA 2 per sapere se il punto(x e y) si trova nell'origine #####################\n";
        cout << "##################### DIGITA 3 per sapere se il punto(x, y) si trova sull'asse delle x #####################\n";
        cout << "##################### DIGITA 4 per sapere se il punto(x, y) si trova sull'asse delle y #####################\n";
        cout << "##################### DIGITA 5 per sapere il la distanza tra 2 punti sul piano cartesiano #####################\n";
        cout << "##################### DIGITA 6 per sapere il punto medio tra 2 punti sul piano cartesiano #####################\n";

        cin >> decisione;

        if (decisione == -1)
            break;

        switch (decisione)
        {
        case 1:
        {
            int x, y = 0;
            cout << "Inserisci x e y\n";
            cin >> x;
            cin >> y;
            cout << "Il punto(x, y) si trova nel quadrante n. " << iquadrante(x, y) << endl;
            break;
        }
        case 2:
        {
            int x, y = 0;
            cout << "Inserisci x e y\n";
            cin >> x;
            cin >> y;

            if (is_origine(x, y) == 1)
                cout << "Il punto (x, y) si trova nell'origine\n";
            else
                cout << "Il punto (x, y) non si trova nell'origine\n";
            ;
            break;
        }
        case 3:
        {
            int x, y = 0;
            cout << "Inserisci x e y\n";
            cin >> x;
            cin >> y;
            if (is_asseX(x, y))
            {
                cout << "Il punto(x, y) si trova sull'asse delle x\n";
            }
            else
            {
                cout << "Il punto(x, y) non si trova sull'asse delle x\n";
            }
            break;
        }
        case 4:
        {
            int x, y = 0;
            cout << "Inserisci x e y\n";
            cin >> x;
            cin >> y;
            if (is_asseY(x, y))
            {
                cout << "Il punto (x, y) si trova sull'asse delle y\n";
            }
            else
            {
                cout << "Il punto (x, y) non si trova sull'asse delle y\n";
            }
            break;
        }

        case 5:
        {
            int x1, x2, y1, y2 = 0;
            cout << "Inserisci x1, x2, y1 e y2\n";
            cin >> x1;
            cin >> x2;
            cin >> y1;
            cin >> y2;
            cout << "La distanza tra i due punti e' " << distanza(x1, y1, x2, y2) << endl;
            break;
        }
        case 6:
        {
            int x1, x2, y1, y2 = 0;
            cout << "Inserisci x1, x2, y1 e y2\n";
            cin >> x1;
            cin >> x2;
            cin >> y1;
            cin >> y2;
            medio(x1, y1, x2, y2);
            break;
        }
        }
    }

    cout << "Arrivederci!\n";
}

int iquadrante(int x, int y)
{
    // Return -1 if the point is on the x or y axis
    if (x == 0 || y == 0)
        return -1;

    // Controllare il quadrante in base a x e y
    if (x > 0 && y > 0)
        return 1;
    if (x < 0 && y > 0)
        return 2;
    if (x < 0 && y < 0)
        return 3;
    return 4;
}
int is_origine(int x, int y)
{
    return (x == 0 && y == 0) ? 1 : 0;
}
int is_asseX(int x, int y)
{
    return (y == 0 && x != 0) ? 1 : 0;
}
int is_asseY(int x, int y)
{
    return (x == 0 && y != 0) ? 1 : 0;
}
float distanza(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void medio(int x1, int y1, int x2, int y2)
{
    float x3 = (x1 + x2) / 2;
    float y3 = (y1 + y2) / 2;

    cout << "Le coordinate del punto medio sono: (" << x3 << ", " << y3 << ")\n";
}