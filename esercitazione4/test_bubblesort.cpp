#include <vector> 
#include <string>
#include <iostream>
#include <cstdlib>
#include "sort.hpp"
#include "randfiller.h"
/*Test Bubble Sort*/
int main() {
	randfiller rf;
	/*Test su 1:100 vettori casuali*/
	for (int t = 0; t < 100; t++) {
		std::vector<int> vec;
		int dim = rand () %100 +1;
		vec.resize(dim);
		rf.fill(vec , -1000 , 1000);
		
		bubble_sort(vec);

		if (!is_sorted(vec)) {
			std::cout <<"Test fallito sul vettore" << t << std::endl;
			return EXIT_FAILURE;
		}
	}

	/*Test su vettore di stringe*/
	std::vector<std::string> words = {"Angola","Germania","Estonia", "Macedonia","Zanzibar", "Bogotà", "Italia","Australia", "Regno Unito" };
	bubble_sort(words);
	if (!is_sorted(words)) {
		std::cout << "Test fallito sulle stringhe" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}