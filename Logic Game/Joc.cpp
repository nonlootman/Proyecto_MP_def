#include "Joc.hpp"
#include "InfoJoc.h"
#include "GraphicManager.h"

int posX = 0;
int posY = 0;

int posX2 = 0;
int posY2 = 0;

void Joc::inicialitza(const string& nomFitxer)
{
    m_partida.inicialitza(nomFitxer);
    m_estat = ESTAT_JOC_ESPERA;
    m_posicioInicial.set(-1, -1);
    m_mouseIntercanviX = 0;
    m_mouseIntercanviY = 0;
    m_despIntercanviX = 0;
    m_despInterncanviY = 0;
}


IMAGE_NAME Joc::colorToSprite(ColorCandy color) {

    IMAGE_NAME sprite;

    switch (color)
    {
    case VERD:
        sprite = IMAGE_PIECE_GREEN;
        break;
    case LILA:
        sprite = IMAGE_PIECE_PURPLE;
        break;
    case BLAU:
        sprite = IMAGE_PIECE_BLUE;
        break;
    case TARONJA:
        sprite = IMAGE_PIECE_ORANGE;
        break;
    case VERMELL:
        sprite = IMAGE_PIECE_RED;
        break;
    case GROC:
        sprite = IMAGE_PIECE_YELLOW;
        break;
    }

    return sprite;
}



void Joc::actualitza(int mousePosX, int mousePosY, bool mouseStatus, double deltaTime)
{
    //TODO 1: Interactuar amb la crida per dibuixar gràfics (sprites).
    // 	      Dibuixar a pantalla el fons i el gràfic amb el tauler buit.
    //------------------------------------------------------------------

    //TODO 1.1 Afegir l'include de GraphicManager --> #include "GraphicManager.h"
    //TODO 1.2 Fer la crida de dibuixar un sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY, centered);
    //	    Per començar podem cridar el drawSprite amb els params --> 
    //          (IMAGE_BACKGROUND,0,0, false) i 
    //          (IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false)




    //TODO 1.3: Dibuixar a pantalla el gràfic amb el tauler i un caramel blau centrat a la posició (2,2) del tauler





    //TODO 2: Interacció amb el mouse
    //------------------------------------------
    // TODO 2.1: Dibuixar un caramel blau centrat a la posició (2,2) del tauler només si estem pressionant el botó esquerre del mouse
    //          Si no l'estem pressionant només s'ha de dibuixar el tauler sense el caramel





    // TODO 2.2 Si estem pressionant el botó esquerre del mouse, dibuixar un caramel blau centrat a la posició del tauler on tenim el mouse
    //          Si no l'estem pressionant només s'ha de dibuixar el tauler sense el caramel



    //TODO 3: Introduir un temps d'espera
    //-----------------------------------
    // Dibuixar un caramel blau a la posicio (2,2) del tauler. Eliminar-lo quan hagi passat mig segon. 
    // Tornar-lo a dibuixar al cap de mig segon i anar repetint el cicle eliminar/dibuixar cada mig segon




    // TODO 4: Imprimir text per pantalla
    //------------------------------------------
    // TODO 4.1: Imprimir les coordenades de la posició actual del ratolí a sota del tauler




    //TODO 5: Mostrar l’estat inicial del joc amb tots els caramels col·locats a la seva posició inicial
    //-----------------------------------------
    
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    m_partida.DIbuixa(mousePosX, mousePosY);
    bool continua;


    switch (m_estat)
    {
    case ESTAT_JOC_ESPERA:
        if (mouseStatus) {

            // Aconseguim les posicions inicials
            cout << "JOC ESPERA 1" << endl;
            posX = (mousePosX - CELL_INIT_X) / CELL_W;
            posY = (mousePosY - CELL_INIT_Y) / CELL_H;

            if ((posX >= 0) && (posX < MAX_COLUMNES) && (posY >= 0) && (posY < MAX_FILES)) {
                m_posicioInicial.set(posY, posX);

                m_estat = ESTAT_JOC_INTERCANVI;
            }
        }
        break;
        
        
    case ESTAT_JOC_INTERCANVI:
        if (!mouseStatus) {
            m_estat = ESTAT_JOC_ESPERA;
            m_posicioInicial.set(-1, -1);
        }

        else {

            // Aconseguim les posicions seguents de la cela marcada
            posX2 = (mousePosX - CELL_INIT_X) / CELL_W;
            posY2 = (mousePosY - CELL_INIT_Y) / CELL_H;

            if (posX2 >= 0 && posX2 < 10 && posY2 >= 0 && posY2 < 10 && (posX2 != posX || posY2 != posY)) {
                m_posicioDesti.set(posY2, posX2);

                bool adjacents;
                adjacents = m_partida.esAdjacent(m_posicioInicial, m_posicioDesti);

                if (!adjacents) {

                    // No son adjacents, tornam dalt
                    cout << "NO SON ADJACENTS" << endl;
                    m_estat = ESTAT_JOC_ESPERA;
                    break;
                }

                m_partida.iniciaMoviment(m_posicioInicial, m_posicioDesti);
                m_estat = ESTAT_JOC_MOVIMENTS;
            }
            else {
                m_estat = ESTAT_JOC_ESPERA;
                }
            }
        break;
    
    
    case ESTAT_JOC_MOVIMENTS:
                    
        // Procediment mostrat
        m_temps += deltaTime;
        if (m_temps > TEMPS_PAUSA) {
            m_temps = 0.0;

            cout << m_partida.getMovs() << " " << m_partida.getPunts() << endl;
                if (m_partida.getMovs() == m_partida.getMaxMovs() || m_partida.getPunts() == m_partida.getMaxPunts()) {
                    cout << "ESTAT FINAL DE LA PARTIDA" << endl;
                    m_estat = ESTAT_FINAL;
                    break;
                }

                else {
                    // Miram si el moviment es correcte
                    cout << "HA ENTRAR EN PAUSA" << endl;
                    continua = m_partida.continuaMoviment(m_posicioInicial, m_posicioDesti);
                }

                if (!continua) {
                    cout << "JOC ESPERA 2" << endl;
                    m_estat = ESTAT_JOC_ESPERA;
                }
        }
        
        break;

    case ESTAT_FINAL:
        break;

    }
	m_partida.DIbuixa(mousePosX, mousePosY);
}


