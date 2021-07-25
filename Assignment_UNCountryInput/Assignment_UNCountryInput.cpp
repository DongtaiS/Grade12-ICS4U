#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct CountryData
{
    string name;
    int area;
    double birthRate;
    double deathRate;
    long long int debtExternal;
    long long int GDP;
    double infantMortality;
    int internetHosts;
    int internetUsers;
    int laborForce;
    double birthLifeExp;
};

int countCountries(vector<CountryData> countries)
{
    return countries.size();
}

string largestCountryArea(vector<CountryData> countries)
{
    string result;
    int size = 0;
    for (CountryData country : countries)
    {
        if (country.area > size)
        {
            size = country.area;
            result = country.name;
        }
    }
    return result;
}

string smallestCountryArea(vector<CountryData> countries)
{
    string result;
    int size = INT_MAX;
    for (CountryData country : countries)
    {
        if (country.area < size)
        {
            size = country.area;
            result = country.name;
        }
    }
    return result;
}

double avgCountrySize(vector<CountryData> countries)
{
    double total = 0;
    for (CountryData country : countries)
    {
        total += country.area;
    }
    return total / countries.size();
}

string mostInternetHosts(vector<CountryData> countries)
{
    string result;
    int max = 0;
    for (CountryData country : countries)
    {
        if (country.internetHosts > max)
        {
            max = country.internetHosts;
            result = country.name;
        }
    }
    return result;
}

string mostInternetUsers(vector<CountryData> countries)
{
    string result;
    int max = 0;
    for (CountryData country : countries)
    {
        if (country.internetUsers > max)
        {
            max = country.internetUsers;
            result = country.name;
        }
    }
    return result;
}

double highestBirthRate(vector<CountryData> countries)
{
    double highest = 0;
    for (CountryData country : countries)
    {
        highest = max(country.birthRate, highest);
    }
    return highest;
}

long double avgGDP(vector<CountryData> countries)
{
    long double total = 0;
    int count = 0;
    for (CountryData country : countries)
    {
        if (country.GDP != 0)
        {
            total += country.GDP;
            count++;
        }
    }
    return total / count;
}

double avgLifeExpectancy(vector<CountryData> countries)
{
    double total = 0;
    int count = 0;
    for (CountryData country : countries)
    {
        if (country.birthLifeExp != 0)
        {
            total += country.birthLifeExp;
            count++;
        }
    }
    return total / count;
}

string highestLifeExpCountry(vector<CountryData> countries)
{
    string result;
    double max = 0;
    for (CountryData country : countries)
    {
        if (country.birthLifeExp > max)
        {
            max = country.birthLifeExp;
            result = country.name;
        }
    }
    return result;
}

long double avgExtDebt(vector<CountryData> countries)
{
    long double total = 0;
    int count = 0;
    for (CountryData country : countries)
    {
        if (country.debtExternal != 0)
        {
            total += country.debtExternal;
            count++;
        }
    }
    return total / count;
}

string smallestLabourforce(vector<CountryData> countries)
{
    string result;
    int min = INT_MAX;
    for (CountryData country : countries)
    {
        if (country.laborForce != 0 && country.laborForce < min)
        {
            min = country.laborForce;
            result = country.name;
        }
    }
    return result;
}

double avgInfantMortality(vector<CountryData> countries)
{
    double total = 0;
    int count = 0;
    for (CountryData country : countries)
    {
        if (country.infantMortality != 0)
        {
            total += country.infantMortality;
            count++;
        }
    }
    return total / count;
}

string lowestDeathRateCountry(vector<CountryData> countries)
{
    string result;
    double min = INT_MAX;
    for (CountryData country : countries)
    {
        if (country.deathRate != 0 && country.deathRate < min)
        {
            min = country.deathRate;
            result = country.name;
        }
    }
    return result;
}

int main()
{
    vector<CountryData> countries;
    ifstream countryFile("CountryData.csv");
    string line;
    while (getline(countryFile, line, '\n'))
    {
        stringstream lineStream(line);
        string tcountry;
        string tarea;
        string tbirthRate;
        string tdeathRate;
        string tdebtExternal;
        string tGDP;
        string tinfantMortality;
        string tinternetHosts;
        string tinternetUsers;
        string tlaborForce;
        string tbirthLifeExpectancy;
        getline(lineStream, tcountry, ',');
        getline(lineStream, tarea, ',');
        getline(lineStream, tbirthRate, ',');
        getline(lineStream, tdeathRate, ',');
        getline(lineStream, tdebtExternal, ',');
        getline(lineStream, tGDP, ',');
        getline(lineStream, tinfantMortality, ',');
        getline(lineStream, tinternetHosts, ',');
        getline(lineStream, tinternetUsers, ',');
        getline(lineStream, tlaborForce, ',');
        getline(lineStream, tbirthLifeExpectancy, ',');
        countries.push_back({ tcountry, stoi(tarea), stod(tbirthRate), stod(tdeathRate), stoll(tdebtExternal), stoll(tGDP), stod(tinfantMortality), stoi(tinternetHosts), stoi(tinternetUsers), stoi(tlaborForce), stod(tbirthLifeExpectancy) });
    }
    cout << fixed << setprecision(4);
    cout << "no. countries is: " << countCountries(countries) << endl;
    cout << "Largest country: " << largestCountryArea(countries) << endl;
    cout << "Smallest country: " << smallestCountryArea(countries) << endl;
    cout << "Avg size: " << avgCountrySize(countries) << endl;
    cout << "Most internet hosts: " << mostInternetHosts(countries) << endl;
    cout << "Most internet users: " << mostInternetUsers(countries) << endl;
    cout << "Highest birth rate: " << highestBirthRate(countries) << endl;
    cout << "Avg GDP: " << avgGDP(countries) << endl;
    cout << "Avg life expectancy: " << avgLifeExpectancy(countries) << endl;
    cout << "Highest life expectancy country: " << highestLifeExpCountry(countries) << endl;
    cout << "Avg debt external: " << avgExtDebt(countries) << endl;
    cout << "Smallest laborforce: " << smallestLabourforce(countries) << endl;
    cout << "Avg infant mortality: " << avgInfantMortality(countries) << endl;
    cout << "Lowest deathrate country: " << lowestDeathRateCountry(countries) << endl;
}
