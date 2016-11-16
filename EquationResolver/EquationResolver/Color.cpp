#include "Color.h"

Color::Color(Vec3b color)
{
	this->blue = color[0];
	this->green = color[1];
	this->red = color[2];
}

Color::Color()
{
	this->blue = 0;
	this->green = 0;
	this->red = 0;
}


Color::~Color()
{
}

short Color::getRedColor()
{
	return this->red;
}

short Color::getBlueColor()
{
	return this->blue;
}

short Color::getGreenColor()
{
	return this->green;
}
