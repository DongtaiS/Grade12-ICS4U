#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
//Jason - how many numbers
int howMuch() {
    int amount;
    cout << "How many random numbers do you want (max = 100)? ";
    cin >> amount;
    while (amount < 0 || amount > 100) {
        cout << "Try again.\nHow many random numbers do you want (max = 100)? ";
        cin >> amount;
    } 

    return amount;
}

//Jason - random numbers
void randomNum(int& amount)
{
    srand(time(0));

    ofstream myFile("numbers.txt");
    if (myFile.is_open())
    {
        myFile << rand() % 1000 + 1;
        for (int i = 0; i < amount - 1; i++)
        {
            myFile << " ";
            int temp = rand() % 1000 + 1;
            myFile << temp;
        }
        myFile.close();
    }
}

//Dongtai - reading from file
void readFromFile(int itemCount, int arr[])
{
    ifstream textFile;
    textFile.open("numbers.txt");
    int count = 0;
    while (count < itemCount && textFile >> arr[count])
    {
        count++;
    }
    textFile.close();
}

//Dongtai - minimum
int findMin(int arr[], int size)
{
    int result = 10000000;
    for (int i = 0; i < size; i++)
    {
        result = min(arr[i], result);
    }
    return result;
}

//Dongtai - maximum
int findMax(int arr[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result = max(arr[i], result);
    }
    return result;
}



//John VK - sum of numbers
double sumFun(int arr[], int amount) {

    int counter = 0;
    double sum = 0;

    while (counter != amount) {
        sum += arr[counter];

        counter += 1;
    }
    return sum;
}


//John VK - Average of numbers
double avgFun(int arr[], int amount) {

    return sumFun(arr, amount) / (double)amount;

}
