// Presentacion/GameUI.cpp
#include "GameUI.h"
#define SEPARADOR "---------------------------------------------------------------------------------------------------------------------"
#define RESET "\033[0m"  // Restablece el color de la fuente.
#define YELLOW "\033[33m"  // Cambia el color de la fuente a amarillo.
#define PURPURA "\033[35m" // Cambia el color de la fuente a purpura.
#define VERDE "\033[1;32m"


using namespace std;

void GameUI::mostrarMenu(int cursor, std::vector<string> opcionesMenu) {
	system("cls");
	cout << endl << PURPURA << SEPARADOR << RESET << endl << endl;
	for(size_t i = 0; i < opcionesMenu.size(); ++i) { // Se repite hasta imprimir todas las opciones del menu.
		if(i == cursor) { // Si se va a imprimir la posicion donde esta el cursor se imprime una flecha.
			cout << YELLOW << "				   ->>" << RESET;
		} else { // Sino se deja un espacio.
			cout << "					";
		}
		cout << opcionesMenu[i] << endl;
	}
	cout << endl << PURPURA << SEPARADOR << RESET << endl;
}

GameUI::Tecla GameUI::getTecla() {
	int c = _getch();
	switch (c) {
		case 72:
			return GameUI::ARRIBA;
		case 80:
			return GameUI::ABAJO;
		case 75:
			return GameUI::IZQUIERDA;
		case 77:
			return GameUI::DERECHA;
		case 13:
			return GameUI::ENTER;
		case 27:
			return GameUI::ESCAPE;
		case 'g':
		case 'G':
			return GameUI::G;
		default:
			return GameUI::OTRA; // Valor por defecto
	}
}

void GameUI::mostrarTablero(const vector<vector<int>>& tablero, const pair<int, int>& cursor) const {
	system("cls");
	cout << endl << PURPURA << SEPARADOR << RESET << endl << endl;
	for(int i = 0; i < tablero.size(); i++) {
		cout << "						";
		for(int j = 0; j < tablero[i].size(); j++) {
			if(i == cursor.first && j == cursor.second) {
				cout << VERDE;
			} else {
				cout << PURPURA;
			}
			cout << "{ ";
			cout << YELLOW;
			cout << (tablero[i][j] == 1 ? "X" : tablero[i][j] == 2 ? "O" : " ");
			if(i == cursor.first && j == cursor.second) {
				cout << VERDE;
			} else {
				cout << PURPURA;
			}
			cout << " }" << RESET;
		}
		cout << endl << endl;
	}
	cout << PURPURA << SEPARADOR << RESET << endl;
}

void GameUI::acercaDelJuego() {
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "ACERCA DEL JUEGO" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << "		El juego de " << YELLOW << "tres en raya" << RESET << " consiste en capturar" << endl;
	cout << "	3 casillas que tracen una recta. Se pueden alinear horizontal, vertical" << endl;
	cout << "	y diagonalmente. En esta version del juego, ademas, cada jugador puede" << endl;
	cout << "	tener como maximo 3 casillas capturadas a la vez, por lo que al intentar" << endl;
	cout << "	capturar una 4ta se elimina la casilla capturada mas antigua." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "CREDENCIALES" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << "	Juego creado en 2024 por:" << endl;
	cout << "		-> Juan Garcia." << endl;
	cout <<	"		-> Keiner Perez." << endl;
	cout << "		-> Roxana Moreno." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << "	Presione cualquier tecla para volver al menu." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	_getch();
}

void GameUI::ayuda() {
	char c = 16; // Para imprimir el caracter ASCII de una flecha.
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "COMO SE JUEGA" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << YELLOW << "	->" << RESET << " Selecciona una casilla para capturarla." << endl;
	cout << YELLOW << "	->" << RESET << " Captura 3 casillas alineadas para ganar." << endl;
	cout << YELLOW << "	->" << RESET << " Evita que tu adversario conquiste 3 casillas alineadas." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "CONSEJOS" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << YELLOW << "	->" << RESET << " Capturar la casilla del centro al principio suele ser la mejor estrategia." << endl;
	cout << YELLOW << "	->" << RESET << " Si el centro ya esta ocupado, opta por una de las esquinas." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << PURPURA << "		+++++++ " << YELLOW << "CONTROLES" << PURPURA << " +++++++" << RESET << endl;
	cout << endl << PURPURA << "	[Flechas direccionales]" << RESET << " 	Mover cursor." << endl;
	cout << PURPURA << "		[Enter]" << RESET << " 		Seleccionar." << endl;
	cout << PURPURA << "		  [G]" << RESET << "			Guardar partida." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	cout << "	Presione cualquier tecla para volver al menu." << endl;
	cout << PURPURA << SEPARADOR << RESET << endl;
	_getch();
}