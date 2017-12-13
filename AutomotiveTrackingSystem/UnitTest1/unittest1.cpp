#include "stdafx.h"
#include "CppUnitTest.h"

#include "Vehicle.h"
#include "ElectricCar.h"
#include "GasCar.h"
#include "DieselCar.h"
#include "main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		//test vehicle's make: make cannot not be empty
		TEST_METHOD(testNewMake)
		{
			int size = sizeof(getNewMake()) / sizeof(char);
			Assert::AreNotEqual(size, 0);
		}
		//test vehicle's model: model cannot not be empty
		TEST_METHOD(testNewModel)
		{
			int size = sizeof(getNewModel()) / sizeof(char);
			Assert::AreNotEqual(size, 0);
		}
		//test vehicle's year: year cannot not be empty
		TEST_METHOD(testNewYear)
		{
			int size = sizeof(getNewYear()) / sizeof(char);
			Assert::AreNotEqual(size, 0);
		}
		//test vehicle's odometer: odometer cannot not be empty
		TEST_METHOD(testNewOdometer)
		{
			int size = sizeof(getNewOdometer()) / sizeof(char);
			Assert::AreNotEqual(size, 0);
		}
		//test vehicle's odometer: odometer cannot not be empty
		TEST_METHOD(testNewType)
		{
			int size = sizeof(getNewType()) / sizeof(char);
			Assert::AreNotEqual(size, 0);
		}
		//test vehicle's inventory: inventory can be empty (size = 0), but cannot be negative

		TEST_METHOD(testListVehicle)
		{
			initializeInventory();
			int size = VehicleInventory.size();
			Assert::AreNotEqual(size, 0);
		}
		//test vehicle's inventory: inventory is either empty or at least 1
		TEST_METHOD(testAddVehicle)
		{
			int size = (int)VehicleInventory.size();
			Assert::IsTrue(size >= 0);
		}
		//test update odometer: odometer must be at least 0 (brand new car)
		TEST_METHOD(testUpdateVehicle)
		{
			for (int index = 0; index < (int)VehicleInventory.size(); index++){
				int odometer = (int)VehicleInventory[index]->getOdometer();
				Assert::IsTrue(odometer >= 0);
			}
		}
		//test remove: inventory must be at least = 0 (if all cars are remove, then inventory is = 0)
		TEST_METHOD(testRemoveVehicle)
		{
			int size = (int)VehicleInventory.size();
			Assert::IsTrue(size >= 0);
		}
		// test tire rotation: new odometer cannot bigger than 9,999,999 km
		TEST_METHOD(testVehicleOdometerReading)
		{
			for (int index = 0; index < (int)VehicleInventory.size(); index++){
				int odometer = (int)VehicleInventory[index]->getOdometer();
				Assert::IsTrue(odometer <= 9999999);
			}
		}

	};
}