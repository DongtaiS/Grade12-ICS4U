#include <iostream>

using namespace std;
unsigned long long factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    return num*factorial(num-1);
}
void print(int num)
{
    if (num > 0)
    {
        cout << "Hello world!" << endl;
        print(num - 1);
    }
}
int sum(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num + sum(num-1);
}
double power(double num, int exponent)
{
    if (exponent == 0)
    {
        return 1.0;
    }
    else if (exponent < 0)
    {
        return 1.0 / power(num, -exponent);
    }
    return num *= power(num, exponent - 1);
}
void printFactors(int num, int divisor)
{
    if (divisor == 0)
    {
        return;
    }
    else if (num % divisor == 0)
    {
        cout << divisor << " is a factor of " << num << endl;
    }
    printFactors(num, divisor - 1);
}
int main()
{
}