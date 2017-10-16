#include "Vehicle.h"



Vehicle::Vehicle(double spd):speed(spd)
{
	cout << "From vehicle class constructor." << endl;
}

double Vehicle::getSpeed() const
{
	return speed;
}
void Vehicle::describe() const
{
	cout << "I am a general vehicle." << endl;
}
Vehicle::~Vehicle()
{
	cout << "From vehicle class destructor." << endl;
}
