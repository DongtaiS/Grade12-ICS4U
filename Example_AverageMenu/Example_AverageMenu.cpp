// Example_AverageMenu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int main()
{
    int num1, num2, num3;
    double average;
    char choice;
    

    for (int i = 0; i < 6; i++)
    {
        cout << i + i;
    }

    do {
        cout << "Please enter 3 integers. \n";
        cin >> num1 >> num2 >> num3;
        average = (num1 + num2 + num3) / 3.0; 
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << "The average is " << average << ". \n";
        cout << "Would you like to do this again? (y/n) \n";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
