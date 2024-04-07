#include "tauler.h"
#include "candy.h"
#include "posicio.h"
#include "partida.h"
#include <fstream>
#include <iostream>

Tauler::Tauler()
{
	m_index = 0;
}

ColorCandy Tauler::GetColorCandyAtPos(int x, int y) const
{
	return m_tauler[x][y].getColor();
}


TipusCandy Tauler::GetTipusCandyAtPos(int x, int y) const
{
	return m_tauler[x][y].getTipus();
}


void Tauler::SetColorCandyAtPos(int x, int y, ColorCandy color) {
	m_tauler[x][y].setColor(color);
}


void Tauler::SetTipusCandyAtPos(int x, int y, TipusCandy tipus) {
	m_tauler[x][y].setTipus(tipus);
}



void Tauler::init(char s, int fil, int col) {
	m_tauler[fil][col].setTipus(NORMAL);
	switch (s)
	{
	case 'G':
		m_tauler[fil][col].setColor(VERD);
		break;
	case 'P':
		m_tauler[fil][col].setColor(LILA);
		break;
	case 'R':
		m_tauler[fil][col].setColor(VERMELL);
		break;
	case 'B':
		m_tauler[fil][col].setColor(BLAU);
		break;
	case 'Y':
		m_tauler[fil][col].setColor(GROC);
		break;
	case 'O':
		m_tauler[fil][col].setColor(TARONJA);
		break;
	default:
		m_tauler[fil][col].setColor(NO_COLOR);
		break;
	}
}


//Cambiam el color a string per tenir el format que demana el tauler
string Tauler::colorToString(ColorCandy color, int i, int j) const {
    if ((m_tauler[i][j].tipusToString(m_tauler[i][j].getTipus()) == "RATLLAT_HORIZONTAL") || (m_tauler[i][j].tipusToString(m_tauler[i][j].getTipus()) == "RATLLAT_VERTICAL")) {
        switch (color)
        {
        case VERD:
            return "g";
        case LILA:
            return "p";
        case BLAU:
            return "b";
        case TARONJA:
            return "o";
        case VERMELL:
            return "r";
        case GROC:
            return "y";
        case NO_COLOR:
            return "NO_COLOR";
        default:
            return "UNKNOWN";
            break;
        }
	}
	else {
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
		return "NO_COLOR";
	default:
		return "UNKNOWN";
	}
	}
}


bool Tauler::dinsTauler(const Posicio& pos) const
{
	// Comprovació de que la posició està dins del tauler

	if (pos.getPosX() >= 0 && pos.getPosX() < MAX_FILES && pos.getPosY() >= 0 && pos.getPosY() < MAX_COLUMNES)
		return true;
	else
		return false;
}


void Tauler::caigudaCaramels() {

	// Si hi ha caramels que siguin NO_COLOR, els caramels de dalt cauen

	for (int i = 0; i < MAX_FILES; i++) 
		for (int j = 0; j < MAX_COLUMNES; j++) 

			if (m_tauler[i][j].getColor() == NO_COLOR) {


				// Desplaçam les files de dalt de la mateixa columna

				for (int k = i; k > 0; k--) {

					mouCandy(Posicio(k - 1, j), Posicio(k, j));

					Posicio posNova(k, j);
						

				}
			}		
}


ColorCandy Tauler::generaNouCaramel() {

	ColorCandy color = NO_COLOR;
	ColorCandy colors[] = { VERMELL,TARONJA, GROC, BLAU, VERD, LILA };

	for (int i = MAX_FILES - 1; i >= 0; i--) {
		for (int j = 0; j <= MAX_COLUMNES - 1; j++)
			if (m_tauler[i][j].getColor() == NO_COLOR) {

				m_tauler[i][j].setColor(colors[m_index]);
				m_tauler[i][j].setTipus(NORMAL);

				// if (m_tauler[i][j].getColor() == m_tauler[i][j].getColor())
				// Guardar posicions dins una rray
				// des d'aquestes posicions agaf 
				// Nova posicio i, j

				Posicio posNova(i, j);
				bool vertical = caramelsAlineatsVerticalment(posNova);
				bool horizontal = caramelsAlineatsHoritzontal(posNova);
				
				if (vertical || horizontal) {

					
				}

				m_index++;
				if (m_index == 6)
					m_index = 0;
			}
	}
	return color;
}


