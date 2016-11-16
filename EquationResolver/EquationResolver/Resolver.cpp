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
	this->cutter = new EquationPictureCutter(picture);
	double resultNb = this->resolve();

	std::ostringstream strs;
	strs << resultNb;
	std::string result = strs.str();

	delete (this->cutter);
	return result;
}

double Resolver::resolve() {
	EquationObject* object = NULL;
	double nb1 = 0;
	double nb2 = 0;
	CheckObjectType::ObjectType operation = CheckObjectType::Unknown;

	while ((object = this->cutter->getNextEquationObject()) != NULL) {
		std::string nb = "";
		
		CheckObjectType::ObjectType typeObject = this->compare.checkObject(object);

		if (typeObject >= 20 && typeObject != CheckObjectType::Unknown) {
			operation = typeObject;
		}
		else if (typeObject != CheckObjectType::Unknown) {
			nb += typeObject;
		}

		if (nb1 <= 0) {
			nb1 = atof(nb.c_str());
		}
		else if (nb2 <= 0) {
			nb2 = atof(nb.c_str());
			if (operation == CheckObjectType::AdditionSign) {
				nb1 = makeAddition(nb1, nb2);
			}
			else if (operation == CheckObjectType::DivisionSign) {
				nb1 = makeDivision(nb1, nb2);
			}
			else if (operation == CheckObjectType::MultiplicationSign) {
				nb1 = makeMultiplication(nb1, nb2);
			}
			else if (operation == CheckObjectType::SubstractionSign) {
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
