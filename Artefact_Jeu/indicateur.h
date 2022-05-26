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

	int numType = -1;
	int posJoueurX = -64;
	int posJoueurY = -64;


public:
	vector<Sprite> listeCasePossible;

	//Proto du contructeur
	Indicateur();
	void afficheIndicateur(RenderWindow& window);
	void updateIndicateur(int numType, int posJoueurX, int posJoueurY, vector<int>& listeMurCaseX, vector<int>& listeMurCaseY);
	void loadTextureIndicateur();
	bool casePossible(RenderWindow& window);


private:

};
#endif
