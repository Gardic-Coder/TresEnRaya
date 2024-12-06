#include "GameLogic.h"

using namespace std;

void GameLogic::moverCursor(int& cursor, vector<string> opcionesMenu, GameUI::Tecla tecla) {
	switch (tecla) { 
		case GameUI::ARRIBA: 
			if (cursor > 0) cursor--; 
			break; 
		case GameUI::ABAJO: 
			if (cursor < opcionesMenu.size() - 1) cursor++; 
			break; 
		default: 
			break; 
	}
}

void GameLogic::moverCursor(pair<int, int>& cursor, int maxSIZE, GameUI::Tecla tecla) {
	switch (tecla) { 
		case GameUI::ARRIBA:
			if (cursor.first > 0) --cursor.first;
			break;
		case GameUI::ABAJO:
			if (cursor.first < maxSIZE - 1) ++cursor.first;
			break; 
		case GameUI::IZQUIERDA: 
			if (cursor.second > 0) --cursor.second;
			break; 
		case GameUI::DERECHA: 
			if (cursor.second < maxSIZE - 1) ++cursor.second;
			break; 
		default: 
			break; 
	}
}