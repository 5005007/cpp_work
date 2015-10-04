#include <iostream>
#include <ctime>
#include "Header.h"

int main(){
	std::srand(std::time(0));
	for (int i = 0; i < targetVector.size(); i++) {
		targetVector[i] = std::rand() % 100 + 1;
	}

	for (int i = 0; i < targetVector.size(); i++) {
		std::cout << targetVector[i] << ' ';
	}
	std::cout << "\nTo continue, press any key";
	getchar();
	return 0;
}