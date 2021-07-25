#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
struct CarData
{
    string name;
    double mpg;
    int cylinders;
    double displacement;
    double hp;
    double weight;
    double acceleration;
    int year;
    string country;
};

int CountCountry(string country, vector<CarData> cars)
{
    int total = 0;
    for (CarData car : cars)
    {
        if (car.country == country)
        {
            total++;
        }
    }
    return total;
}

int main()
{
    ifstream myFile("Cars.txt");
    string line;
    vector<CarData> cars;
    while (getline(myFile, line, '\n'))
    {
        string tname;
        string tmpg;
        string tcylinders;
        string tdisplacement;
        string thp;
        string tweight;
        string tacceleration;
        string tyear;
        string tcountry;
        stringstream ss(line);
        getline(ss, tname, ',');
        getline(ss, tmpg, ',');
        getline(ss, tcylinders, ',');
        getline(ss, tdisplacement, ',');
        getline(ss, thp, ',');
        getline(ss, tweight, ',');
        getline(ss, tacceleration, ',');
        getline(ss, tyear, ',');
        getline(ss, tcountry, ',');
        cars.push_back({ tname, stod(tmpg), stoi(tcylinders), stod(tdisplacement), stod(thp), stod(tweight), stod(tacceleration), stoi(tyear), tcountry });
    }
    cout << CountCountry("US", cars);
}
