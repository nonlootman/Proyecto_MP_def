#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <fstream>
#include "tauler.h"

using namespace std;

class Partida
{
public:
    Partida();
    void inicialitza(const string& nomFitxer);
   

    void escriuTauler(const string& nomFitxer);
    void DIbuixa(int mouX, int mouY);
    Tauler getTauler(int fila, int columna) const { return m_tauler1; }

    bool iniciaMoviment(const Posicio& p1, const Posicio& p2);
    bool continuaMoviment(const Posicio& p1, const Posicio& p2);

    void fesMoviment(const Posicio& pos1, const Posicio& pos2);

    int getMovs() const { return m_nMoviments; }
    int getPunts() const { return m_punts2; }
    int getMaxMovs() const { return m_nMaxMoviments; }
    int getMaxPunts() const { return m_nMaxPunts2; }

    bool esAdjacent(const Posicio& posicio, const Posicio& posicio2) const;
    
private:
    Tauler m_tauler1;
    int m_nMovs;
    int m_nObj;
    string m_CarObj;
    
    int m_nMoviments;
    int m_nMaxMoviments;
    int m_punts2;
    int m_nMaxPunts2;

    string colorToString(ColorCandy color) const;
    string tipusToString(TipusCandy tipus) const;

	TipusCandy stringToTipus(const string& tipus) const;
    
};

#endif
