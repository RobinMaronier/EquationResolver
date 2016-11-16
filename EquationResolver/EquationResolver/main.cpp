
#include <string>
#include <iostream>
#include "EquationPicture.h"
#include "Resolver.h"

int main(int argc, char **argv)
{
	Resolver resolver;
	std::string picturePath = "";

	if (argc > 1) {
		picturePath = argv[1];
	}
	else {
		std::cout << "Enter a picture path for the EquationResolver : ";
		std::getline(std::cin, picturePath);
	}

	while (true) {
		std::cout << std::endl << "Opening file : " << picturePath << std::endl;

		EquationPicture *picture = new EquationPicture(picturePath);
		std::string result = resolver.newEquation(picture);
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