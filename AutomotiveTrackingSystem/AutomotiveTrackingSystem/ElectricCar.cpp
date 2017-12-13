#include"ElectricCar.h"

/*
OVERRIDE: calculate the distance the car has run.
If the distance is at each 50k km, then advice the rotation
*/
const int RUNFLAT_TIRE_CYCLE = 50000;  // km
void ElectricCar::checkTireRotation(int newOdometer){
	cout << "\nRun Flat Tires for the ELECTRIC vehicle require tire rotation every 50000 km." << endl;
	int distanceRun = newOdometer - m_odometer;
	cout << "Distance run: " << distanceRun << " km." << endl;
	//if distance is less than 50000 km, then tires are good to go
	if (distanceRun < RUNFLAT_TIRE_CYCLE){
		cout << "You still have " << RUNFLAT_TIRE_CYCLE - distanceRun << " km before tire rotation." << endl;
		cout << "\nTires are good to go." << endl;
	}
	// other wise, calculate the remainder of each 50000, if remainder >= 0 then advice to rotate tires 
	else if (distanceRun % RUNFLAT_TIRE_CYCLE >= 0){
		cout << "Please rotate tires." << endl;
	}

}
/*
Calculate the distance the car has run.
If the distance is more than 400 km, then advice the recharge power
*/
const int DISTANCE_KM_POWER = 400; // km
void ElectricCar::checkChargePower(int newOdometer){
	cout << "\nELECTRIC vehicles requires the battery to be recharged every 400 km." << endl;
	int distanceRun = newOdometer - m_odometer;
	cout << "Distance run: " << distanceRun << " km." << endl;
	if (distanceRun >= DISTANCE_KM_POWER){
		cout << "Please recharge your vehicle." << endl;
	}
	else{
		cout << "You still have " << DISTANCE_KM_POWER - distanceRun << " km before the car needs to be recharged." << endl;
		cout << "Your vehicle is good to go." << endl;
	}
}
/*
get type Electric
*/
Vehicle::Type ElectricCar::getType(){
	return ELECTRIC;
}