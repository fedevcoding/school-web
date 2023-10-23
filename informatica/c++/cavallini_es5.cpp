#include <iostream>

using namespace std;

int main(void){

    int num = 0;

    cout << "Scrivi un numero intero per sapere se è pari o dispari\n";
    cin >> num;


    if(num % 2 == 0) cout << "Il numero " << num << " è pari\n";
    else cout << "Il numero " << num << " è dispari\n";

    return 0;
}