//#include "stdafx.h"
#include <iomanip>
#include"Vehicle.h"

/*
Calculate the distance the car has run. If the distance is more than 20k km
then advice the rotation

@param distanceRun:  the distance the car has run from last rotation.
*/
const int DISTANCE_ROTATION_KM = 20000; // km
void Vehicle::checkTireRotation(int newOdometer){
	cout << "\nFor every 20,000 km, you need to rotate the tires." << endl;
	int distanceRun = newOdometer - m_odometer;
	cout << "Distance vehicle has run: " << distanceRun << " km." << endl;
	if (distanceRun >= DISTANCE_ROTATION_KM){
		cout << "Please rotate tires." << endl;
	}
	else{
		cout << "You still have " << DISTANCE_ROTATION_KM - distanceRun << " km before tire rotation." << endl;
		cout << "\nTires are good to go." << endl;
	}
}
/*
Print information of the car including make, model, year, odometer, and type
*/
string carType;
void Vehicle::getCarInformation(){
	int type = getType();
	if (getType() == 0){
		carType = "GAS";
	}
	else if (getType() == 1){
		carType = "DIESEL";
	}
	else {
		carType = "ELECTRIC";
	}
	cout << setw(13) << "Make: " << m_make << endl;
	cout << setw(13) << "Model: " << m_model << endl;
	cout << setw(13) << "Year: " << m_year << endl;
	cout << setw(13) << "Odometer: " << m_odometer << " km" << endl;
	cout << setw(13) << "Type: " << carType << endl;
}

