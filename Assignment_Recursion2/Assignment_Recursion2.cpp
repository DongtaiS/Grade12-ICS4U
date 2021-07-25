#include <iostream>
#include <string>
using namespace std;
int gcf(int a, int b, int counter) //counter starts at 2
{
    if (a % counter == 0 && b % counter == 0)
    {
        return counter * gcf(a / counter, b / counter, 2);
    }
    else if (a == counter || b == counter)
    {
        return 1;
    }
    return gcf(a, b, counter + 1);
}
string reverse(string res, string base)
{
    if (base.size() == 0)
    {
        return res;
    }
    res.insert(0, base.substr(0,1));
    base.erase(0, 1);
    return reverse(res, base);
}
int addDigits(int num)
{
    if (num / 10 <= 0)
    {
        return num;
    }
    return num % 10 + addDigits(num / 10);
}
int lcm(int a, int b, int counter) // counter starts at min(a,b)
{
    if (counter == 0)
    {
        return a * b;
    }
    if (a % counter == 0 && b % counter == 0)
    {
        a /= counter;
    }
    return lcm(a, b, counter-1);
}
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int lcd(int a, int b, int counter) //counter starts at 2
{
    if (a == counter || b == counter)
    {
        return 1;
    }
    if (a % counter == 0 && b % counter == 0)
    {
        return counter;
    }
    return lcd(a, b, counter+1);
}
int reverseNum(int a, int counter)
{
    if (a / 10 == 0)
    {
        return a%10 * pow(10,counter-1);
    }
    return reverseNum(a/10, counter - 1) + (a % 10) * pow(10, counter-1);
}
int main()
{
    cout << lcm(9, lcm(12, 15, 12), 9);
}