#include <iostream>

using namespace std;
int gcd(int a, int b, int counter) //counter starts at min(a,b)
{
    if (a % counter == 0 && b % counter == 0)
    {
        return counter;
    }
    return gcd(a, b, counter - 1);
}
int gcd(int a, int b, int c, int counter) //counter starts at min(a,b,c)
{
    if (a % counter == 0 && b % counter == 0 && c % counter == 0)
    {
        return counter;
    }
    return gcd(a, b, c, counter - 1);
}
int main()
{
    char continueInput;
    do
    {
        cout << "Would you like to find the Greatest Common Denominator of 2 numbers, or 3 numbers?" << endl;
        int input;
        cin >> input;
        while (input != 2 && input != 3)
        {
            cout << "Please only enter 2 or 3" << endl;
            cin >> input;
        }
        if (input == 2)
        {
            int a, b;
            do
            {
                cout << "Please enter two numbers greater than one hundred" << endl;
                cin >> a;
                cin >> b;
            } while (a <= 100 || b <= 100);
            gcd(a, b, 2);
            cout << "The GCD of your numbers is " << gcd(a, b, min(a, b)) << endl;
        }
        else
        {
            int a, b, c;
            do
            {
                cout << "Please enter three numbers greater than one hundred" << endl;
                cin >> a;
                cin >> b;
                cin >> c;
            } while (a <= 100 || b <= 100 || c <= 100);
            cout << "The GCD of your numbers is " << gcd(a, b, c, min(a, min(b, c))) << endl;
        }
        cout << "Would you like to try again? (Y/N) " << endl;
        cin >> continueInput;
        while (continueInput != 'Y' && continueInput != 'y' && continueInput != 'N' && continueInput != 'n')
        {
            cout << "Please only enter the letter Y or N " << endl;
            cin >> continueInput;
        }
    } while (continueInput == 'Y' || continueInput == 'y');
}
