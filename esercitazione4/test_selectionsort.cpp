#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "sort.hpp"
#include "randfiller.h"

int main() {
    randfiller rf;

    // TEST 1: 100 vettori di interi casuali
    for (int t = 0; t < 100; t++) {
        std::vector<int> vec;
        int dim = rand() % 100 + 1;
        vec.resize(dim);
        rf.fill(vec, -100, 100);

        selection_sort(vec);

        if (!is_sorted(vec)) {
            std::cout << "Test fallito sul vettore " << t << std::endl;
            return EXIT_FAILURE;
        }
    }

    // TEST 2: vettore di stringhe
    std::vector<std::string> words = {"Angola","Germania","Estonia", "Macedonia","Zanzibar", "Bogotà", "Italia","Australia", "Regno Unito"};
    selection_sort(words);

    if (!is_sorted(words)) {
        std::cout << "Test fallito sulle stringhe" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}