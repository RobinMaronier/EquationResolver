#pragma once

#include "opencv2\core\core.hpp"

using namespace cv;

class Color // RGBQUAD equivalent
{
private:
	short red;
	short green;
	short blue;

public:
	Color(Vec3b);
	Color();
	~Color();
	short getRedColor();
	short getBlueColor();
	short getGreenColor();
};

