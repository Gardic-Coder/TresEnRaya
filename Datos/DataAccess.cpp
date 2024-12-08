// Datos/DataAccess.h
#include "DataAccess.h"
#include <fstream.h>

using namespace std;

void DataAccess::guardarR(TableroDeJuego tablero, vector<int> resultados[][] ){
	//Guarda los valores del tablero de la ultima partida
	
	vector<int> resultados [s][s];
	
	for (int i = 0; i <= s; i++){
		
		for (int j = 0; j <= s; j++ ){
			
			tablero[i][j] = resultados[i][j];
		}
		
	}
	
	return resultados;
};

void DataAccess::crearF(vector<int> resultados[][]){
	//Escribe los resultados en un .txt
	
	int n = 3;
	
	ofstream hojaResult("Datos de partida.txt");
	
	hojaResult.open();
	
	hojaResult << "Resultados del juego:" << endl;
	
	for (int i = 0; i < n; i++){
		
		for (int j = 0; j < n; j++){
			
			switch(resultados[i][j]){
				case 1: hojaResult << "X" << "\n";
						break;
				case 2: hojaResult << "O" << "\n";
						break;
				default: hojaResult << "-" << "\n";
						break;
			}	
			
		}
		
		hojaResult << endl;
		
	}
	
	hojaResult.close();
	
	return 0;
	
};