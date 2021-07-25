#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
struct TorontoData
{
    int finalPrice;
    int listPrice;
    int bedrooms;
    int bathrooms;
    int sqft;
    int parking;
    string type;
    string fullAddress;
};

int totalSold(vector<TorontoData> data)
{
    return data.size();
}

int countTriplex(vector<TorontoData> data)
{
    int count = 0;
    for (TorontoData unit : data)
    {
        if (unit.type == "Triplex")
        {
            count++;
        }
    }
    return count;
}

double avgFinalSemiDetached(vector<TorontoData> data)
{
    long double total = 0;
    int count = 0;
    for (TorontoData unit : data)
    {
        if (unit.type == "Semi-Detached")
        {
            total += unit.finalPrice;
            count++;
        }
    }
    return total / count;
}

int countLessThanList(vector<TorontoData> data)
{
    int count = 0;
    for (TorontoData unit : data)
    {
        if (unit.finalPrice < unit.listPrice)
        {
            count++;
        }
    }
    return count;
}

double avgFinalQueenswayAve(vector<TorontoData> data)
{
    long double total = 0;
    int count = 0;
    for (TorontoData unit : data)
    {
        if (unit.fullAddress.find("The Queensway Ave") != string::npos)
        {
            total += unit.finalPrice;
            count++;
        }
    }
    return total / count;
}

double avgSizeCoopApt(vector<TorontoData> data)
{
    double total = 0;
    int count = 0;
    for (TorontoData unit : data)
    {
        if (unit.type == "Co-Op Apt" && unit.sqft > 0)
        {
            total += unit.sqft;
            count++;
        }
    }
    return total / count;
}

string highestPriceAddress(vector<TorontoData> data)
{
    int max = 0;
    string result;
    for (TorontoData unit : data)
    {
        if (unit.finalPrice > max)
        {
            max = unit.finalPrice;
            result = unit.fullAddress;
        }
    }
    return result;
}

int countMoreThanOneMil(vector<TorontoData> data)
{
    int count = 0;
    for (TorontoData unit : data)
    {
        if (unit.finalPrice > 1000000)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    fstream TorontoRealEstate("TorontoRealEstate.csv");
    string line;
    vector<TorontoData> realEstateData;
    while (getline(TorontoRealEstate, line, '\n'))
    {
        stringstream lineStream(line);
        string finalPrice;
        string listPrice;
        string bedrooms;
        string bathrooms;
        string sqft;
        string parking;
        string type;
        string fullAddress;
        getline(lineStream, finalPrice, ',');
        getline(lineStream, listPrice, ',');
        getline(lineStream, bedrooms, ',');
        getline(lineStream, bathrooms, ',');
        getline(lineStream, sqft, ',');
        getline(lineStream, parking, ',');
        getline(lineStream, type, ',');
        getline(lineStream, fullAddress, ',');
        realEstateData.push_back({ stoi(finalPrice), stoi(listPrice), stoi(bedrooms), stoi(bathrooms), stoi(sqft), stoi(parking), type, fullAddress });
    }
    cout << fixed << setprecision(4);
    cout << "Total sold: " << totalSold(realEstateData) << endl;
    cout << "Triplexes: " << countTriplex(realEstateData) << endl;
    cout << "Avg final semi-detached: " << avgFinalSemiDetached(realEstateData) << endl;
    cout << "Sold for less than list price: " << countLessThanList(realEstateData) << endl;
    cout << "Avg final on the Queensway Ave: " << avgFinalQueenswayAve(realEstateData) << endl;
    cout << "Avg size of Coop Apts: " << avgSizeCoopApt(realEstateData) << endl;
    cout << "Address of most expensive unit: " << highestPriceAddress(realEstateData) << endl;
    cout << "Houses sold for more than $1 mil: " << countMoreThanOneMil(realEstateData) << endl;
}