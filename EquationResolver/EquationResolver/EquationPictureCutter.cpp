#include "EquationPictureCutter.h"

EquationPictureCutter::EquationPictureCutter(EquationPicture *picture)
{
	this->currentObject = 0;
	/* cut picture*/
}


EquationPictureCutter::~EquationPictureCutter()
{
	std::list<EquationObject*>::iterator it = this->objects.begin();
	for (it; it != this->objects.end(); ++it) {
		delete (*it); /* verify */
	}
}

EquationObject* EquationPictureCutter::getNextEquationObject()
{
	if (this->objects.size() <= this->currentObject + 1) {
		return NULL;
	}
	this->currentObject++;
	std::list<EquationObject*>::iterator it = this->objects.begin();
	std::advance(it, this->currentObject);
	return *it; /* verify */
}
