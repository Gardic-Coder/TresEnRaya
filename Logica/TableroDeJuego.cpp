#include "GameLogic.h"

using namespace std;

TableroDeJuego::TableroDeJuego() : tablero(SIZE, vector<int>(SIZE, 0)) {}

bool TableroDeJuego::capturarCasilla(int jugador, const pair<int, int>& posicion) {
	//auto[fila, columna] = posicion;
	int fila = posicion.first;
	int columna = posicion.second;
	if(tablero[fila][columna] != 0) {
		return false;
	}
	bool x = (jugador == 1 && movJugador1.size() == 3) || (jugador == 2 && movJugador2.size() == 3);
	if(x) {
		eliminarCasilla(jugador);
	}
	tablero[fila][columna] = jugador;
	if(jugador == 1) {
		movJugador1.push(posicion);
	} else {
		movJugador2.push(posicion);
	}
	return true;
}

void TableroDeJuego::eliminarCasilla(int jugador) {
	if(jugador == 1 && !movJugador1.empty()) { 
		int fila = movJugador1.front().first;
		int columna = movJugador1.front().second;
		//auto[fila, columna] = movJugador1.front(); 
		movJugador1.pop(); 
		tablero[fila][columna] = 0; 
	} else if(jugador == 2 && !movJugador2.empty()) {
		int fila = movJugador2.front().first;
		int columna = movJugador2.front().second; 
		//auto [fila, columna] = movJugador2.front(); 
		movJugador2.pop(); 
		tablero[fila][columna] = 0; 
	}
}

int TableroDeJuego::comprobarVictoria() const { 
	for(int i = 0; i < SIZE; ++i) { 
		// Verificar filas 
		if(tablero[i][0] != 0 && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) { 
			return tablero[i][0]; 
		} 
		// Verificar columnas 
		if(tablero[0][i] != 0 && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) { 
			return tablero[0][i]; 
		} 
	} 
	// Verificar diagonales 
	if(tablero[0][0] != 0 && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) { 
		return tablero[0][0]; 
	} 
	if(tablero[0][2] != 0 && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) { 
		return tablero[0][2]; 
	} 
	return 0; 
}

const vector<vector<int>>& TableroDeJuego::getTablero() const { 
	return tablero; 
}
