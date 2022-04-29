#include "sol.h"

Sol::Sol() {

}

Sol::Sol(int numMap) {
	numeroMap = numMap;
}

void Sol::afficheSol(RenderWindow& window) {
	switch (numeroMap)
	{
	case 1:
		sprite_sol.setTextureRect(IntRect(0, 0, 960, 960));
		window.draw(sprite_sol);
		break;
	default:
		break;
	}

}

void Sol::loadTextureSol() {

	if (!texture_sol.loadFromFile("res/img/sol.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		//Je charge la texture
		sprite_sol.setTexture(texture_sol);
	}

};