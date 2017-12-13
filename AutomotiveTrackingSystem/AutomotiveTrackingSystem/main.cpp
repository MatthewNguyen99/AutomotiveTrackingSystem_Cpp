#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <assert.h>

#include "Vehicle.h"
#include "ElectricCar.h"
#include "GasCar.h"
#include "DieselCar.h"

using namespace std;

vector<Vehicle*> VehicleInventory;
/*
Function prototype
*/

void initializeInventory();
bool isNumerical(string str);
string getNewMake();
string getNewModel();
string getNewYear();
string getNewOdometer();
string getNewType();
string selectCar(vector<Vehicle*>vehicleList);
string getNewOdometerReading(Vehicle* vehicle);
void listVehicles();
void addVehicle(string make, string model, string year, string odometer, string type);
void updateVehicle();
void removeVehicle();
void tireRotation();
void oilChange();
void recharge();
void menu();

/*
This is the main method
*/
int main(){
	//Create initial cars
	initializeInventory();

	//Start the menu and ask th e user to choose List/Add/Update/Delete
	while (1){
		menu();
		string inputStr;
		getline(cin, inputStr);
		//Ask for input again if the input is not a digit or not within 0 - 7
		while (!isNumerical(inputStr) || inputStr.length() == 0 || inputStr.length() > 7 || stoi(inputStr) < 0 || stoi(inputStr) > 7){
			cout << "\nPlease select 1 to 7 or press 0 to quit." << endl;
			getline(cin, inputStr);
		}
		//Get all input make, model, year, odometer, type
		//Check user input 0-1-2-3-4. 
		//Function will be called based on the user input
		//If input is not from 0 to 4, then ask again
		string make, model, year, odometer, type;
		switch (stoi(inputStr)){
		case 0:
			exit(0);
			break;
		case 1:
			listVehicles();
			break;
		case 2:
			make = getNewMake();
			model = getNewModel();
			year = getNewYear();
			odometer = getNewOdometer();
			type = getNewType();
			addVehicle(make, model, year, odometer, type);
			break;
		case 3:
			updateVehicle();
			break;
		case 4:
			removeVehicle();
			break;
		case 5:
			tireRotation();
			break;
		case 6:
			oilChange();
			break;
		case 7:
			recharge();
			break;
		default:
			break;
		}
	}
	return 0;
}
/*
Create new vehicles and add them into inventory
*/
void initializeInventory(){
	ElectricCar* electricTestla3 = new ElectricCar("Tesla", "Model3", 2017, 1000);
	GasCar* gasFord = new GasCar("Ford", "Escape", 2000, 100000);
	DieselCar* dieselChevy = new DieselCar("Chevy", "Silverado", 2010, 95000);
	GasCar* gasHonda = new GasCar("Honda", "Civic", 2005, 175000);
	GasCar* gasNissan = new GasCar("Nissan", "Altima", 1999, 200000);
	ElectricCar* electricTestla4 = new ElectricCar("Tesla", "Model4", 2017, 4200);
	ElectricCar* electricTestla5 = new ElectricCar("Tesla", "Model5", 2007, 200);
	GasCar* gasBMW = new GasCar("BMW", "3Series", 2017, 100);

	//Add cars to inventory
	VehicleInventory.push_back(electricTestla3);
	VehicleInventory.push_back(gasFord);
	VehicleInventory.push_back(dieselChevy);
	VehicleInventory.push_back(gasHonda);
	VehicleInventory.push_back(gasNissan);
	VehicleInventory.push_back(electricTestla4);
	VehicleInventory.push_back(electricTestla5);
	VehicleInventory.push_back(gasBMW);
}
/*
Return true if the input string is numerical
*/
bool isNumerical(string str){
	for (char letter : str){
		if (!isdigit(letter)){
			return false;
		}
	}
	return true;
}
/*
Retrieve the user input on the vehicle's make.
If the input is blank, then the input will be requested again.
*/
string getNewMake(){
	cout << "\nEnter new make: " << endl;
	string make;
	getline(cin, make);
	while (make.length() == 0){
		cout << "\nMake cannot be blank." << endl;
		getline(cin, make);
	}
	return make;
}
/*
Retrieve the user input on the vehicle's model.
If the input is blank, then the input will be requested again.
*/
string getNewModel(){
	cout << "\nEnter new model: " << endl;
	string model;
	getline(cin, model);
	while (model.length() == 0){
		cout << "\nModel cannot be blank." << endl;
		getline(cin, model);
	}
	return model;
}
/*
Retrieve the user input on the vehicle's year.
Year must be 4 digits.  Example: 1999, 2009, etc.
If input doesn't have 4 digits, then the input will be requested again.
*/
string  getNewYear(){
	cout << "\nEnter new year: " << endl;
	string year;
	getline(cin, year);
	while (!isNumerical(year) || year.length() != 4){
		cout << "\nOnly 4 digit year allowed:" << endl;
		getline(cin, year);
	}
	return year;
}
/*
Retrieve the user input on the vehicle's odometer.
Odometer must not contain any strings.
If the input contains a non-numerical character, then the input will be requested again.
*/
string getNewOdometer(){
	cout << "\nEnter new odometer: " << endl;
	string odometer;
	getline(cin, odometer);
	while (!isNumerical(odometer) || odometer.length() == 0 || odometer.length() > 7){
		cout << "\nOnly numbers (less than 7 digits) allowed:" << endl;
		getline(cin, odometer);
	}
	return odometer;
}
/*
Retrieve the user input on the vehicle's type.
Type must be between 0 - 2.
If the input isn't within 0 - 2, then the input will be requested again.
*/
string getNewType(){
	cout << "\nChoose type of fuel: \n0. GAS\n1. DIESEL\n2. ELECTRIC" << endl;
	string type;
	getline(cin, type);
	while (!isNumerical(type) || type.length() == 0 || type.length() > 7 || stoi(type) < 0 || stoi(type) > 2){
		cout << "\nPlease enter 0 or 1 or 2:" << endl;
		getline(cin, type);
	}
	return type;
}
/*
Retrieve the selected vehicle from the user input.
If the input isn't a digit or not within the size of the vehicle list, then the input will be requested again.
*/
string selectCar(vector<Vehicle*>vehicleList){
	cout << "\nPlease select car (from 1 to " << vehicleList.size() << "): " << endl;
	string indexStr;
	getline(cin, indexStr);
	while (!isNumerical(indexStr) || indexStr.length() == 0 || indexStr.length() > 7 || stoi(indexStr) < 1 || stoi(indexStr) > (int)vehicleList.size()){
		cout << "\nPlease enter from 1 to " << vehicleList.size() << ": " << endl;
		getline(cin, indexStr);
	}
	return indexStr;
}
/*
Request input for the new Odometer reading.
(The new odometer reading will be used for calculation of oil change, tire rotation, and power recharged)
*/
string getNewOdometerReading(Vehicle* vehicle){
	//Ask for the new odometer in this vehicle, then calculate how far the car has run
	string newOdometer = getNewOdometer();
	int previousOdometer = vehicle->getOdometer();
	//If distance run is negative, ask for new input
	while (stoi(newOdometer) - previousOdometer < 0){
		cout << "\nInvalid.  New odometer is less than previous odometer." << endl;
		newOdometer = getNewOdometer();
	}
	cout << "\nNew odometer reading: " << newOdometer << " km." << endl;
	cout << "Previous odometer: " << previousOdometer << " km." << endl;
	return newOdometer;
}
/*
List all of the vehicle in the inventory along with its information.
*/
void listVehicles(){
	if (VehicleInventory.size() == 0){
		cout << "\nInventory is empty.  Please add car by enter 2. " << endl;
	}
	for (int index = 0; index < (int)VehicleInventory.size(); index++){
		cout << "\n" << index + 1 << ". " << endl;
		VehicleInventory[index]->getCarInformation();
	}
	//assert
	assert(VehicleInventory.size() >= 0);
}
/*
Create and add a new vehicle in the vehicle inventory.
*/
void addVehicle(string make, string model, string year, string odometer, string type){
	Vehicle *vehicle;
	switch (stoi(type)){
	case 0:
		vehicle = new GasCar(make, model, stoi(year), stoi(odometer));
		break;
	case 1:
		vehicle = new DieselCar(make, model, stoi(year), stoi(odometer));
		break;
	case 2:
		vehicle = new ElectricCar(make, model, stoi(year), stoi(odometer));
		break;
	default:
		break;
	}
	//Add to inventory and show new vehicle:
	VehicleInventory.push_back(vehicle);
	listVehicles();
	cout << "\nNew vehicle added at index " << VehicleInventory.size() << ".\n" << endl;

	assert(make.length() != 0);					// make cannot be empty
	assert(model.length() != 0);				// model cannot be empty
	assert(year.length() == 4);					// year must be 4 digits
	assert(odometer.length() != 0);				// odometer cannot be empty
	assert(stoi(odometer) >= 0);				// odometer must be positive
	assert(stoi(type) >= 0 || stoi(type) <= 2); // type must be between 0 and 2
}
/*
Updates an existing vehicle.
Users are only allowed to update the odometer.
If the inventory is empty, then this method will return along with a message.
*/
void updateVehicle(){
	if (VehicleInventory.size() == 0){
		cout << "\nInventory is empty, cannot delete or update.  Please add car by entering 2." << endl;
		return;
	}
	listVehicles();
	//Get the information of selected car
	int index = stoi(selectCar(VehicleInventory));
	cout << "\nUpdate this vehicle:" << endl;
	VehicleInventory[index - 1]->getCarInformation();

	cout << "\nYou can only update the odometer." << endl;
	string newOdometer = getNewOdometer();
	//Inform user that only odometer can be updated.  New odometer cannot be less than the current one.
	while (stoi(newOdometer) < VehicleInventory[index - 1]->getOdometer()){
		cout << "\nInvalid. It is illegal to lower your odometer." << endl;
		newOdometer = getNewOdometer();
	}
	//Set new odometer to the selected car
	VehicleInventory[index - 1]->setOdometer(stoi(newOdometer));
	cout << "\nOdometer has been updated." << endl;
	VehicleInventory[index - 1]->getCarInformation();

	assert(stoi(newOdometer) >= VehicleInventory[index - 1]->getOdometer()); //make sure new odometer >= current odometer
}
/*
Remove selected vehicle from inventory.
If the inventory is empty, then this method will return along with a message.

*/
void removeVehicle(){
	if (VehicleInventory.size() == 0){
		cout << "\nInventory is empty, cannot delete or update.  Please add car by enter 2." << endl;
		return;
	}
	listVehicles();
	//Get the information of selected car
	int index = stoi(selectCar(VehicleInventory));

	Vehicle *vehicle = VehicleInventory[index - 1];
	cout << "\nVehicle removed:" << endl;
	vehicle->getCarInformation();
	VehicleInventory.erase(VehicleInventory.begin() + (index - 1));

	delete vehicle;

	//assert
	assert(VehicleInventory.size() >= 0);  // inventory (vector size) must be >= 0
}
/*
Check if the tires need rotation.  The decision is based on the distance the car has run.
*/
void tireRotation(){
	listVehicles();
	//Select car from the list
	int indexCar = stoi(selectCar(VehicleInventory));
	cout << "\nCheck tire rotation for: " << endl;
	Vehicle *selectedCar = VehicleInventory[indexCar - 1];
	selectedCar->getCarInformation();

	//Ask for the new odometer in this vehicle, then calculate how far the car has run
	string newOdometer = getNewOdometerReading(selectedCar);

	//Call method in Vehicle.cpp to check rotation
	VehicleInventory[indexCar - 1]->checkTireRotation(stoi(newOdometer));

	assert(stoi(newOdometer) > 0);        // odometer is at least 0 km
	assert(stoi(newOdometer) <= 9999999); // max odometer is 7 digits
}
/*
Check if the car requires an oil change.  The decision is based on the distance the car has run.
*/
void oilChange(){
	vector<Vehicle*> fuelCarInventory;
	//Filter GAS and DIESEL vehicles.  The types for GAS is 0, DIESEL is 1;
	//Add only fuel vehicles to the fuelCarInventory
	for (int index = 0, indexOfFuelCar = 1; index < (int)VehicleInventory.size(); index++){
		if (VehicleInventory[index]->getType() == 0 || VehicleInventory[index]->getType() == 1){
			cout << "\n" << indexOfFuelCar++ << ". " << endl;
			//Cast the cars in vehicleInventory to FuelVehicle
			Vehicle* currentVehicle = VehicleInventory[index];
			//Add to new vector of fuel cars
			fuelCarInventory.push_back(currentVehicle);
			//now print the information
			currentVehicle->getCarInformation();
		}
	}
	//Select car from the list
	int indexCar = stoi(selectCar(fuelCarInventory));
	FuelVehicle* selectedCar = static_cast<FuelVehicle*>(fuelCarInventory[indexCar - 1]);
	cout << "\nCheck oil change for: " << endl;
	selectedCar->getCarInformation();

	//Ask for the new odometer in this vehicle, then calculate how far the car has run
	string newOdometer = getNewOdometerReading(selectedCar);
	//Call method in Vehicle.cpp to check oil
	selectedCar->checkOilChange(stoi(newOdometer));

	assert(stoi(newOdometer) > 0);        // odometer is at least 0 km
	assert(stoi(newOdometer) <= 9999999); // max odometer is 7 digits
}

