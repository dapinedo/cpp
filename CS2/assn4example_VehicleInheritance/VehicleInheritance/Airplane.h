#pragma once
#include "Vehicle.h"
class Airplane : public Vehicle
{
protected:
	size_t numWings;
public:
	Airplane(double spd = 0.0, size_t N=1);
	void describe() const;
	~Airplane();
};

