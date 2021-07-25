#include "header.h"

using namespace std;

int main() {

    int amount = howMuch();
    randomNum(amount);

    int arr[100];

    readFromFile(amount, arr);

    cout << "The sum is " << sumFun(arr, amount) << endl;
    cout << "The average is " << avgFun(arr, amount) << endl;
    cout << "The maximum value is " << findMax(arr, amount) << endl;
    cout << "The minimum value is " << findMin(arr, amount) << endl;
}