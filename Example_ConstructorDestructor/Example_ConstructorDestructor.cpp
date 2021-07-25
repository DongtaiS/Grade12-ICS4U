#include <iostream>
#include "Rectangle.h"
using namespace std;

class Yard
{
private:
	int length, width;
public:
	Yard()
	{
		length = 0; width = 0;
	}
	void setLength(int len)
	{
		length = len;
	}
	void setWidth(int w)
	{
		width = w;
	}
};
int main()
{
	Yard yards[5];
	for (int i = 0; i < 5; i++)
	{
		int length, width;
		do
		{
			cout << "Enter the length of the yard" << endl;
			cin >> length;
			cout << "Enter the width of the yard" << endl;
			cin >> width;
		} while (length <= 0 || width <= 0);
		yards[i].setLength(length);
		yards[i].setWidth(width);
	}
}
