// Datos/DataAccess.h
#include "DataAccess.h"
#include <fstream>

#define A 3

using namespace std;

DatosdeJuego::DatosdeJuego() : r(A, vector<int>(A, 0)) {}

void DatosdeJuego::definirV(vector<vector<int>> r){
	
	for(int i = 0; i < A; i++){
		
		r.resize(A, vector<int>(A));
		
	}
	
}

void DatosdeJuego::guardarR(TableroDeJuego& tablero){
	//Guarda los valores del tablero de la ultima partida
	
	vector<vector<int>> r = tablero.getTablero();
	
};

void DatosdeJuego::crearF(vector<vector<int>> r){
	//Escribe los resultados en un .txt
	
	int n = 3;
	
	ofstream hojaResult("Datos de partida.txt");
	
	hojaResult << "Partida Guardada:" << endl;
	
	for (int i = 0; i < n; i++){
		
		for (int j = 0; j < n; j++){
			
			switch(r[i][j]){
				case 1: hojaResult << "X" << "\t";
						break;
				case 2: hojaResult << "O" << "\t";
						break;
				default: hojaResult << "-" << "\t";
						break;
			}	
			
		}
		
		hojaResult << endl;
		
	}
	
	hojaResult.close();
	
};