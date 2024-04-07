#include "posicio.h"
#include <cstdlib>
#include <iostream>

using namespace std;


bool Posicio::teAdjacent(const Posicio& posicio, const Posicio& posicio2) const
{
    
	if (posicio.getPosX() == posicio2.getPosX() && abs(posicio.getPosY() - posicio2.getPosY()) == 1)
	{
		return true;
	}
	else if (posicio.getPosY() == posicio2.getPosY() && abs(posicio.getPosX() - posicio2.getPosX()) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



