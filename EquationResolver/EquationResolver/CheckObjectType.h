#pragma once

#include "EquationObject.h"

class CheckObjectType
{
public:
	enum ObjectType {
		AdditionSign = 20,
		SubstractionSign = 21,
		MultiplicationSign = 22,
		DivisionSign = 23,
		Comma = 10,
		Zero = 0,
		One = 1,
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Unknown = 42
	};

	CheckObjectType();
	~CheckObjectType();
	ObjectType checkObject(EquationObject *);
};

