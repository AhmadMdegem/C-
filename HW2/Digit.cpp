#include "Digit.h"

Digit::Digit() :value(0)
{
}

bool Digit::chekeDigit(int value1)
{

	return value == value1;
}

int Digit::getDigit()
{
	return value;
}

void Digit::setDigit(int value1)
{
	value = value1;
}