#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
struct Car
{
    string carMake;
    string carModel;
    int yearModel;
    double cost;
};
void printTable(vector<Car> cars)
{
    cout << left << setw(15) << "Make";
    cout << left << setw(15) << "Model";
    cout << left << setw(8) << "Year";
    cout << left << setw(15) << "Cost" << endl << endl;
    int yearTotal = 0;
    double costTotal = 0;
    for (auto car : cars)
    {
        cout << left << setw(15) << car.carMake;
        cout << left << setw(15) << car.carModel;
        cout << left << setw(8) << car.yearModel;
        cout << right << "$" << setw(8) << car.cost << endl;
        yearTotal += car.yearModel;
        costTotal += car.cost;
    }
    cout << "Avg year: " << yearTotal / cars.size() << "\nAvg cost: $" << costTotal / cars.size() << endl;
}
int main()
{
    vector<Car> cars {
        {"Ford", "Taurus", 1997, 21000.0},
        {"Honda", "Accord", 1992, 11000.0},
        {"Lamborghini", "Countach", 1997, 200000.0}
    };
    printTable(cars);
    string newMake;
    string newModel;
    int newYear;
    double newCost;
    cout << "Enter the information of another car \nMake ";
    cars.push_back(Car{ "", "", 0, 0});
    getline(cin, cars[cars.size() - 1].carMake);
    cout << "Model ";
    getline(cin, cars[cars.size() - 1].carModel);
    cout << "Year ";
    cin >> cars[cars.size() - 1].yearModel;
    cout << "Cost ";
    cin >> cars[cars.size() - 1].cost;
    cout << endl;
    printTable(cars);
}