#ifndef SOL_H
#define SOL_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Sol {

	int numeroMap;

	Sprite sprite_sol;
	Texture texture_sol;


public:
	//Proto du contructeur
	Sol();
	Sol(int numMap);
	void afficheSol(RenderWindow& window);
	void loadTextureSol();


private:

};
#endif





