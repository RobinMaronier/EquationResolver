#include "EquationPicture.h"

EquationPicture::EquationPicture(String picturePath) : EquationObject()
{
	this->picture = imread(picturePath);
	if (!picture.data) {
		std::cout << "ERROR: image path doesn't exist !" << std::endl;
	}
	else {
		this->width = picture.cols;
		this->height = picture.rows;
	}
}


EquationPicture::~EquationPicture()
{
}