/*
Check if the vehicle requires a battery recharge.
*/
void recharge(){
	vector<Vehicle*> electricCarInventory;
	//Filter ELECTRIC vehicles.  The types for ELECTRIC is 2
	//Add only ELECTRIC vehicles to the electricCarInventory
	for (int index = 0, indexOfFuelCar = 1; index < (int)VehicleInventory.size(); index++){
		if (VehicleInventory[index]->getType() == 2){
			cout << "\n" << indexOfFuelCar++ << ". " << endl;
			//Cast the cars in vehicleInventory to FuelVehicle
			Vehicle* currentVehicle = VehicleInventory[index];
			//Add to new vector of fuel cars
			electricCarInventory.push_back(currentVehicle);
			//now print the information
			currentVehicle->getCarInformation();
		}
	}

	//Select car from the list
	int indexCar = stoi(selectCar(electricCarInventory));
	ElectricCar* selectedCar = static_cast<ElectricCar*>(electricCarInventory[indexCar - 1]);
	cout << "\nCheck power recharge for: " << endl;
	selectedCar->getCarInformation();

	//Ask for the new odometer in this vehicle, then calculate how far the car has run
	string newOdometer = getNewOdometerReading(selectedCar);

	//Call method in Vehicle.cpp to check oil
	selectedCar->checkChargePower(stoi(newOdometer));

	assert(stoi(newOdometer) > 0);        // odometer is at least 0 km
	assert(stoi(newOdometer) <= 9999999); // max odometer is 7 digits
}
/*
Show menu
*/
void menu(){
	cout << "\n*******************************\n"
		<< "*                             *"
		<< "\nPlease select option (0 to 7):\n"
		<< "   0. Quit.\n"
		<< "   1. List inventory.\n"
		<< "   2. Add vehicle.\n"
		<< "   3. Update vehicle\n"
		<< "   4. Remove vehicle\n"
		<< "   5. Tire Rotation\n"
		<< "   6. Oil Change\n"
		<< "   7. Recharge\n"
		<< "*                             *"
		<< "\n*******************************" << endl;
}
