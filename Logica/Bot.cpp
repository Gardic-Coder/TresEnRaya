#include "GameLogic.h"
#include <limits> // para numeric_limits
#include <algorithm> // para random_shuffle

using namespace std;

int Bot::evaluar(const vector<vector<int>>& tablero, int jugador) {
    // Evaluar filas, columnas y diagonales
    for (int fila = 0; fila < 3; ++fila) {
        if (tablero[fila][0] == jugador && tablero[fila][1] == jugador && tablero[fila][2] == jugador)
            return +10;
        if (tablero[fila][0] != jugador && tablero[fila][1] != jugador && tablero[fila][2] != jugador && tablero[fila][0] != 0)
            return -10;
    }

    for (int col = 0; col < 3; ++col) {
        if (tablero[0][col] == jugador && tablero[1][col] == jugador && tablero[2][col] == jugador)
            return +10;
        if (tablero[0][col] != jugador && tablero[1][col] != jugador && tablero[2][col] != jugador && tablero[0][col] != 0)
            return -10;
    }

    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return +10;
    if (tablero[0][0] != jugador && tablero[1][1] != jugador && tablero[2][2] != jugador && tablero[0][0] != 0)
        return -10;

    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return +10;
    if (tablero[0][2] != jugador && tablero[1][1] != jugador && tablero[2][0] != jugador && tablero[0][2] != 0)
        return -10;

    return 0;
}

bool Bot::hayMovimientosDisponibles(const vector<vector<int>>& tablero) {
    for (int fila = 0; fila < 3; ++fila)
        for (int col = 0; col < 3; ++col)
            if (tablero[fila][col] == 0)
                return true;
    return false;
}

int Bot::minimax(vector<vector<int>>& tablero, int profundidad, bool esMaximizador, int jugador) {
    int puntuacion = evaluar(tablero, jugador);

    if (puntuacion == 10)
        return puntuacion - profundidad;
    if (puntuacion == -10)
        return puntuacion + profundidad;

    if (!hayMovimientosDisponibles(tablero))
        return 0;

    if (esMaximizador) {
        int mejor = numeric_limits<int>::min();

        for (int fila = 0; fila < 3; ++fila) {
            for (int col = 0; col < 3; ++col) {
                if (tablero[fila][col] == 0) {
                    tablero[fila][col] = jugador;
                    mejor = max(mejor, minimax(tablero, profundidad + 1, !esMaximizador, jugador));
                    tablero[fila][col] = 0;
                }
            }
        }
        return mejor;
    } else { 
		int mejor = numeric_limits<int>::max(); 
		int oponente = (jugador == 1) ? 2 : 1; 
		for (int fila = 0; fila < 3; ++fila) { 
			for (int col = 0; col < 3; ++col) { 
				if (tablero[fila][col] == 0) { 
				tablero[fila][col] = oponente; 
				mejor = min(mejor, minimax(tablero, profundidad + 1, true, jugador)); 
				tablero[fila][col] = 0; 
				} 
			} 
		} 
	return mejor;
	}
}

pair<int, int> Bot::hacerMovimiento(const vector<vector<int>>& tablero, int jugador) {
    int mejorValor = numeric_limits<int>::min();
    vector<pair<int, int>> mejoresMovimientos;
    pair<int, int> mejorMovimiento = {-1, -1};

    for (int fila = 0; fila < 3; ++fila) {
        for (int col = 0; col < 3; ++col) {
            if (tablero[fila][col] == 0) {
                vector<vector<int>> tableroTemp = tablero;
                tableroTemp[fila][col] = jugador;

                int valorMovimiento = minimax(tableroTemp, 0, false, jugador);

                if (valorMovimiento > mejorValor) {
                	mejorValor = valorMovimiento; 
					mejoresMovimientos.clear(); 
					mejoresMovimientos.push_back({fila, col});
                } else if(valorMovimiento == mejorValor) {
                	mejoresMovimientos.push_back({fila, col});
				}
            }
        }
    }
    // Anadir aleatoriedad 
	random_shuffle(mejoresMovimientos.begin(), mejoresMovimientos.end());
    return mejoresMovimientos[0];
}