bool Tauler::caramelsAlineats(const Posicio& pos1, const Posicio& pos2) {

	int comptadorVertical = 1;
	int comptadorHoritzontal = 1;
	bool alineacio = false;

	// Mou Candy

	mouCandy(pos1, pos2);

	ColorCandy color = m_tauler[pos2.getPosX()][pos2.getPosY()].getColor();

	// Eliminam els caramels de la mateixa fila

	bool vertical2 = caramelsAlineatsVerticalment(pos2);
	bool vertical1 = caramelsAlineatsVerticalment(pos1);
	
	bool horizontal2 = caramelsAlineatsHoritzontal(pos2);
	bool horizontal1 = caramelsAlineatsHoritzontal(pos1);

	m_index = 0;
	
	if (vertical2 || horizontal2 || vertical1 || horizontal1) {
		
		caigudaCaramels();
		return true;
	}

	// No s'ha pogut realitzar cap alineació
	mouCandy(pos2, pos1);
	
	// Al final de cada fesMoviment el posam a 0
	//m_index = 0;
    return false;
}


bool Tauler::caramelsAlineatsVerticalment(const Posicio& pos2) {
	
	int comptadorBaix = 1;
	int comptadorDalt = 1;

	for (int i = pos2.getPosX(); i > 0; i--) {
		if (m_tauler[i][pos2.getPosY()].getColor() == m_tauler[i - 1][pos2.getPosY()].getColor() && m_tauler[i][pos2.getPosY()].getColor() != NO_COLOR) {
			comptadorBaix++;
		}
		else
			break;
	}

	for (int i = pos2.getPosX(); i <= MAX_FILES - 1; i++) {
		if (m_tauler[i][pos2.getPosY()].getColor() == m_tauler[i + 1][pos2.getPosY()].getColor() && m_tauler[i][pos2.getPosY()].getColor() != NO_COLOR) {
			comptadorDalt++;
		}
		else
			break;
	}

	int comptadorVertical = comptadorBaix + comptadorDalt - 1;
	
	
	if (comptadorVertical == 3) {
		int iterador = 0;
		for (int j = pos2.getPosX() + comptadorDalt - 1; j >= 0; j--) {
			if (iterador == comptadorVertical)
				break;

			else {
				iterador++;
				Candy c = m_tauler[j][pos2.getPosY()];
				c.setColor(NO_COLOR);
				m_tauler[j][pos2.getPosY()] = c;

				// Fila

				if (m_tauler[j][pos2.getPosY()].getTipus() == RATLLAT_HORIZONTAL)
					for (int k = 0; k < MAX_COLUMNES; k++) 
						m_tauler[pos2.getPosX()][k].setColor(NO_COLOR);
						

				// Columna 

				else if (m_tauler[pos2.getPosX()][j].getTipus() == RATLLAT_VERTICAL)
					for (int k = MAX_FILES; k >= 0; k--)
						m_tauler[k][pos2.getPosY()].setColor(NO_COLOR);
			}
		}
		return true;
	}

	if (comptadorVertical >= 4) {
		int iterador = 0;
		m_tauler[pos2.getPosX()][pos2.getPosY()].setTipus(RATLLAT_HORIZONTAL);


		for (int j = pos2.getPosX() + comptadorDalt - 1; j >= 0; j--) {
			if (iterador == comptadorVertical)
				break;
			
			else {	
				if (m_tauler[j][pos2.getPosY()].getTipus() == RATLLAT_HORIZONTAL) 
					iterador++;
				
				else {
					iterador++;
					Candy c = m_tauler[j][pos2.getPosY()];
					c.setColor(NO_COLOR);
					m_tauler[j][pos2.getPosY()] = c;

					// Fila

					if (m_tauler[j][pos2.getPosY()].getTipus() == RATLLAT_HORIZONTAL)
						for (int k = 0; k < MAX_COLUMNES; k++)
							m_tauler[pos2.getPosX()][k].setColor(NO_COLOR);

					// Columna 

					if (m_tauler[pos2.getPosX()][j].getTipus() == RATLLAT_VERTICAL)
						for (int k = MAX_FILES; k >= 0; k--)
							m_tauler[k][pos2.getPosY()].setColor(NO_COLOR);
				}
			}
		}
		return true;
	}

	return false;
}


