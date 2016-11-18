
#include <string>
#include <iostream>
#include "EquationPicture.h"
#include "Resolver.h"

int main(int argc, char **argv)
{
	Resolver resolver; // Resolver is the main class. It will resolve the equation with a picture

	std::string picturePath = "";

	if (argc > 1) { // I check if a file/picture is given in parameter of the program...
		picturePath = argv[1];
	}
	else { // ... if not, i ask to write the path of a picture
		std::cout << "Enter a picture path for the EquationResolver : ";
		std::getline(std::cin, picturePath);
	}

	while (true) {
		std::cout << std::endl << "Opening file : " << picturePath << std::endl;

		EquationPicture *picture = new EquationPicture(picturePath); // EquationPicture is equivalent of cxImage from our class exercices (it's a home made class)
		std::string result = resolver.newEquation(picture); // I give the path of the picture to the resolver, and return a string of the result
		delete(picture);

		std::cout << "Result : " << result << std::endl;

		std::cout << std::endl << "=====================================================" << std::endl
			<< "Enter a picture path for the EquationResolver (exit for quit) : ";
		std::getline(std::cin, picturePath);
		if (picturePath == "exit")
			break;
	}
	std::cout << std::endl << "Goodbye !" << std::endl;
	system("pause");
	return 0;
}