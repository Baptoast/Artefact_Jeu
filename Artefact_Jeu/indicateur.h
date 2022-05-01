#ifndef INDICATEUR_H
#define INDICATEUR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Indicateur {

	Mouse laSouris;

	Sprite sprite_indicateur;
	Texture texture_indicateur;
	Sprite sprite_indicateur_possible;
	Texture texture_indicateur_possible;
	Sprite sprite_indicateur_impossible;
	Texture texture_indicateur_impossible;

	vector<Sprite> listeCasePossible;


public:
	//Proto du contructeur
	Indicateur();
	void afficheIndicateur(RenderWindow& window, int numType, int posJoueurX, int posJoueurY);
	void loadTextureIndicateur();
	bool casePossible(RenderWindow& window);


private:

};
#endif
