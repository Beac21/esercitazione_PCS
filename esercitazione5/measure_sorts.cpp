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
    //Creazione tabella di output
    std::cout << "dim\tbubble_sort\t\tinsertion_sort\t\tselection_sort\t\tmerge_sort\t\t quick_sort\t\t quick_sort_mod \t\t std::sort" << std::endl;

    for (int dim = 2; dim <= 2048; dim *= 2) {
        std::vector<std::vector<int>> vecs(100, std::vector<int>(dim));
        for (int i =0; i<100; i++) {
            rf.fill(vecs[i], -1000, 1000);
        }
    
    
        /*bubble_sort*/
        // copia vettori originali
        std::vector<std::vector<int>> vecs_bubble = vecs;
        // misura
        tc.tic();
        for (int i = 0; i<100; i++) {
            bubble_sort(vecs_bubble[i]);
        }
        double t_bubble = tc.toc()/100.0;

        /*insertion_sort*/
        // copia vettori originali
        std::vector<std::vector<int>> vecs_insertion = vecs;
        // misura
        tc.tic();
        for (int i = 0; i<100; i++) {
            insertion_sort(vecs_insertion[i]);
        }
        double t_insertion = tc.toc()/100.0;
        
        /*selection_sort*/
        // copia vettori originali
        std::vector<std::vector<int>> vecs_selection = vecs;
        // misura
        tc.tic();
        for (int i = 0; i<100; i++) {
            selection_sort(vecs_selection[i]);
        }
        double t_selection = tc.toc()/100.0;

        /*merge_sort*/
        // copia vettori originali
        std::vector<std::vector<int>> vecs_merge = vecs;
        // misura
        tc.tic();
        for (int i = 0; i<100; i++) {
            merge_sort(vecs_merge[i], 0 , vecs_merge[i].size()-1);
        }
        double t_merge = tc.toc()/100.0;

        /*quick_sort*/
        // copia vettori originali
        std::vector<std::vector<int>> vecs_quick = vecs;
        // misura
        tc.tic();
        for (int i = 0; i<100; i++) {
            quick_sort(vecs_quick[i], 0 , vecs_quick[i].size()-1);
        }
        double t_quick = tc.toc()/100.0;

        /*quick_sort_mod*/
        std::vector<std::vector<int>> vecs_mod = vecs;
        tc.tic();
        for (int i = 0; i < 100; i++) {
            quick_sort_mod(vecs_mod[i]);
        }
        double t_mod = tc.toc()/100.0;
        
        /*Uso std::sort*/ 
        std::vector<std::vector<int>> vecs_std = vecs; 
        tc.tic(); 
        for (int i =0; i<100; i++) {
            std::sort(vecs_std[i].begin(), vecs_std[i].end());
        }
        double t_std = tc.toc()/100.0;

        // stampa le righe 
        std::cout << dim << "\t" << t_bubble << "\t\t"<< t_insertion << "\t\t" << t_selection << "\t\t" << t_merge <<"\t\t" << t_quick << "\t\t"<<t_mod<< "\t\t"<< t_std <<std::endl;
        
        
    
    }
    return EXIT_SUCCESS;
}
