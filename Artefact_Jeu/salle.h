#ifndef SALLE_H
#define SALLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Salle {
	
	int numeroMap;
	int mapChoisi[225];

	Sprite sprite_mur;
	Texture texture_mur;


public:
	vector<int> posXmurs;
	vector<int> posYmurs;

	//Proto du contructeur
	Salle();
	Salle(int numMap);
	void afficheSalle(RenderWindow& window);
	void loadTextureSalle();


private:
	void choixMap(int num);
	
};
#endif


