#include <iostream>

using namespace std;

int main(void)
{

    int num = 0;

    cout << "Scrivi un numero intero per sapere quale è il numero precedente e quale è il successivo";
    cin >> num;

    cout << "Il numero successivo e' " << num + 1 << " e il numero precedente e' " << num - 1;

    return 0;
}