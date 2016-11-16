#pragma once
#include <list>
#include "EquationPicture.h"

class EquationPictureCutter
{
private:
	std::list<EquationObject*> objects;
	int currentObject;

public:
	EquationPictureCutter(EquationPicture *);
	~EquationPictureCutter();
	EquationObject* getNextEquationObject();
};

