#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int main()
{
    Date newYears(1, 1, 2021);
    cout << newYears.dateToString();
}
