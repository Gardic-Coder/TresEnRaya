#include <iostream>
#include <vector>
#include "Logica/GameLogic.h"
#include "Presentacion/GameUI.h"

using namespace std;

GameUI gameUI;
GameLogic gameLogic;
GameUI::Tecla tecla;

vector<string> opcionesMenuPrincipal = { // Aca se guardan las cadenas de texto utilizadas en el menu principal.
	"INICIAR JUEGO",
	"CARGAR JUEGO",
	"ACERCA DEL JUEGO",
	"AYUDA",
	"SALIR"
};

vector<string> opcionesSubMenu = {
	"JUGADOR VS JUGADOR",
	"JUGADOR VS BOT",
	"BOT VS BOT"
};

int menu(vector<string> opciones);

int main() {
	bool salir = false;
	int seleccion;

	do {
		seleccion = menu(opcionesMenuPrincipal);
		system("cls");
		switch(seleccion) {
			case 0: {
				seleccion = menu(opcionesSubMenu);
				switch(seleccion) {
					case 0: {
						
						break;
					}
					case 1: {
						
						break;
					}
					case 2: {
						
						break;
					}
				}
				break;
			}
			case 1: {
				
				break;
			}
			case 2: {
				gameUI.acercaDelJuego();
				break;
			}
			case 3: {
				gameUI.ayuda();
				break;
			}
			case 4: {
				salir = !salir;
				break;
			}
		}
	} while(!salir);


	return 0;
}

int menu(vector<string> opciones) {
	int cursor;
	while(true){
		gameUI.mostrarMenu(cursor, opciones);
		tecla = gameUI.getTecla();
		gameLogic.moverCursor(cursor, opciones, tecla);
		if(tecla == GameUI::ENTER) return cursor;
		if(tecla == GameUI::ESCAPE) return -1;
	}
}


