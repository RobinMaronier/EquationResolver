#pragma once

#include "opencv2\highgui\highgui.hpp"
#include "opencv2\core\core.hpp"

#include "Color.h"

using namespace cv;

class EquationObject // cximage equivalent
{
protected:
	EquationObject();
	Mat picture;
	int width;
	int height;

public:
	EquationObject(int, int);
	~EquationObject();
	int getWidth();
	int getHeight();
	Color getColorAtIndex(int, int);
	void setColorAtIndex(int, int, Color);
};

