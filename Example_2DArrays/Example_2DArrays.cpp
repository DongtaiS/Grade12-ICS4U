#include <iostream>
#include <sstream>
using namespace std;
float findAvg(int testScores[], int size)
{
    float counter = 0;
    for (int i = 0; i < size; i++)
    {
        counter += testScores[i];
    }
    return counter / size;
}
int main()
{
    string xd = "100";
    int a = stoi(xd);
    cout << a;
    string names[3]{ "john", "asdf", "123" };
    int tests[3][5]{ {92, 93, 89, 84, 90}, {91, 95, 98, 90, 100}, {87, 90, 84, 89, 92} };
    for (int i = 0; i < 3; i++)
    {
        cout << names[i] << "'s score was: " << findAvg(tests[i], 5) << endl;
    }
}
