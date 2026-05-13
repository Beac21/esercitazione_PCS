#include "undirected_graph.hpp"
#include <iostream>

int main() {
    undirected_edge<int> arco_1(3,1);
    std::cout<<"From:"<<arco_1.from()<<std::endl;
    std::cout<<"To:" <<arco_1.to()<<std::endl;
    undirected_edge<int> arco_2(1,3);
    std::cout << "Arco 1: " << arco_1 << std::endl;
    std::cout << "Arco 2: " << arco_2 << std::endl;
    
    undirected_edge<int> arco_3 (2,3);
    undirected_edge<int> arco_4 (3,4);
    undirected_edge<int> arco_5 (5,4);
    undirected_edge<int> arco_6 (5,8);
    
    bool result= arco_1==arco_2;
    if (!result) {
        std::cout<<"Gli archi sono diversi" << " "<< arco_1<<" " << arco_2<<std::endl;
    }
    else {
        std::cout<<"Gli archi sono uguali" <<" " <<arco_1<<" " << arco_2<<std::endl;
    }
    //implemento ora il grafo
    undirected_graph<int> grafo1;  
    grafo1.add_edge(arco_1);       
    grafo1.add_edge(arco_2); 
    grafo1.add_edge(arco_3);
    grafo1.add_edge(arco_4);
    std::cout << "Vicini del nodo1 in grafo1: ";
    auto vicini = grafo1.neighbours(1);
    for (const auto & nodo : vicini) {
        std::cout << nodo << " ";
    }
    std::cout << std::endl;
    auto arco_trovato = grafo1.edge_at(0);
    std::cout << "Arco alla posizione 0: " <<arco_trovato << std::endl;


    undirected_graph<int> grafo2; 
    grafo2.add_edge(arco_3);
    grafo2.add_edge(arco_4);
    grafo2.add_edge(arco_5);
    grafo2.add_edge(arco_6);

    std::cout << "Archi grafo1: ";
    for (const auto& arco : grafo1.all_edges()) {
        std::cout << arco << " ";
    } std::cout << std::endl;


    std::cout << "Archi grafo2: ";
    for (const auto& arco : grafo2.all_edges()) {
        std::cout << arco << " ";
    } std::cout << std::endl;

    auto differenza = grafo1 - grafo2;
    auto diff_archi = differenza.all_edges();
    std::cout << "Archi del grafo1 non in grafo2: ";
    for (const auto & arco : diff_archi) {
        std::cout << arco << " ";
    }std::cout <<std::endl;

    std::cout << std::endl;
    int nodo_trovato = grafo2.edge_number(arco_5);
    std::cout << "Posizione di arco_5 in grafo2: " <<nodo_trovato << std::endl;


}

