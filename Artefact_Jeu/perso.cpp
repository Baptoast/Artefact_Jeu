#include "perso.h"

//Constructeur perso 
Perso::Perso() {

};

Perso::Perso(int x, int y) {
    //attribut la position du joueur à sa génération
    setPosX(x);
    setPosY(y);
	sprite_perso.setPosition(posJoueur.posX,posJoueur.posY);
	sprite_vision.setPosition(posJoueur.posX-175+32, posJoueur.posY - 175+32);
}

//Getter
Perso::Pos Perso::getPos(void) const
{
    return posJoueur;
}

void Perso::setPosX(int x)
{
    posJoueur.posX = x;
}
void Perso::setPosY(int y)
{
    posJoueur.posY = y;
}

void Perso::loadTexturePerso() {
    if (!texture_perso.loadFromFile("res/img/jon.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_perso.setTexture(texture_perso);
	}
	if (!texture_vision.loadFromFile("res/img/vision.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_vision.setTexture(texture_vision);
	}
};

void Perso::affichePerso(RenderWindow& window) {

	sprite_vision.setTextureRect(IntRect(0, 0, 350, 350));
	sprite_perso.setTextureRect(IntRect(0, 0, 64, 64));

	window.draw(sprite_vision);
	window.draw(sprite_perso);

}