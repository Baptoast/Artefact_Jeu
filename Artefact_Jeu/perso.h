#ifndef PERSO_H
#define PERSO_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"


//namespaces
using namespace sf;
using namespace std;

class Perso {

	//structure utilisée dans Perso.cpp
	struct Pos { int posX, posY; };

	Texture texture_perso;
	Texture texture_vision;
	Texture texture_portrait;
	
	//Liste des directions où peut regarder notre personnage
	enum Dir { Down, Left, Right, Up };
	//(x, y) x = colonne d'animation (de 1 à 3) et y = ligne d'animation (choix de la liste juste au dessus)
	Vector2i anim;

public:
	int pv;

	struct Case { int posX, posY; };
	vector<Case> listeCase;

	int choix = 0;
	int numeroDeFile = -1;
	Sprite sprite_perso;
	Sprite sprite_vision;
	Sprite sprite_portrait;

	//Proto du contructeur
	Perso();
	Perso(int x, int y);

	//Setter
	void setInput(Input input);
	void setPosX(int x);
	void setPosY(int y);

	//Getter
	Pos getPos(void) const;
	Sprite getSprite();

	//fontion
	void loadTexturePerso();
	float anglePoints(int x1, int y1, int x2, int y2);
	float anglePointsDegree(int x1, int y1, int x2, int y2);
	void loadTexturePersoPortrait(String personnageChoisi);

	void affichePerso(RenderWindow& window);



	//attribut private
private:
	Pos posJoueur;
};
#endif

