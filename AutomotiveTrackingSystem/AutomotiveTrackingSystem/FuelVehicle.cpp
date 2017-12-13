#include "FuelVehicle.h"

/*
Calculate the distance the car has run.
If the distance is more than 5000 km, then advice the oil change
*/
const int DISTANCE_OIL_LIFESPAN = 5000; // km
void FuelVehicle::checkOilChange(int newOdometer){
	cout << "\nFor every 5,000 km, you need to change the engine oil." << endl;
	int distanceRun = newOdometer - m_odometer;
	cout << "Distance vehicle has run: " << distanceRun << " km." << endl;
	if (distanceRun >= DISTANCE_OIL_LIFESPAN){
		cout << "Please change engine oil. " << endl;
	}
	else{
		cout << "You still have " << DISTANCE_OIL_LIFESPAN - distanceRun << " km before oil change." << endl;
		cout << "Your vehicle is good to go." << endl;
	}
}

