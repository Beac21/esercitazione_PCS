using namespace std;
#include <fstream>
#include <string>
#include <iostream>


int main(void) {
	string filename = "input_es1.txt";
	ifstream ifs(filename);
	if ( ifs.is_open() ) { // Check if file successfully opened
		string citta;
		double temp[4]; //array fisso di 4 valori
		double somma =0;
		double media=0; 
		double x=4;
		
		while( ifs >> citta >> temp[0] >> temp[1] >> temp[2] >> temp[3] ) {
			somma =0; 
			for (int i=0; i<4; i++) {
				somma += +temp[i];
			}
			media=somma/x;
			cout << citta <<" "<< media << "\n";
			} 
	}
	else {
		cout << "Errore in apertura del file\n" ;
		return 1;
		}
	
	return 0;
}