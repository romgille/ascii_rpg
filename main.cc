#include <string>
#include <iostream>
#include <random>
#include "direction.hh"

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
}
