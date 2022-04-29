#include "adversaire.h"

//Constructeur perso 
Adversaire::Adversaire() {

};

Adversaire::Adversaire(int x, int y) {
	//attribut la position du joueur à sa génération
	setPosX(x);
	setPosY(y);
	sprite_adversaire.setPosition(posAdversaire.posX, posAdversaire.posY);
}

//Getter
Adversaire::Pos Adversaire::getPos(void) const
{
	return posAdversaire;
}

void Adversaire::setPosX(int x)
{
	posAdversaire.posX = x;
}
void Adversaire::setPosY(int y)
{
	posAdversaire.posY = y;
}

void Adversaire::loadTextureAdversaire() {
	if (!texture_adversaire.loadFromFile("res/img/helene.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_adversaire.setTexture(texture_adversaire);
	}
};

void Adversaire::afficheAdversaire(RenderWindow& window) {

	sprite_adversaire.setTextureRect(IntRect(0, 0, 64, 64));

	window.draw(sprite_adversaire);

}