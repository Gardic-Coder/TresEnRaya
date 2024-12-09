// Datos/DataAccess.h

#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
//#include <iostream>

using namespace std;

class DataAccess {
	private:
		vector<vector<int>> tablero;
		int modoDeJuego;
		queue<pair<int, int>> movJug1;
		queue<pair<int, int>> movJug2;
	
	public:
		DataAccess();
		DataAccess(TableroDeJuego tableroDeJuego, int modo);
		void guardarPartida();
		void cargarPartida();
		const vector<vector<int>>& getTablero() const;
		const queue<pair<int, int>>& getMovJug1() const;
		const queue<pair<int, int>>& getMovJug2() const;
		const int& getModoDeJuego() const;
};
