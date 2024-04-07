#ifndef TAULER_H
#define TAULER_H
#include "candy.h"
#include "posicio.h"

using namespace std;

class Tauler
{
public:

	Tauler();
	
	Candy getCandy(const Posicio& pos) const { return m_tauler[pos.getPosX()][pos.getPosY()]; }

	
	int getFila() const { return m_fil; }
	int getColumna() const { return m_col; };


	ColorCandy GetColorCandyAtPos(int x, int y) const;
	TipusCandy GetTipusCandyAtPos(int x, int y) const;
	void SetColorCandyAtPos(int x, int y, ColorCandy color);
	void SetTipusCandyAtPos(int x, int y, TipusCandy tipus);

	void mouCandy(const Posicio& pos1, const Posicio& pos2);

	void Dibuixa();

	void init(char s, int fil, int col);

	string colorToString(ColorCandy color, int i, int j) const;
	void caigudaCaramels();

	bool dinsTauler(const Posicio& pos) const;
	
	ColorCandy generaNouCaramel(); // Genera un caramel seguint R,O,Y,B,G,P
	bool caramelsAlineats(const Posicio& pos1, const Posicio& pos2);
	bool caramelsAlineatsVerticalment(const Posicio& pos2);
	bool caramelsAlineatsHoritzontal(const Posicio& pos2);
	

	Candy getTauler(int fila, int columna) const { return m_tauler[fila][columna]; 

	}

private:
	Candy m_tauler[MAX_FILES][MAX_COLUMNES];

	int m_fil;
	int m_col;
	int m_index;
 };

#endif
