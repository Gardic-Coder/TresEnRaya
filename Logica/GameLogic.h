// Logica/GameLogic.h
#pragma once
#include <array>
#include <string>
#include <algorithm>
#include <conio.h> // Para detectar las teclas presionadas en sistemas Windows 
//#include <iostream>
#include <vector>
#include "../Presentacion/GameUI.h"

using namespace std;

class GameLogic {
	public:
		void moverCursor(int& cursor, vector<string> opcionesMenu, GameUI::Tecla tecla);
		//void moverCursor(int& fila, int& columna, Tecla tecla);
};