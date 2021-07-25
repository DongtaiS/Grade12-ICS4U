#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main()
{
    const int ARRSIZE = 100;
    int arr[ARRSIZE];
    int count = 0;
    ofstream outputFile;
    //outputFile.open("Text.txt");

    //srand(time(0));
    //for (int i = 0; i < ARRSIZE; i++)
    //{
    //    arr[i] = rand() % 1000 + 1;
    //}
    //while (count < ARRSIZE && outputFile << arr[count] << endl)
    //{
    //    count++;
    //}
    //outputFile.close();
    //for (int i : arr)
    //{
    //    cout << i << endl;
    //}

    ifstream inputFile;
    inputFile.open("Text.txt");
    count = 0;
    while (count < ARRSIZE && inputFile >> arr[count])
    {
        count++;
    }
    for (int i : arr)
    {
        cout << i << endl;
    }
    int result[ARRSIZE] = { 0 };
    int counter = 0;
    bool swapped;
    do
    {
        swapped = false;
        //int index = 0;
        //int lowest = 1000000;
        for (int j = 0; j < ARRSIZE-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
                counter += 8;
            }
        }
        counter += 2;
        //result[counter] = arr[index];
        //arr[index] = 10000000;
        counter++;
    } while (swapped);
    for (int i : arr)
    {
        cout << i << endl;
    }
    cout << counter;
}