#include <vector> 
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include "sort.hpp"
#include "randfiller.h"

/*Test Merge Sort*/
int main() {
    randfiller rf;
	/*Test su 1:100 vettori casuali*/
	for (int t = 0; t < 100; t++) {
		std::vector<int> vec;
		int dim = rand () %100 +1;
		vec.resize(dim);
		rf.fill(vec , -100 , 100);
		std::cout << "Test " << t << " dim=" << dim << std::endl;
		merge_sort(vec, 0 , vec.size()-1);

		if (!is_sorted(vec)) {
			std::cout <<"Test fallito sul vettore" << t << std::endl;
			return EXIT_FAILURE;
		}
	}

	/*Test su vettore di stringe*/
	std::vector<std::string> words = {"Angola","Germania","Estonia", "Macedonia","Zanzibar", "Bogotà", "Italia","Australia", "Regno Unito","Qatar" };
	std::cout << "Inizio stringhe" << std::endl;
	merge_sort(words, 0, words.size()-1);
	std::cout << "Fine stringhe" << std::endl;
	if (!is_sorted(words)) {
		std::cout << "Test fallito sulle stringhe" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
