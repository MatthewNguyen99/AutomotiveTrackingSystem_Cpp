#include"DieselCar.h"

/*
Print the type of fuel
*/
void DieselCar::getFuelType(){
	cout << "Fuel type is DIESEL." << endl;
}
/*
Get type of fuel
*/
Vehicle::Type DieselCar::getType(){
	return DIESEL;
}