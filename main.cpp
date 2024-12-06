#include <iostream>
#include <vector>
#include <conio.h>
#include "Logica/GameLogic.h"
#include "Presentacion/GameUI.h"

#define RESET "\033[0m"  // Restablece el color de la fuente.
#define YELLOW "\033[33m"  // Cambia el color de la fuente a amarillo.
#define PURPURA "\033[35m" // Cambia el color de la fuente a purpura.
#define VERDE "\033[1;32m"

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
int jugVsJug(TableroDeJuego& tableroDeJuego, int jugadorEnTurno);

int main() {
	bool salir = false;
	int seleccion;
	TableroDeJuego tableroDeJuego;

	do {
		seleccion = menu(opcionesMenuPrincipal);
		system("cls");
		switch(seleccion) {
			case 0: {
				seleccion = menu(opcionesSubMenu);
				switch(seleccion) {
					case 0: {
						int ganador = jugVsJug(tableroDeJuego, 1);
						if (ganador != 0){ 
							cout << "					     ¡El " << YELLOW << "jugador " << ganador << RESET << " ha ganado!" << endl;
							_getch();
						}
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

int jugVsJug(TableroDeJuego& tableroDeJuego, int jugadorEnTurno) { 
	pair<int, int> cursor = {0, 0}; 
	while (true) {
		gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);
		tecla = gameUI.getTecla();
		gameLogic.moverCursor(cursor, TableroDeJuego::SIZE, tecla);
		if (tecla == GameUI::ENTER) { 
			if (tableroDeJuego.capturarCasilla(jugadorEnTurno, cursor)) {
				jugadorEnTurno = (jugadorEnTurno == 1) ? 2 : 1; // Cambiar de jugador
			}
		} else if (tecla == GameUI::ESCAPE) { 
			return 0; // Partida pausada o terminada 
		} /*else if (key == GameUI::G) { 
			// Lógica para guardar el juego 
		} */
		gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);
		int ganador = tableroDeJuego.comprobarVictoria(); 
		if (ganador != 0) { 
			for(int i = 0; i < 3; i++){
				tableroDeJuego.eliminarCasilla(1);
				tableroDeJuego.eliminarCasilla(2);
			}
			return ganador; // Devuelve el jugador ganador
		} 
	} 
}
