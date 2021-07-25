#include <iostream>

using namespace std;
void iterative()
{
	int base, exponent, result = 1;
	cout << "Enter a base number. " << endl;
	cin >> base;
	cout << "Enter an exponent. " << endl;
	cin >> exponent;

	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	cout << base << " raised to the " << exponent << " is " << result;
}
int recursive(int base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	return base * recursive(base, exponent - 1);
}
int main()
{
	int base, exponent, result = 1;
	cout << "Enter a base number. " << endl;
	cin >> base;
	cout << "Enter an exponent. " << endl;
	cin >> exponent;
	result = recursive(base, exponent);
	cout << base << " raised to the " << exponent << " is " << result;
}