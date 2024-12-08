// Datos/DataAccess.h
#pragma once
#include <vector>

using namespace std;


class DatosdeJuego{
	
	private:
		vector<int> resultados [3][3];
		
	public:
		DatosdeJuego();
		void guardarR(TableroDeJuego tablero, vector<int> resultados[][]);
		void crearF(vector<string> resultados);
		
};
