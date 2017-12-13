#ifndef GASCAR_H
#define GASCAR_H

#include "FuelVehicle.h"
#include "Vehicle.h"

/*
Create a subclass name GasCar that inherit FuelVehicle class
*/
class GasCar : public FuelVehicle{
public:
	/*
	Construct GasCar with make, model, year, odometer.
	*/
	GasCar(string make, string model, int year, int odometer) :
		FuelVehicle(make, model, year, odometer)
	{}
	/*
	Method to show the fuel type of the car
	*/
	void getFuelType();
	/*
	Method to get the fuel type of the car. Types are GAS/DIESEL/ELECTRIC
	*/
	Type getType();
};

#endif

