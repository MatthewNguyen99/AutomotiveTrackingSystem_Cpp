#ifndef FUELVEHICLE_H
#define FUELVEHICLE_H

#include "Vehicle.h"


/*
Create an abstract class name FuelVehicle
that inherit Vehicle class
*/
class FuelVehicle : public Vehicle{
public:
	/*
	Construct FuelVehicle with make, model, year, odometer.
	*/
	FuelVehicle(string make, string model, int year, int odometer) :
		Vehicle(make, model, year, odometer)
	{}
	/*
	Method to advice whether or not the car needs to change oil.
	It is based on the odometer reading
	*/
	void checkOilChange(int newOdometer);
	/*
	Method to show the fuel types of the car. Types are GAS/DIESEL/ELECTRIC
	*/
	virtual void getFuelType() = 0;
};

#endif