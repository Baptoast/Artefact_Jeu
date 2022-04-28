#ifndef SALLE_H
#define SALLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Salle {
	
	int numeroMap;
	int mapChoisi[225];

	Sprite sprite_sol;
	Texture texture_sol;

	Sprite sprite_mur;
	Texture texture_mur;


public:
	//Proto du contructeur
	Salle();
	Salle(int numMap);
	void afficheSalle(RenderWindow& window);
	void LoadTextureSalle();


private:
	void choixMap(int num);
	
};
#endif


