#pragma once
#include "Vehicles.h"

class Car : public Vehicles
{
private:
	int seats;
public:
	Car();
	Car(std::string regNumIn, int seatsIn, float lengthIn, int vehicleTypeIn);
	~Car();
	int getSeats();
	void setSeats(int seatsIn);
	virtual void showReport(); // virtual function to access derived class variables
};