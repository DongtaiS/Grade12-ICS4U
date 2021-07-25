#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct RealEstateData
{
    string street;
    string region;
    int zipcode;
    int bedrooms;
    int bathrooms;
    int squareFt;
    int price;
};

int highestPrice(vector<RealEstateData> data)
{
    int highest = 0;
    for (auto estate : data)
    {
        highest = max(highest, estate.price);
    }
    return highest;
}

int avgPriceSacramento(vector<RealEstateData> data)
{
    int count = 0;
    int total = 0;
    for (auto estate : data)
    {
        if (estate.region == "SACRAMENTO")
        {
            count++;
            total += estate.price;
        }
    }
    return total / count;
}

int lowestPrice(vector<RealEstateData> data)
{
    int lowest = INT_MAX;
    for (auto estate : data)
    {
        lowest = min(lowest, estate.price);
    }
    return lowest;
}

int avgSize(vector<RealEstateData> data)
{
    int total = 0;
    for (auto estate : data)
    {
        total += estate.squareFt;
    }
    return total / data.size();
}

int avgBedroomsSacramento(vector<RealEstateData> data)
{
    int total = 0;
    int count = 0;
    for (auto estate : data)
    {
        if (estate.region == "SACRAMENTO")
        {
            count++;
            total += estate.bedrooms;
        }
    }
    return total / count;
}

int avgBathrooms(vector<RealEstateData> data)
{
    int total = 0;
    for (auto estate : data)
    {
        total += estate.bathrooms;
    }
    return total / data.size();
}

int numHousesRanchoCordova(vector<RealEstateData> data)
{
    int count = 0;
    for (auto estate : data)
    {
        if (estate.region == "RANCHO CORDOVA")
        {
            count++;
        }
    }
    return count;
}

int numHousesRoseville(vector<RealEstateData> data)
{
    int count = 0;
    for (auto estate : data)
    {
        if (estate.region == "ROSEVILLE")
        {
            count++;
        }
    }
    return count;
}

int numHousesCrystalwoodLicoln(vector<RealEstateData> data)
{
    int count = 0;
    for (auto estate : data)
    {
        if (estate.region == "LINCOLN" && estate.street.find("CRYSTALWOOD CIR") != string::npos)
        {
            count++;
        }
    }
    return count;
}


int main()
{
    fstream realEstateFile("SacramentoRealEstate.csv");
    string line;
    vector<RealEstateData> sacramentoData;
    while (getline(realEstateFile, line, '\n'))
    {
        stringstream lineStream(line);
        string tstreet;
        string tregion;
        string tzip;
        string tbed;
        string tbath;
        string tsqrft;
        string tprice;
        getline(lineStream, tstreet, ',');
        getline(lineStream, tregion, ',');
        getline(lineStream, tzip, ',');
        getline(lineStream, tbed, ',');
        getline(lineStream, tbath, ',');
        getline(lineStream, tsqrft, ',');
        getline(lineStream, tprice, ',');
        sacramentoData.push_back({ tstreet, tregion, stoi(tzip), stoi(tbed), stoi(tbath), stoi(tsqrft), stoi(tprice) });
    }
    cout << "Highest price overall: " << highestPrice(sacramentoData) << endl;
    cout << "Avg price in Sacramento: " << avgPriceSacramento(sacramentoData) << endl;
    cout << "Lowest price overall: " << lowestPrice(sacramentoData) << endl;
    cout << "Avg house size overall: " << avgSize(sacramentoData) << endl;
    cout << "Avg bedrooms in Sacramento: " << avgBedroomsSacramento(sacramentoData) << endl;
    cout << "Avg bathrooms: " << avgBathrooms(sacramentoData) << endl;
    cout << "No. houses sold in Rancho Cordova: " << numHousesRanchoCordova(sacramentoData) << endl;
    cout << "No. houses sold in Roseville: " << numHousesRoseville(sacramentoData) << endl;
    cout << "No. houses sold on Crystalwood Cir in Lincoln: " << numHousesCrystalwoodLicoln(sacramentoData) << endl;
}
