#include "EquationObject.h"

EquationObject::EquationObject()
{
}

EquationObject::EquationObject(int width, int height)
{
	Mat image(width, height, CV_8UC3, Scalar(0, 0, 0));
	this->picture = image;
	this->width = width;
	this->height = height;
}

EquationObject::~EquationObject()
{
}

int EquationObject::getWidth()
{
	return this->width;
}

int EquationObject::getHeight()
{
	return this->height;
}

Color EquationObject::getColorAtIndex(int x, int y)
{
	if (x >= width || y >= height) {
		return Color();
	}
	Color color = this->picture.at<Vec3b>(Point(x, y));
	return color;
}

void EquationObject::setColorAtIndex(int x, int y, Color newColor)
{
	Vec3b color = this->picture.at<Vec3b>(Point(x, y));
	color[0] = newColor.getBlueColor();
	color[1] = newColor.getGreenColor();
	color[2] = newColor.getRedColor();
	this->picture.at<Vec3b>(Point(x, y)) = color;
}

