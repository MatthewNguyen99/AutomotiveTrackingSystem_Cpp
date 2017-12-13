#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Vehicle.h"

/*
Create a subclass name ElectricCar that inherit Vehicle class
*/
class ElectricCar : public Vehicle{
public:
	/*
	Construct ElectricCar with make, model, year, odometer.
	*/
	ElectricCar(string make, string model, int year, int odometer) :
		Vehicle(make, model, year, odometer)
	{}
	/*
	Method to advice whether or not the car needs to rotate tires.
	It is based on the odometer reading
	*/
	void checkTireRotation(int newOdometer);
	/*
	Method to advice whether or not the car needs to recharge power.
	It is based on the odometer reading
	*/
	void checkChargePower(int newOdometer);
	/*
	Method to get the fuel type of the car. Types are GAS/DIESEL/ELECTRIC
	*/
	Type getType();
};

#endif
