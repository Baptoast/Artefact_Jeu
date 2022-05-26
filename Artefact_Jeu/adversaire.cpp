#include "adversaire.h"

//Constructeur perso 
Adversaire::Adversaire() {

};

Adversaire::Adversaire(int x, int y) {
	//attribut la position du joueur à sa génération
	setPosX(x);
	setPosY(y);
	sprite_adversaire.setPosition(posAdversaire.posX, posAdversaire.posY);
	pv = 4;
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
	Texture text_jon;
	Texture text_helene;
	Texture text_mickael;
	Texture text_teneia;
	texture_adversaire.push_back(text_jon);
	texture_adversaire.push_back(text_helene);
	texture_adversaire.push_back(text_mickael);
	texture_adversaire.push_back(text_teneia);

	if (!texture_adversaire.at(0).loadFromFile("res/img/portrait/Jon_sprite.png") || !texture_adversaire.at(1).loadFromFile("res/img/portrait/Helene_sprite.png") || !texture_adversaire.at(2).loadFromFile("res/img/portrait/Mickael_sprite.png") || !texture_adversaire.at(3).loadFromFile("res/img/portrait/Teneia_sprite.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_adversaire.setTexture(texture_adversaire.at(0));
	}
};

void Adversaire::loadTextureAdversairePortrait(String personnageChoisi) {
	if (!texture_portrait.loadFromFile("res/img/portrait/" + personnageChoisi + ".png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_portrait.setTexture(texture_portrait);
	}
};

void Adversaire::afficheAdversaire(RenderWindow& window) {

	sprite_adversaire.setTextureRect(IntRect(0, 0, 48, 48));

	sprite_adversaire.setPosition(posAdversaire.posX + 8, posAdversaire.posY + 8);

	window.draw(sprite_adversaire);

}

void Adversaire::choixDeSesActions() {
	listeCase.clear();
	int caseX = posAdversaire.posX;
	int caseY = posAdversaire.posY;

	srand(time(NULL));
	int i = 0;
	while (i < 3) {

		Case caseSuivante;
		int alea1 = rand() % 4;

		//Droite
		if (alea1 == 0) {
			caseSuivante.posX = caseX + 64;
			caseSuivante.posY = caseY;
			
		}
		//Bas
		else if (alea1 == 1) {
			caseSuivante.posX = caseX;
			caseSuivante.posY = caseY + 64;
		}
		//Gauche
		else if (alea1 == 2) {
			caseSuivante.posX = caseX - 64;
			caseSuivante.posY = caseY;
		}
		//Haut
		else {
			caseSuivante.posX = caseX;
			caseSuivante.posY = caseY - 64;
		}
		if (caseSuivante.posX > 0 && caseSuivante.posX < 960 && caseSuivante.posY > 0 && caseSuivante.posY < 960) {
			i++;
			caseX = caseSuivante.posX;
			caseY = caseSuivante.posY;
			listeCase.push_back(caseSuivante);
		}
	}
}