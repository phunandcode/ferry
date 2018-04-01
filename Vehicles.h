#pragma once
#include <string>

class Vehicles
{
private:
	float length;
	std::string registerationNumber;
public:
	Vehicles();
	~Vehicles();
	int vehicleType;
	float getLength();
	std::string getRegisterationNumber();
	void setLength(float lengthIn);
	void setRegisterationNumber(std::string regNumIn);
	virtual void showReport(); // virtual function to access derived class variables
};