#pragma once
#include "Vehicles.h"

class Lorry : public Vehicles
{
private:
	int maxLoad;
public:
	Lorry();
	Lorry(std::string regNumIn, int maxLoadIn, float lengthIn, int vehicleTypeIn);
	~Lorry();
	void setMaxLoad(int maxLoadIn);
	int getMaxLoad();
	virtual void showReport(); // virtual function to access derived class variables
};