#include <iostream>

using namespace std;
struct bruh
{
	int empID;
	string name;
	int hours;
	float rate;
	float wage = hours * rate;
};
int main()
{
	bruh no{ 1, "bruh", 2, 2.0};
	cout << no.wage;
	no.rate = 20.0;
	cout << no.wage;
}