#include <iostream>

using namespace std;
int main()
{
    cout << "Code" << "\t" << "Char" << "\t" << "Code" << "\t" << "Char" << "\t" << endl;
    for (int i = 0; i < 128; i++)
    {
        char character = i;
        cout << i << "\t" << character << "\t";
        if (i % 2 != 0)
        {
            cout << endl;
        }
    }
}

