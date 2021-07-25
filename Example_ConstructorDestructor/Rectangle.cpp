#include "Rectangle.h"
using namespace std;
double Rectangle::getLength()
{
	return length;
}
double Rectangle::getWidth()
{
	return width;
}
double Rectangle::getArea()
{
	return length * width;
}
void Rectangle::setLength(double l)
{
	length = l;
}
void Rectangle::setWidth(double w)
{
	width = w;
}
Rectangle::Rectangle()
{
}
Rectangle::Rectangle(double l, double w)
{
	length = l;
	width = w;
}
Rectangle::~Rectangle()
{
	cout << "asdf";
}