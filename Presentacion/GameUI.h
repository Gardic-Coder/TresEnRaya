// Presentacion/GameUI.h
#pragma once
#include <vector>
#include <conio.h>
#include <string>
#include <iostream>
//#include "../Logica/GameLogic.h"

using namespace std;

class GameUI {
public:
	enum Tecla { ARRIBA, ABAJO, IZQUIERDA, DERECHA, ENTER, ESCAPE, G, OTRA };
	
    void mostrarMenu(int cursor, vector<string> opcionesMenu);
    Tecla getTecla();
    void acercaDelJuego();
	void ayuda();
};
