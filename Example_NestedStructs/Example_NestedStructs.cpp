#include <iostream>

using namespace std;

struct Residence 
{
    string streetAddress;
    string city;
    string postalCode;
};

struct BirthDate
{
    int year;
    int month;
    int day;
};

struct EmployeeData
{
    int empID;
    string name;
    Residence location;
    BirthDate birthDay;
};

int main()
{
    EmployeeData bob = { 1, "bob", {"123 street road", "townville", "111111"}, {2000,1,1} };
    cout << bob.birthDay.day << bob.name << bob.location.streetAddress;
}