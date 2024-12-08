// Datos/DataAccess.h
#include <vector>
#include "../Logica/GameLogic.h"

using namespace std;

class DatosdeJuego{
	
	private:
		vector<vector<int>> r;
		
		
	public:
		DatosdeJuego();
		void definirV(vector<vector<int>> r);
		void guardarR(TableroDeJuego& tablero);
		void crearF(vector<vector<int>> r);
		
};
