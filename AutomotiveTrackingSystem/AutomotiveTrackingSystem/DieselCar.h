#ifndef DIESELCAR_H
#define DIESELCAR_H

#include "Vehicle.h"
#include "FuelVehicle.h"

/*
Create a subclass name DieselCar that inherit FuelVehicle class
*/
class DieselCar : public FuelVehicle{
public:
	/*
	Construct DieselCar with make, model, year, odometer.
	*/
	DieselCar(string make, string model, int year, int odometer) :
		FuelVehicle(make, model, year, odometer)
	{}
	/*
	Method to show the fuel types of the car. Types are GAS/DIESEL/ELECTRIC
	*/
	void getFuelType();
	/*
	Method to get the fuel type of the car. Types are GAS/DIESEL/ELECTRIC
	*/
	Type getType();
};

#endif