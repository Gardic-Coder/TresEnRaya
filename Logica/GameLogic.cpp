#include "GameLogic.h"

using namespace std;

void GameLogic::moverCursor(int& cursor, vector<string> opcionesMenu, GameUI::Tecla tecla) {
	switch (tecla) { 
		case GameUI::ARRIBA: 
			if (cursor > 0) cursor--; 
			break; 
		case GameUI::ABAJO: 
			if (cursor < opcionesMenu.size()) cursor++; 
			break; 
		default: 
			break; 
	}
}