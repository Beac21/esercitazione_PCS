#include <vector>
#include <iostream>
#include <algorithm>    // std::sort
#include <cstdlib>
#include "sort.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main() {
    randfiller rf;
    timecounter tc;

    std::cout << "dim\t\tbubble_sort\t\tinsertion_sort\t\tselection_sort\t\tstd::sort" << std::endl;

    for (int dim = 4; dim <= 8192; dim *= 2) {

        // vettore base casuale
        std::vector<int> v1;
        v1.resize(dim);
        rf.fill(v1, -1000, 1000);

        // copie identiche per confronto equo
        std::vector<int> v2 = v1;
        std::vector<int> v3 = v1;
        std::vector<int> v4 = v1;

        // misura bubble_sort
        tc.tic();
        bubble_sort(v1);
        double t_bubble = tc.toc();

        // misura insertion_sort
        tc.tic();
        insertion_sort(v2);
        double t_insertion = tc.toc();

        // misura selection_sort
        tc.tic();
        selection_sort(v3);
        double t_selection = tc.toc();

        // misura std::sort
        tc.tic();
        std::sort(v4.begin(), v4.end());
        double t_std = tc.toc();

        // stampa riga della tabella
        std::cout << dim        << "\t\t"
                  << t_bubble    << "\t\t"
                  << t_insertion << "\t\t"
                  << t_selection << "\t\t"
                  << t_std
                  << " s" << std::endl;
    }

    return EXIT_SUCCESS;
}