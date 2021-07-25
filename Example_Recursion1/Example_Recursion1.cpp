#include <iostream>
using namespace std;

void showStuff(int num)
{
    if (num < 101)
    {
        cout << num << endl;
        showStuff(num + 1);
    }
}
int main()
{
    showStuff(10);
}
