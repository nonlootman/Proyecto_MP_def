#ifndef CANDY_H
#define CANDY_H

#include "definicions.h"
#include <string>
#include <iostream>
#include "GraphicManager.h"
#include "InfoJoc.h"

using namespace std;

class Candy
{
public:

	Candy();
	Candy(ColorCandy color, TipusCandy tipus);

	bool operator==(char c) const;
	string tipusToString(TipusCandy tipus) const;
	void dibuixa(int posX, int posY);
	ColorCandy getColor() const { return m_color; }
	TipusCandy getTipus() const { return m_tipus; }
	
	void setColor(ColorCandy color) { m_color = color; }
	void setTipus(TipusCandy tipus) { m_tipus = tipus; }
	
	string evaluaColor(const ColorCandy color);
	string evaluaTipus(const TipusCandy tipus);

	
private:
	ColorCandy m_color;
	TipusCandy m_tipus;
};



#endif
