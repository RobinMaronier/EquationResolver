#pragma once

#include <iostream>

#include "EquationObject.h"

using namespace cv;

class EquationPicture : public EquationObject
{
public:
	EquationPicture(String);
	~EquationPicture();
};

