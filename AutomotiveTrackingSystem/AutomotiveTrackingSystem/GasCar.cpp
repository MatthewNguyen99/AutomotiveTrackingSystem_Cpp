#include "GasCar.h"


/*
Print the type of fuel
*/
void GasCar::getFuelType(){
	cout << "Fuel type is GASOLINE." << endl;
}
/*
Get type of fuel
*/
Vehicle::Type GasCar::getType(){
	return GAS;
}

