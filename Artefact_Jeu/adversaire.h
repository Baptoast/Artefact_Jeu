#ifndef ADVERSAIRE_H
#define ADVERSAIRE_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"


//namespaces
using namespace sf;
using namespace std;

class Adversaire {

	//structure utilisée dans Perso.cpp
	struct Pos { int posX, posY; };
	
	Texture texture_portrait;
	

	//Liste des directions où peut regarder notre personnage
	enum Dir { Down, Left, Right, Up };
	//(x, y) x = colonne d'animation (de 1 à 3) et y = ligne d'animation (choix de la liste juste au dessus)
	Vector2i anim;

public:
	vector<Texture> texture_adversaire;

	int pv;
	Sprite sprite_portrait;
	Sprite sprite_adversaire;
	int numeroDeFile = -1;
	struct Case { int posX, posY; };
	vector<Case> listeCase; 
	int choix = 1;
	Pos posAdversaire;

	//Proto du contructeur
	Adversaire();
	Adversaire(int x, int y);

	//Setter
	void setInput(Input input);
	void setPosX(int x);
	void setPosY(int y);

	//Getter
	Pos getPos(void) const;
	Sprite getSprite();

	//fontion
	void loadTextureAdversaire();
	void loadTextureAdversairePortrait(String personnageChoisi);
	float anglePoints(int x1, int y1, int x2, int y2);
	float anglePointsDegree(int x1, int y1, int x2, int y2);

	void choixDeSesActions();

	void afficheAdversaire(RenderWindow& window);
	void effaceCaseEnregistrees();



	//attribut private
private:
	
};
#endif