bool Tauler::caramelsAlineatsHoritzontal(const Posicio& pos2) {
	
	int comptadorDreta = 1;
	int comptadorEsquerra = 1;

	for (int i = pos2.getPosY(); i <= MAX_COLUMNES - 1; i++) {
		
		if (m_tauler[pos2.getPosX()][i].getColor() == m_tauler[pos2.getPosX()][i + 1].getColor() && m_tauler[pos2.getPosX()][i].getColor() != NO_COLOR) {
			
			comptadorDreta++;
		}
		else
			break;
	}

	for (int i = pos2.getPosY(); i > 0; i--) {

		if (m_tauler[pos2.getPosX()][i].getColor() == m_tauler[pos2.getPosX()][i - 1].getColor() && m_tauler[pos2.getPosX()][i].getColor() != NO_COLOR) {
			
			comptadorEsquerra++;
		}
		else
			break;
	}
	
	int comptadorHorizontal = comptadorDreta + comptadorEsquerra - 1;

	if (comptadorHorizontal == 3) {
		int iterador = 0;
		for (int j = pos2.getPosY() + comptadorDreta - 1; j >= 0; j--) {
			if (iterador == comptadorHorizontal)
				break;

			else {
				iterador++;
				Candy c = m_tauler[pos2.getPosX()][j];
				c.setColor(NO_COLOR);
				m_tauler[pos2.getPosX()][j] = c;
				cout << j << " " << pos2.getPosY() << " " << c.getColor() << endl;

				// Fila

				if (m_tauler[j][pos2.getPosY()].getTipus() == RATLLAT_HORIZONTAL)
					for (int k = 0; k < MAX_COLUMNES; k++)
						m_tauler[pos2.getPosX()][k].setColor(NO_COLOR);

				// Columna 

				if (m_tauler[pos2.getPosX()][j].getTipus() == RATLLAT_VERTICAL)
					for (int k = MAX_FILES; k >= 0; k--)
						m_tauler[k][pos2.getPosY()].setColor(NO_COLOR);
			}
		}
		return true;
	}

	if (comptadorHorizontal >= 4) {
		int iterador = 0;
		m_tauler[pos2.getPosX()][pos2.getPosY()].setTipus(RATLLAT_VERTICAL);
		for (int j = pos2.getPosY() + comptadorDreta - 1; j >= 0; j--) {
			if (iterador == comptadorHorizontal)
				break;

			else {

				if (m_tauler[pos2.getPosX()][j].getTipus() == RATLLAT_VERTICAL) {
					iterador++;
				}
				else {
					iterador++;
					Candy c = m_tauler[pos2.getPosX()][j];
					c.setColor(NO_COLOR);
					m_tauler[pos2.getPosX()][j] = c;

					// Fila

					if (m_tauler[j][pos2.getPosY()].getTipus() == RATLLAT_HORIZONTAL)
						for (int k = 0; k < MAX_COLUMNES; k++)
							m_tauler[pos2.getPosX()][k].setColor(NO_COLOR);

					// Columna 

					if (m_tauler[pos2.getPosX()][j].getTipus() == RATLLAT_VERTICAL)
						for (int k = MAX_FILES; k >= 0; k--)
							m_tauler[k][pos2.getPosY()].setColor(NO_COLOR);
				}
			}
		}
		return true;
	}
	return false;
}


void Tauler::mouCandy(const Posicio& pos1, const Posicio& pos2) {

	//m_index = 0;
	
	Candy c1 = m_tauler[pos1.getPosX()][pos1.getPosY()];
	Candy c2 = m_tauler[pos2.getPosX()][pos2.getPosY()];	
	Candy aux;

	aux = c1;
	c1 = c2;
	c2 = aux;

	m_tauler[pos1.getPosX()][pos1.getPosY()] = c1;
	m_tauler[pos2.getPosX()][pos2.getPosY()] = c2;
}


void Tauler::Dibuixa() {
	for (int i = 0; i < MAX_FILES; i++)
		for (int j = 0; j < MAX_COLUMNES; j++)
			m_tauler[i][j].dibuixa(j, i);
}




