#pragma once

#include "opencv2\highgui\highgui.hpp"
#include "opencv2\core\core.hpp"

#include "EquationPicture.h"
#include "EquationPictureCutter.h"
#include "CheckObjectType.h"

class Resolver
{
public:
	Resolver(bool);
	Resolver();
	~Resolver();
	std::string newEquation(EquationPicture *);

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