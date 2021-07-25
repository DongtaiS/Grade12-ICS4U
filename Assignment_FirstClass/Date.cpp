#include "Date.h"
using namespace std;
Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}
string Date::dateToString()
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}