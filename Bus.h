#pragma once
#include "Vehicles.h"

class Bus : public Vehicles
{
private:
	int psvNumber; // public service vehicle number
	int maxPassengers;
public:
	Bus();
	Bus(std::string regNumIn, int psvNumberIn, int maxPassengersIn, float lengthIn, int vehicleTypeIn);
	~Bus();
	void setPsvNumber(int psvNumberIn);
	int getPsvNumber();
	void setMaxPassengers(int maxPassengersIn);
	int getMaxPassengers();
	virtual void showReport(); // virtual function to access derived class variables
};