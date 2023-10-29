#include <iostream>

// utils
int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}
int max(int num1, int num2, int num3)
{
    return max(max(num1, num2), num3);
}

int min(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}
int min(int num1, int num2, int num3)
{
    return min(min(num1, num2), num3);
}
// utils

using namespace std;

int main(void)
{
    const int num1 = 7;
    const int num2 = 23;
    const int num3 = 2;

    int biggest = max(num1, num2, num3);

    cout << "Biggest: " << biggest << "\n";

    return 0;
}