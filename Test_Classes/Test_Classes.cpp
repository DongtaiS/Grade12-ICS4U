#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double d = 1.4;
	cout << fixed << showpoint << setprecision(2);
	cout << d;
}