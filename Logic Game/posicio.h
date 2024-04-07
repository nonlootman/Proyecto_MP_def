#ifndef POSICIO_H
#define POSICIO_H

#include "definicions.h"

class Posicio
{
public:
	Posicio() : m_fila(-1), m_columna(-1) {}
	Posicio(int fila, int columna) : m_fila(fila), m_columna(columna) {}
	void set(int fila, int columna) { m_fila = fila; m_columna = columna; }

	int getPosX() const { return m_fila; };
	int getPosY() const { return m_columna; };

	bool teAdjacent(const Posicio& posicio, const Posicio& posicio2) const;
	
private:
	int m_fila;
	int m_columna;
	
};



#endif
