#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	double speed;
public:
	Vehicle(double spd = 0.0);
	double getSpeed() const;
	virtual void describe() const;
	~Vehicle();
};

