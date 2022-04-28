#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "input.h"
#include "salle.h"
#include <Windows.h>

//Constantes du Programme
const int SCREEN_SIZE_WEIGHT = 960;
const int SCREEN_SIZE_HEIGHT = 960;



using namespace sf;
using namespace std;

class Jeu {
	View vue = View();
	Clock clk;

	RenderWindow window;
	Font font;

	Input input;
	Event event;

	Salle salle;

public:
	//Proto du contructeur
	Jeu();

	//getter

	//setter

	//fonction
	void creationJeu();
	void bouclePrincipale();

	bool isOpen();

private:
	void loadFont();
	bool bloquageCameraX();
	bool bloquageCameraY();
};
#endif

