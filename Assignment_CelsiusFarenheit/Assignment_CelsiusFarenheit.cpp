#include <iostream>

using namespace std;
int main()
{
    cout << "C" << "\t" << "F" << endl;
    for (int i = 0; i <= 30; i++)
    {
        cout << i << "\t" << i * (9.0 / 5) + 32 << endl;
    }
}