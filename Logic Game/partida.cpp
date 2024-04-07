#include "partida.h"
#include "candy.h"
#include "tauler.h"
#include <fstream>
#include <iostream>
#include "GraphicManager.h"
#include "InfoJoc.h"

using namespace std;

int estatPrevi = 0;

Partida::Partida() {
	m_CarObj = "";

	cout << "Indica el numero de moviments maxims: " << endl;
	while (true) {
		if (!(cin >> m_nMaxMoviments) || cin.peek() != '\n') {
			cout << "No has posat un numero, introdueix novament: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		break;
	}

	cout << "Indica el numero de punts maxims (Cada caramel suma un punt): " << endl;

	while (true) {
		if (!(cin >> m_nMaxPunts2) || cin.peek() != '\n') {
			cout << "No has posat un numero, introdueix novament: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		break;
	}

	m_nMoviments = 0;
	m_nObj = 0;
	m_punts2 = 0;
}


//Inicialitzam la partida a partir d'un fitxer
void Partida::inicialitza(const string& nomFitxer) {
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open()) {
		int obj, mov;
		string pe;
		char car;
		fitxer >> pe >> obj >> mov;
		m_CarObj = pe;
		m_nObj = obj;
		m_nMovs = 0;
		int fila = 0, columna = 0;
		while (fitxer >> car) {
			m_tauler1.init(car, fila, columna);
			columna++;
			if (columna == MAX_COLUMNES) {
				columna = 0;
				fila++;
				if (fila == MAX_FILES) {
					break;  // Hemos leído todo el contenido del archivo
				}
			}
		}
		fitxer.close();
	}
}

//Cambiam el color a string per tenir el format que demana el tauler
string Partida::colorToString(ColorCandy color) const {
	switch (color) {
	case VERD:
		return "G";
	case LILA:
		return "P";
	case BLAU:
		return "B";
	case TARONJA:
		return "O";
	case VERMELL:
		return "R";
	case GROC:
		return "Y";
	case NO_COLOR:
		return "_";
	default:
		return "UNKNOWN";
	}
}

TipusCandy Partida::stringToTipus(const string& tipus) const {
	if (tipus == "NORMAL") {
		return NORMAL;
	}
	else if (tipus == "RATLLAT_HORIZONTAL") {
		return RATLLAT_HORIZONTAL;
	}
	else if (tipus == "RATLLAT_VERTICAL") {
		return RATLLAT_VERTICAL;
	}
	else {
		return NO_TIPUS;
	}
}

bool Partida::esAdjacent(const Posicio& posicio1, const Posicio& posicio2) const {
	
	int difX = abs(posicio1.getPosX() - posicio2.getPosX());
	int difY = abs(posicio1.getPosY() - posicio2.getPosY());

	if (difX <= 100 && difX >= 50 && difY <= 100 && difY >= 50) {
		
		cout << "Diferencia X: " << difX << " Diferencia Y: " << difY << endl;
	}
		return true;
	
		cout << "Diferencia X: " << difX << " Diferencia Y: " << difY << endl;
		cout << "No son adjacents" << endl;
	return false;
}



bool Partida::iniciaMoviment(const Posicio& p1, const Posicio& p2)
{
	// Hem fet un moviment, sumam fins arribar a m_nMaxMoviments (input)
	
	m_nMoviments++;

	cout << "Moviments: " << m_nMoviments << endl;;

	cout << "Moviments maxims: " << m_nMaxMoviments << endl;

	cout << "Punts: " << m_punts2 << endl;;

	cout << "Punts maxims: " << m_nMaxPunts2 << endl;
	continuaMoviment(p1, p2);

	return true;
}

bool Partida::continuaMoviment(const Posicio& p1, const Posicio& p2)
{

		cout << "HA ENTRAT EN ELIMINA" << endl;
		bool eliminats = m_tauler1.caramelsAlineats(p1, p2);
		m_tauler1.caigudaCaramels();
		m_tauler1.generaNouCaramel();

		// Eliminació completada, sumam un punt
		if (eliminats)
			m_punts2++;

		return eliminats;
}


void Partida::fesMoviment(const Posicio& pos1, const Posicio& pos2)
{
	
	while (m_nMoviments < m_nMaxMoviments)
	{
		m_tauler1.caramelsAlineats(pos1, pos2);
		m_tauler1.caigudaCaramels();
		m_tauler1.generaNouCaramel();

		m_nMovs++;
	}
	
	
	/*
	if (m_nMovs < m_nMaxMovs)
	{
		m_tauler1.mouCandy(pos1, pos2);

		if (m_tauler1.caramelsCompatibles(pos1, pos2))
		{
			Candy c1 = m_tauler1.getTauler(pos1.getPosX(), pos1.getPosY());
			Candy c2 = m_tauler1.getTauler(pos2.getPosX(), pos2.getPosY());
			
			m_tauler1.eliminaCaramelsAlineats(pos1);
			m_tauler1.eliminaCaramelsAlineats(pos2);
			
			if (m_tauler1.dinsTauler(pos1))
			{
				m_tauler1.mouCandy(pos1, pos2);
			}
		}
		else
		{
			m_tauler1.mouCandy(pos2, pos1);
			valid = false;
		}
	}
	*/
}


void Partida::escriuTauler(const string& nomFitxer) {
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (!fitxer.is_open()) {
		cout << "Error: no s'ha pogut obrir el fitxer " << nomFitxer << endl;
		return;
	}
	
	for (int fila = 0; fila < MAX_FILES; fila++) {
		for (int columna = 0; columna < MAX_COLUMNES; columna++) {
			Candy c = m_tauler1.getTauler(fila, columna);
			cout << colorToString(c.getColor()) << " ";
			fitxer << colorToString(c.getColor()) << " ";
		}
		fitxer << endl;
	}
	fitxer.close();
}

void Partida::DIbuixa(int mouX, int mouY) {
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);
	m_tauler1.Dibuixa();
	string msg = "X: " + to_string(mouX) + ", Y: " + to_string(mouY);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, FINAL_INIT_X, FINAL_INIT_Y, 1.0, msg);
}