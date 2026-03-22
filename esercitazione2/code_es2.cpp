#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cerrno>
#include <cfenv>
#include <cmath>


int main() {
	static const int N=10;
	double ad[N]={10, 1, 2,3,4,5,6,7,8,9};
	double max = *std::max_element(ad,ad+N);	
	std::cout<< "Il massimo è:"<< max <<"\n";
	double min = *std::min_element(ad,ad+N);
	std::cout << "Il minimo è:" << min << "\n";
	double somma =0;
	double media =0; 
	for (int i=0; i<N; i++) {
		somma += ad[i];
		}
	media = somma/N;
	std::cout << "La media è:" << media<< "\n";
	
	double somma_diff =0; 
	double varianza =0; 
	
	for (int i=0; i<N; i++) {
		somma_diff +=( std::pow((ad[i] -media), 2));
		
	}
	varianza = somma_diff/N; 
	double dev_std= std::sqrt( varianza);
	std::cout << "La deviazione standard  è:" << dev_std<< "\n";
	return 0;
}
	