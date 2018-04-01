#pragma once
#include "Lorry.h"

class ArticulatedLorry : public Lorry
{
private:
	float cabLength;
	float trailerLength;
public:
	ArticulatedLorry();
	ArticulatedLorry(std::string regNumIn, float cabLengthIn, float trailerLengthIn, float lengthIn, int vehicleTypeIn);
	~ArticulatedLorry();
	void setCabLength(float cabLengthIn);
	float getCabLength();
	void setTrailerLength(float trailerLengthIn);
	float getTrailerLength();
	virtual void showReport(); // virtual function to access derived class variables
};