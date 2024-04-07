#ifndef InfoJoc_h
#define InfoJoc_h

// N� de files i columnes del tauler
const int N_ROWS = 10;
const int N_COLS = 10;

// Tamany en p�xel de cadascuna de les caselles del tauler
const int CELL_W = 50;
const int CELL_H = 50;

// Posici� a pantalla de la cantonada superior esquerra del tauler
const int CELL_INIT_X = 50;
const int CELL_INIT_Y = 150;

// Posici� a pantalla on imprimir la puntuaci�
const int PUNTS_INIT_X = 50;
const int PUNTS_INIT_Y = 20;

// Posici� a pantalla on imprimir el n� de moviments
const int MOVIMENTS_INIT_X = 50;
const int MOVIMENTS_INIT_Y = 60;

// Posici� a pantalla on imprimir els objectius aconseguits
const int OBJECTIU_INIT_X = 500;
const int OBJECTIU_INIT_Y = 50;

// Posici� a pantalla on imprimir el text de final de partida
const int FINAL_INIT_X = 50;
const int FINAL_INIT_Y = 650;

// Tamany en p�xels de la finestra del joc
const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 700;

// Temps d'espera entre cadascun dels passos d'un moviment de caramels
const double TEMPS_PAUSA = 0.25;


#endif
