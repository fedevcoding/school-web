#include <iostream>

using namespace std;

int main(void)
{

    while (true)
    {
        int operation, firstNumber, secondNumber, result;

        cout << "####### CALCULATOR #######\n";
        cout << "Enter the operation to execute: \n";
        cout << "1 for ADDITION \n";
        cout << "2 for SUBTRACTION \n";
        cout << "3 for MULTIPLICATION \n";
        cout << "4 for DIVISION \n";
        cout << "0 to EXIT \n\n";

        cin >> operation;

        if (operation == 0)
            break;

        if (operation != 1 && operation != 2 && operation != 3 && operation != 4)
        {
            cout << "Operation not valid!\n";
            continue;
        }

        cout << "ENTER FIRST NUMBER \n";
        cin >> firstNumber;
        cout << "ENTER SECOND NUMBER \n";
        cin >> secondNumber;

        switch (operation)
        {
        case 1:
            result = firstNumber + secondNumber;
            break;
        case 2:
            result = firstNumber - secondNumber;
            break;
        case 3:
            result = firstNumber * secondNumber;
            break;
        case 4:
            result = firstNumber / secondNumber;
            break;
        }

        cout << "Result is: " << result << endl;
    }

    cout << "See you next time, bye bye!\n";

    return 0;
}