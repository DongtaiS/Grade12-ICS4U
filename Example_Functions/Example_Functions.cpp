#include <iostream>

using namespace std;
void sayHello(string name)
{
    cout << "Hello " << name << endl;
}
void qualify()
{
    cout << "Congratulations, you qualify for our credit card. \n";
    cout << "Our annual interest rate is 12%. \n";
}
void noQualify()
{
    cout << "Unfortunately, you do not qualify for our credit card. \n";
    cout << "To qualify, you must have worked at your current job for more than 2 years, \n";
    cout << "and have a salary of over $17000. \n";
}
int main()
{
    string temp;
    cin >> temp;
    sayHello(temp);
    qualify();
    noQualify();
}