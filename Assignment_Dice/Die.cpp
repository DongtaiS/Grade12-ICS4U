#include "Die.h"
using namespace std;
Die::Die(int s)
{
	sides = s;
	srand(time(0));
	roll();
}
int Die::getValue()
{
	return value;
}
void Die::setSides(int s)
{
	sides = s;
}
void Die::roll()
{
	value = rand() % sides + 1;
}