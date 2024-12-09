// Datos/DataAccess.h
#include "DataAccess.h"

using namespace std;

DataAccess::DataAccess() : tablero(TableroDeJuego::SIZE, vector<int>(TableroDeJuego::SIZE, 0)), modoDeJuego(0) {}

DataAccess::DataAccess(TableroDeJuego tableroDeJuego, int modo) {
	modoDeJuego = modo;
	tablero = tableroDeJuego.getTablero();
	movJug1 = tableroDeJuego.getMovJugador1();
	movJug2 = tableroDeJuego.getMovJugador2();
}

void DataAccess::guardarPartida() {
	ofstream archivo("Datos de partida.txt");
	
	if(modoDeJuego == 1) {
		archivo << "jugVsJug" << endl;
	} else if(modoDeJuego == 2){
		archivo << "jugVsBot" << endl;
	}
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			switch(tablero[i][j]){
				case 1: archivo << "X" << "\t";
						break;
				case 2: archivo << "O" << "\t";
						break;
				default: archivo << "-" << "\t";
						break;
			}	
		}
		archivo << endl;
	}
	pair<int, int> movimiento;
	archivo << "Movimientos Jugador 1:" << endl; 
	while (!movJug1.empty()) { 
		movimiento = movJug1.front(); 
		archivo << "(" << movimiento.first << ", " << movimiento.second << ")" << endl;
		movJug1.pop();
	} 
	
	archivo << "Movimientos Jugador 2:" << endl;
	while (!movJug2.empty()) { 
		movimiento = movJug2.front(); 
		archivo << "(" << movimiento.first << ", " << movimiento.second << ")" << endl; 
		movJug2.pop(); 
	}
	
	archivo.close();
}

void DataAccess::cargarPartida() {
	ifstream archivo("Datos de partida.txt");
	string linea;
	
	// Limpiar las colas antes de cargar nuevos datos 
	while (!movJug1.empty()) movJug1.pop(); 
	while (!movJug2.empty()) movJug2.pop();
	
	getline(archivo, linea);
	
	if(linea == "jugVsJug") {
		modoDeJuego = 1;
	} else if(linea == "jugVsBot") {
		modoDeJuego = 2;
	} else {
		modoDeJuego = -1;
	}
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j <3; j++) {
			char c;
			archivo >> c;
			
			// Convertir los caracteres a los valores correspondientes 
			if (c == 'X') { 
				tablero[i][j] = 1; 
			} else if (c == 'O') { 
				tablero[i][j] = 2; 
			} else if (c == '-') { 
				tablero[i][j] = 0;
			}
			// Descartar el tabulador si no es el último elemento de la línea 
			if (j < 2) { 
				archivo.ignore(); 
			}
		}
	}
	
	// Leer los movimientos del archivo 
	bool leerJugador1 = true; 
	while (getline(archivo, linea)) { 
		if (linea.find("Movimientos Jugador 1:") != string::npos) { 
			leerJugador1 = true; 
		} else if (linea.find("Movimientos Jugador 2:") != string::npos) { 
			leerJugador1 = false; 
		} else if (!linea.empty() && linea.front() == '(' && linea.back() == ')') { 
			int fila, columna; 
			char coma; 
			stringstream ss(linea); 
			ss.ignore(1, '('); // Ignorar el '(' 
			ss >> fila >> coma >> columna; // Leer los valores 
			if (leerJugador1) { 
				movJug1.emplace(fila, columna); 
			} else { 
				movJug2.emplace(fila, columna); 
			} 
		} 
	}
	
	archivo.close();
	ofstream borrar("Datos de partida.txt", ios::trunc); 
	if (borrar.is_open()) { 
		// El archivo ha sido truncado, por lo tanto, está vacío 
	}
	borrar.close();
}

const vector<vector<int>>& DataAccess::getTablero() const { 
	return tablero; 
}

const queue<pair<int, int>>& DataAccess::getMovJug1() const { 
	return movJug1; 
} 

const queue<pair<int, int>>& DataAccess::getMovJug2() const { 
	return movJug2; 
}

const int& DataAccess::getModoDeJuego() const{
	return modoDeJuego;
}
