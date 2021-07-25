#pragma once
#include <iostream>

using namespace std;
class Employee
{
private:
	string name;
	int IDNumber;
	string department;
	string position;
public:
	Employee(string n, int ID, string dept, string pos)
	{
		name = n;
		IDNumber = ID;
		department = dept;
		position = pos;
	}
	Employee(string n, int ID)
	{
		name = n;
		IDNumber = ID;
		department = "";
		position = "";
	}
	string getName()
	{
		return name;
	}
	void setName(string n)
	{
		name = n;
	}
	int getIDNumber()
	{
		return IDNumber;
	}
	void setIDNumber(int ID)
	{
		IDNumber = ID;
	}
	string getDepartment()
	{
		return department;
	}
	void setDepartment(string dept)
	{
		department = dept;
	}
	string getPosition()
	{
		return position;
	}
	void setPosition(string pos)
	{
		position = pos;
	}
};

