#pragma once

#include <iostream>

#include "EquationObject.h"

using namespace cv;

class EquationPicture : public EquationObject // cximage equivalent
{
public:
	EquationPicture(String);
	~EquationPicture();
};

