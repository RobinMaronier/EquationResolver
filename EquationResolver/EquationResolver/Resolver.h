#pragma once

#include "opencv2\highgui\highgui.hpp"
#include "opencv2\core\core.hpp"

#include "EquationPicture.h"
#include "EquationPictureCutter.h"
#include "CheckObjectType.h"

class Resolver // Main class, resolver
{
public:
	Resolver(bool); // not important
	Resolver();
	~Resolver();
	std::string newEquation(EquationPicture *); // first call

private:

	EquationPictureCutter* cutter;
	CheckObjectType compare;
	bool withLog;

	double resolve();
	double makeAddition(double, double);
	double makeSubstraction(double, double);
	double makeDivision(double, double);
	double makeMultiplication(double, double);
};