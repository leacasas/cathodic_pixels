#include "Manager.h"

float Manager::getRedVal()
{
	return this->rr;
}

float Manager::getGreenVal()
{
	return this->gg;
}

float Manager::getBlueVal()
{
	return this->bb;
}

void Manager::setRedVal(float val)
{
	this->rr = val;
}

void Manager::setGreenVal(float val)
{
	this->gg = val;
}

void Manager::setBlueVal(float val)
{
	this->bb = val;
}
