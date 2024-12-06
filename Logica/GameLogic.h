// Logica/GameLogic.h
#pragma once
#include <conio.h> // Para detectar las teclas presionadas en sistemas Windows 
#include <vector>
#include <queue>
#include <utility>
#include "../Presentacion/GameUI.h"

using namespace std;

class GameLogic {
	public:
		void moverCursor(int& cursor, vector<string> opcionesMenu, GameUI::Tecla tecla);
		void moverCursor(pair<int, int>& cursor, int maxSIZE, GameUI::Tecla tecla);
};

class TableroDeJuego {
	private:
		vector<vector<int>> tablero;
		queue<pair<int, int>> movJugador1;
		queue<pair<int, int>> movJugador2;
		
		
	public:
		TableroDeJuego();
		void eliminarCasilla(int jugador);
		bool capturarCasilla(int jugador, const pair<int, int>& posicion);
		int comprobarVictoria() const;
		const vector<vector<int>>& getTablero() const;
		static const int SIZE = 3;
};