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
	//recupere les actions du joueur (shift pour aller plus vite)
	Input inputPerso;

	//structure utilisée dans Perso.cpp
	struct Pos { int posX, posY; };


	//Texture du personnage (image dans un dossier)
	Texture texture_perso;
	//Sprite du personnage (apparence du personnage en jeu)
	Sprite sprite_perso;
	//Liste des directions où peut regarder notre personnage
	enum Dir { Down, Left, Right, Up };
	//(x, y) x = colonne d'animation (de 1 à 3) et y = ligne d'animation (choix de la liste juste au dessus)
	Vector2i anim;

public:
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



	//attribut private
private:
	Pos posJoueur;
};
#endif

