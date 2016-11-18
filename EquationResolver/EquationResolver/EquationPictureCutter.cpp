#include "EquationPictureCutter.h"

EquationPictureCutter::EquationPictureCutter(EquationPicture *picture) // cut the entire picture into small ones
{
	this->currentObject = 0;
	/* cut picture 

	=== EXAMPLE ===

	(picture = "1 + 2 + 3")

	objectCut1 = cutMyPicture(1, picture); --> want cut the "1"
	objectCut2 = cutMyPicture(2, picture); --> want cut the "+"
	objectCut3 = cutMyPicture(3, picture); --> want cut the "2"
	[...]
	======= cutMyPicture cut the object number given in parameter for example (or another way, as you want) =======

	this->objects.push_back(objectCut1); --> "1"
	this->objects.push_back(objectCut2); --> "+"
	this->objects.push_back(objectCut3); --> "2"
	[...]

	================

	WARNING : to create a new EquationObject, i don't know if my constructor is functionnal, i didn't test it.
	Maybe we have to read opencv documentation for learn how create a new image (MAT)

	*/
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
