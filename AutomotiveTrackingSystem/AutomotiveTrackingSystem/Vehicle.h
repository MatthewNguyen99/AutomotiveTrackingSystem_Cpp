#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream> 
#include <string>

using namespace std;
/*
Create an abstract class named Vehicle
*/
class Vehicle{

protected:
	/*
	Creater variables make, model, year, odometer
	@param m_make is the vehicle's make
	@param m_model is the vehicle's model
	@param m_year is the vehicle's year
	@param m_odometer is the vehicle's odometer
	*/
	string m_make;
	string m_model;
	int m_year;
	int m_odometer;

	Vehicle() {}

public:
	/*
	Construct Vehicle with make, model, year, odometer.
	*/
	Vehicle(string make, string model, int year, int odometer) :
		m_make(make), m_model(model), m_year(year), m_odometer(odometer){}
	/*
	Create the enum of fuel types and electric type.
	*/
	enum Type {
		GAS,
		DIESEL,
		ELECTRIC
	};
	/*
	Get the Vehicle's make.
	@return make
	*/
	const string getMake() { return m_make; }
	/*
	Get the Vehicle's mode.
	@return model
	*/
	const string getModel() { return m_model; }
	/*
	Get the Vehicle's year.
	@return year
	*/
	int getYear() { return m_year; }
	/*
	Get the Vehicle's odometer.
	@return odometer
	*/
	int getOdometer() { return m_odometer; }
	/*
	Set the Vehicle's make.
	*/
	void setMake(string make) { m_make = make; }
	/*
	Set the Vehicle's model.
	*/
	void setModel(string model) { m_model = model; }
	/*
	Set the Vehicle's year.
	*/
	void setYear(int year) { m_year = year; }
	/*
	Set the Vehicle's odormeter.
	*/
	void setOdometer(int odormeter) { m_odometer = odormeter; }
	/*
	Virtual method to advice whether or not the tires need rotation
	according to distance the car had run
	*/
	virtual void checkTireRotation(int newOdometer);
	/*
	Virtual method to get the information of each car
	*/
	virtual void getCarInformation();
	/*
	Pure virtual method to get the fuel type of the car. Types are GAS/DIESEL/ELECTRIC
	*/
	virtual Type getType() = 0;
};



#endif