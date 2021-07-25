#include <iostream>
using namespace std;

void sayHi();
void sayHello(string);
void calculate(double &, long, int);

void calculate(double &a, long b, int c = 5)
{
    cout << a + b + c;
}
bool isPrime(int input)
{
    bool prime = true;
    for (int i = 2; i <= sqrt(input); i++)
    {
        if (input % i == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}
int main()
{
    double d = 0.5;
    calculate(d, 2);
}
void sayHi()
{
    double d = 1;
    std::cout << d;
}
void sayHello(string name)
{
    cout << "Hello " << name;
}