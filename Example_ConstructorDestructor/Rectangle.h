#pragma once
#include <iostream>
class Rectangle
{
private:
	double length;
	double width;
public:
	double getLength();
	double getWidth();
	double getArea();
	void setLength(double l);
	void setWidth(double w);
	Rectangle();
	Rectangle(double l, double w);
	~Rectangle();
};

