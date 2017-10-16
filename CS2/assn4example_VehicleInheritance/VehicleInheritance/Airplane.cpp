#include "Airplane.h"



Airplane::Airplane(double spd, size_t N) :Vehicle(spd), numWings(N)
{
	cout << "From Airplane class constructor." << endl;
}

void Airplane::describe() const
{
	cout << "I am an airplane. I fly in air." << endl;
}
Airplane::~Airplane()
{
	cout << "From airplane class destructor." << endl;
}
