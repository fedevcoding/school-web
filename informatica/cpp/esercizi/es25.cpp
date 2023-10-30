#include <iostream>

using namespace std;

// Function declarations
int max(int num1, int num2);
int min(int num1, int num2);
int diffMaxMin(int num1, int num2);
bool isEven(int num);
int prodottoMenoSomma(int num1, int num2);
int checkRepeated(int num1, int num2, int num3);
int maxDivisoriN(int num);

// Main
int main(void)
{
    // Test diffMaxMin
    int num1 = 5;
    int num2 = 7;
    // expected output: 2
    cout << diffMaxMin(num1, num2) << endl;
    //

    // Test is even
    int num3 = 4;
    // expected output: true
    // std::boolalpha per loggare true/false invece di 0/1
    cout << boolalpha << isEven(num3) << endl;
    //

    // Test prodottoMenoSomma
    int num4 = 7;
    int num5 = 6;
    // expected output: 29
    cout << prodottoMenoSomma(num4, num5) << endl;
    //

    // Test checkRepeated
    int num6 = 5;
    int num7 = 2;
    int num8 = 5;
    // expected output: 5
    cout << checkRepeated(num6, num7, num8) << endl;
    //

    // Test max divisori per n naturale
    int num9 = 28;
    // Expected output: 6
    cout << maxDivisoriN(num9) << endl;
    //

    return 0;
}

// Functions
int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}
int min(int num1, int num2)
{
    return num1 > num2 ? num2 : num1;
}
int diffMaxMin(int num1, int num2)
{
    return max(num1, num2) - min(num1, num2);
}
bool isEven(int num)
{
    return num % 2 == 0;
}
int prodottoMenoSomma(int num1, int num2)
{
    return (num1 * num2) - (num1 + num2);
}
int checkRepeated(int num1, int num2, int num3)
{
    int repeated = -1;

    if (num1 == num2)
        repeated = num1;
    else if (num1 == num3)
        repeated = num1;
    else if (num2 == num3)
        repeated = num2;

    return repeated;
}
int maxDivisoriN(int num)
{
    int divisori = 0;
    for (int i = num; i > 0; i--)
    {
        if (num % i == 0)
            divisori++;
    }
    return divisori;
}