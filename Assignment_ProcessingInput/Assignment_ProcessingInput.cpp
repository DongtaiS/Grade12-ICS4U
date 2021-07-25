#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    int arr[100];
    ifstream file;
    file.open("RandomNumbers.txt");
    int counter = 0;
    int min = 1000000, max = 0;
    long total = 0;
    while (counter < 100 && file >> arr[counter])
    {
        counter++;
    }
    counter = 0;
    for (int i : arr)
    {
        if (i < min)
        {
            min = i;
        }
        if (i > max)
        {
            max = i;
        }
        total += i;
    }
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << total / 100.0 << endl;
}