#include "Resolver.h"

Resolver::Resolver(bool withLog)
{
	this->withLog = withLog;
}

Resolver::Resolver()
{
	this->withLog = false;
}


Resolver::~Resolver()
{
}

std::string Resolver::newEquation(EquationPicture *picture)
{
	this->cutter = new EquationPictureCutter(picture); // EquationPictureCutter is the class for separate every object of the picture/equation.
														// A picture with "1 + 2 + 3 + 4" will be transform into several picture "1", "+", "2", "+", "3", "+", "4"
	double resultNb = this->resolve(); // Main function

	/* ========= Convertion double to string ================== */
	std::ostringstream strs;
	strs << resultNb;
	std::string result = strs.str();
	/* ======================================================================== */

	delete (this->cutter);
	return result;
}

double Resolver::resolve() {
	EquationObject* object = NULL;
	double nb1 = 0;
	double nb2 = 0;
	CheckObjectType::ObjectType operation = CheckObjectType::Unknown;

	while ((object = this->cutter->getNextEquationObject()) != NULL) { // I call getNextEquationObject which give me the next object of the equation ("1", next "+", next "2", .....)
		std::string nb = "";
		
		CheckObjectType::ObjectType typeObject = this->compare.checkObject(object); // Compare is the class used for compare each object and determined what is it

		if (typeObject >= 20 && typeObject != CheckObjectType::Unknown) { // If it's a "+" or "-" or "*" or "/"
			operation = typeObject;
		}
		else if (typeObject != CheckObjectType::Unknown) { // If it's a "1" or "2" or "3" or ....... or "8" or "9" or "0"
			nb += typeObject;
		}

		if (nb1 <= 0) {
			nb1 = atof(nb.c_str());
		}
		else if (nb2 <= 0) { // If i have 2 numbers, then i make calcul
			nb2 = atof(nb.c_str());
			if (operation == CheckObjectType::AdditionSign) { // Addition
				nb1 = makeAddition(nb1, nb2);
			}
			else if (operation == CheckObjectType::DivisionSign) { // Division
				nb1 = makeDivision(nb1, nb2);
			}
			else if (operation == CheckObjectType::MultiplicationSign) { // Multiplication
				nb1 = makeMultiplication(nb1, nb2);
			}
			else if (operation == CheckObjectType::SubstractionSign) { //Substraction
				nb1 = makeSubstraction(nb1, nb2);
			}
		}
	}
	return nb1;
}

double Resolver::makeAddition(double nb1, double nb2)
{
	return nb1 + nb2;
}

double Resolver::makeSubstraction(double nb1, double nb2)
{
	return nb1 - nb2;
}

double Resolver::makeDivision(double nb1, double nb2)
{
	if (nb1 > 0 && nb2 > 0) {
		return nb1 / nb2;
	}
	return 0.0;
}

double Resolver::makeMultiplication(double nb1, double nb2)
{
	return nb1 * nb2;
}
