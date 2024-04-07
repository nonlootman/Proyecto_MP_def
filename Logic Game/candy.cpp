#include "candy.h"
#include "GraphicManager.h"

Candy::Candy() {
    m_color = NO_COLOR;
    m_tipus = NO_TIPUS;
}

Candy::Candy(ColorCandy color, TipusCandy tipus) {
    m_color = color;
    m_tipus = tipus;
}

//Comparam colors, si son iguals retorna true
bool Candy::operator==(char c) const {
    return m_color == c;
}

bool caramelCompatibles(const Candy& can1, const Candy& can2)  {
    if (can1.getColor() == can2.getColor() || can1.getTipus() == can2.getTipus()) {
        return true;
    }
    else {
        return false;
    }
}

//Evalua el color i retorna el string que li correspon
string Candy::evaluaColor(const ColorCandy color) {
    switch (color) {
    case VERD:
        return "VERD";
    case LILA:
        return "LILA";
    case BLAU:
        return "BLAU";
    case TARONJA:
        return "TARONJA";
    case VERMELL:
        return "VERMELL";
    case GROC:
        return "GROC";
    case NO_COLOR:
        return "NO_COLOR";
    default:
        return "UNKNOWN";
    }
}

//Evalua el tipus i retorna el string que li correspon
string Candy::evaluaTipus(const TipusCandy tipus) {
    switch (tipus) {
    case NORMAL:
        return "NORMAL";
    case RATLLAT_HORIZONTAL:
        return "RATLLAT_HORIZONTAL";
    case RATLLAT_VERTICAL:
        return "RATLLAT_VERTICAL";
    case NO_TIPUS:
        return "NO_TIPUS";
    default:
        return "UNKNOWN";
    }
}

string Candy::tipusToString(TipusCandy tipus) const {

    switch (tipus) {
    case NORMAL:
        return "NORMAL";
    case RATLLAT_HORIZONTAL:
        return "RATLLAT_HORIZONTAL";
    case RATLLAT_VERTICAL:
        return "RATLLAT_VERTICAL";
    case NO_TIPUS:
        return "NO_TIPUS";
    default:
        return "UNKNOWN";
    }
}

string colorToString(Candy m_tauler[MAX_FILES][MAX_COLUMNES], int i, int j) {
	switch (m_tauler[i][j].getColor()) {
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
		return "X";
	default:
		return "UNKNOWN";
	}
}

void Candy::dibuixa(int posX, int posY) {
    switch (m_color)
    {
    case VERD:
        switch (m_tipus)
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        default:
            break;
        }
        break;
    case VERMELL:
        switch (m_tipus)
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        default:
            break;
        }
        break;
    case BLAU:
        switch (m_tipus)
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        default:
            break;
        }
        break;
    case TARONJA:
        switch (m_tipus)
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        default:
            break;
        }
        break;
    case GROC:
        switch (m_tipus)
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        default:
            break;
        }
        break;
    case LILA:
        switch (m_tipus)
        {
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_HORIZONTAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        case RATLLAT_VERTICAL:
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2),
                CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}