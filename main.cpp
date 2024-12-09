#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h> // Para Sleep
#include "Logica/GameLogic.h"
#include "Presentacion/GameUI.h"
#include "Datos/DataAccess.h"

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
int jugVsBot(TableroDeJuego& tableroDeJuego, int jugadorEnTurno);
int botVsBot(TableroDeJuego& tableroDeJuego);

int main() {
	bool salir = false;
	int seleccion, ganador;
	TableroDeJuego tableroDeJuego;

	do {
		seleccion = menu(opcionesMenuPrincipal);
		system("cls");
		switch(seleccion) {
			case 0: {
				seleccion = menu(opcionesSubMenu);
				switch(seleccion) {
					case 0: {
						ganador = jugVsJug(tableroDeJuego, 1);
						if(ganador != 0){ 
							cout << "					     ¡El " << YELLOW << "JUGADOR " << ganador << RESET << " ha ganado!" << endl;
							_getch();
						}
						break;
					}
					case 1: {
						ganador = jugVsBot(tableroDeJuego, 1);
						if(ganador != 0){
							if(ganador == 1) {
								cout << "					     ¡El " << YELLOW << "JUGADOR " << ganador << RESET << " ha ganado!" << endl;
							} else {
								cout << "					     ¡El " << YELLOW << "BOT" << RESET << " ha ganado!" << endl;
							}
							_getch();
						}
						break;
					}
					case 2: {
						ganador = botVsBot(tableroDeJuego);
						if(ganador != 0){ 
							cout << "					     ¡El " << YELLOW << "BOT " << ganador << RESET << " ha ganado!" << endl;
							_getch();
						}
						break;
					}
				}
				break;
			}
			case 1: {
				DataAccess datosRecuperados;
				datosRecuperados.cargarPartida();
				tableroDeJuego.setTablero(datosRecuperados.getTablero());
				tableroDeJuego.setMovJugador1(datosRecuperados.getMovJug1());
				tableroDeJuego.setMovJugador2(datosRecuperados.getMovJug2());
				int n = datosRecuperados.getModoDeJuego();
				if(n == 1) {
					ganador = jugVsJug(tableroDeJuego, 1);
					if(ganador != 0){ 
						cout << "					     ¡El " << YELLOW << "JUGADOR " << ganador << RESET << " ha ganado!" << endl;
					}
				} else if(n == 2) {
					ganador = jugVsBot(tableroDeJuego, 1);
					if(ganador != 0){
						if(ganador == 1) {
							cout << "					     ¡El " << YELLOW << "JUGADOR " << ganador << RESET << " ha ganado!" << endl;
						} else {
							cout << "					     ¡El " << YELLOW << "BOT" << RESET << " ha ganado!" << endl;
						}
					}
				} else {
					cout << endl << YELLOW <<"					     NO HAY PARTIDA GUARDADA" << RESET << endl;
				}
				_getch();
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
	while(true) {
		gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);
		tecla = gameUI.getTecla();
		gameLogic.moverCursor(cursor, TableroDeJuego::SIZE, tecla);
		if(tecla == GameUI::ENTER) {
			if(tableroDeJuego.capturarCasilla(jugadorEnTurno, cursor)) {
				jugadorEnTurno = (jugadorEnTurno == 1) ? 2 : 1; // Cambiar de jugador.
			}
		}
		if(tecla == GameUI::G) {
			DataAccess datos(tableroDeJuego, 1);
			datos.guardarPartida();
		}
		gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);
		int ganador = tableroDeJuego.comprobarVictoria();
		if(ganador != 0) {
			for(int i = 0; i < 3; i++) {
				tableroDeJuego.eliminarCasilla(1);
				tableroDeJuego.eliminarCasilla(2);
			}
			return ganador;
		}
	}
}

int jugVsBot(TableroDeJuego& tableroDeJuego, int jugadorEnTurno) {
    Bot bot;
    pair<int, int> cursor = {0, 0};
    while (true) {
        gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);
        if (jugadorEnTurno == 1) { // Turno del jugador humano
            tecla = gameUI.getTecla();
            gameLogic.moverCursor(cursor, TableroDeJuego::SIZE, tecla);
            if (tecla == GameUI::ENTER) {
                if (tableroDeJuego.capturarCasilla(jugadorEnTurno, cursor)) {
                    jugadorEnTurno = 2; // Cambiar al bot
                }
            }
            if(tecla == GameUI::G) {
				DataAccess datos(tableroDeJuego, 2);
				datos.guardarPartida();
			}
        } else { // Turno del bot
            // Simular que el bot está pensando
            Sleep(1500); // Retraso de 1.5 segundos (1500 milisegundos)

            pair<int, int> botMove = bot.hacerMovimiento(tableroDeJuego.getTablero(), jugadorEnTurno);
            if (botMove.first != -1 && botMove.second != -1) {
                tableroDeJuego.capturarCasilla(jugadorEnTurno, botMove);
                jugadorEnTurno = 1; // Cambiar al jugador humano
            }
        }
        gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);
        int ganador = tableroDeJuego.comprobarVictoria();
        if (ganador != 0) {
            for (int i = 0; i < 3; i++) {
                tableroDeJuego.eliminarCasilla(1);
                tableroDeJuego.eliminarCasilla(2);
            }
            return ganador;
        }
    }
}

int botVsBot(TableroDeJuego& tableroDeJuego) {
    Bot bot;
    int jugadorEnTurno = 1;
    pair<int, int> cursor = {-1, -1}; // Inicializar el cursor aunque no lo usemos realmente aquí
    while (true) {
        gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);

        // Simular que el bot está pensando
        Sleep(1500); // Retraso de 1.5 segundos (1500 milisegundos)

        pair<int, int> botMove = bot.hacerMovimiento(tableroDeJuego.getTablero(), jugadorEnTurno);
        if (botMove.first != -1 && botMove.second != -1) {
            tableroDeJuego.capturarCasilla(jugadorEnTurno, botMove);
            jugadorEnTurno = (jugadorEnTurno == 1) ? 2 : 1; // Cambiar de bot
        }

        gameUI.mostrarTablero(tableroDeJuego.getTablero(), cursor);
        int ganador = tableroDeJuego.comprobarVictoria();
        if (ganador != 0) {
            for (int i = 0; i < 3; i++) {
                tableroDeJuego.eliminarCasilla(1);
                tableroDeJuego.eliminarCasilla(2);
            }
            return ganador;
        }
    }
}
