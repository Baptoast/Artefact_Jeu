#include "salle.h"

Salle::Salle() {

}

Salle::Salle(int numMap) {
	numeroMap = numMap;
	choixMap(1);
}

void Salle::choixMap(int num) {
	
	int map1[225] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,
					 1,1,0,0,0,0,0,0,0,0,0,0,0,1,1, 
					 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 
					 1,0,0,0,0,0,1,0,1,0,0,0,0,0,1, 
					 1,0,0,0,0,0,1,0,1,0,0,0,0,0,1, 
					 1,0,0,0,1,1,1,0,1,1,1,0,0,0,1, 
					 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 
					 1,0,0,0,1,1,1,0,1,1,1,0,0,0,1, 
					 1,0,0,0,0,0,1,0,1,0,0,0,0,0,1, 
					 1,0,0,0,0,0,1,0,1,0,0,0,0,0,1, 
					 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 
					 1,1,0,0,0,0,0,0,0,0,0,0,0,1,1, 
					 1,1,1,0,0,0,0,0,0,0,0,0,1,1,1, 
					 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	for (int i = 0; i < 225; i++)
	{
		mapChoisi[i] = map1[i];
	}
	for (int i = 0; i < 225 * 64; i += 64) {
		switch (mapChoisi[i / 64])
		{
		case 0:
			break;
		case 1:
			posXmurs.push_back(i % 960);
			posYmurs.push_back((i / 960) * 64);
			break;
		default:
			break;
		}
	}

	
}

void Salle::afficheSalle(RenderWindow& window) {
	for (int i = 0; i < 225*64 ; i+=64) {
		switch (mapChoisi[i/64])
		{
		case 0:
			break;
		case 1:
			sprite_mur.setPosition(i % 960, (i / 960) * 64);
			sprite_mur.setTextureRect(IntRect(0, 0, 64, 64));
			window.draw(sprite_mur);
			break;
		default:
			break;
		}
	}
}

void Salle::loadTextureSalle() {

	if (!texture_mur.loadFromFile("res/img/mur.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		//Je charge la texture
		sprite_mur.setTexture(texture_mur);
	}
};