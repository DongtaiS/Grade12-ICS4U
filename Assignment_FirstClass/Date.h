#pragma once
#include <iostream>
#include <string>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y);
    string dateToString();
};