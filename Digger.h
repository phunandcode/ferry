#pragma once
#include "Vehicles.h"

class Digger : public Vehicles
{
private:
	int trackCount;
public:
	Digger();
	Digger(std::string regNumIn, int trackCountIn, float lengthIn, int vehicleTypeIn);
	~Digger();
	void setTrackCount(int trackCountIn);
	int getTrackCount();
	virtual void showReport(); // virtual function to access derived class variables
};