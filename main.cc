#include <string>
#include <iostream>
#include <random>
#include <fstream>

#include "direction.hh"
#include "objet.hh"
#include "plateau.hh"


int main() {
	//std::random_device rd;
	//std::mt19937 mt(rd());
	//std::uniform_int_distribution<int> distribution(0, 3);

	std::string data[] = {
		#include "data.txt"
	};
	//for (auto s : data) std::cout << s << std::endl;
	
	//Directions test = Directions(distribution(mt));
	//std::cout << "direction: " << test << std::endl;
	

	Plateau* plateau = new Plateau();
	std::cout << "size: " << plateau->getLengthFile("data.txt") << std::endl;
}
