#include "indicateur.h"

Indicateur::Indicateur() {

}

void Indicateur::afficheIndicateur(RenderWindow& window, int numType, int posJoueurX, int posJoueurY) {
	int positionSourisX =  laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY =  laSouris.getPosition().y - window.getPosition().y;

	int affichageX = (int) positionSourisX / 64;
	int affichageY = (int) positionSourisY / 64;
	if (numType == 1) {
		Sprite n0 = sprite_indicateur_possible;
		Sprite n1 = sprite_indicateur_possible;
		Sprite n2 = sprite_indicateur_possible;
		Sprite n3 = sprite_indicateur_possible;
		Sprite n4 = sprite_indicateur_possible;

		n0.setPosition(posJoueurX, posJoueurY);
		n1.setPosition(posJoueurX + 64, posJoueurY);
		n2.setPosition(posJoueurX - 64, posJoueurY);
		n3.setPosition(posJoueurX, posJoueurY + 64);
		n4.setPosition(posJoueurX, posJoueurY - 64);

		listeCasePossible.push_back(n0);
		listeCasePossible.push_back(n1);
		listeCasePossible.push_back(n2);
		listeCasePossible.push_back(n3);
		listeCasePossible.push_back(n4);

		sprite_indicateur.setPosition(affichageX * 64, affichageY * 64);
		window.draw(sprite_indicateur);
		window.draw(n0);
		window.draw(n1);
		window.draw(n2);
		window.draw(n3);
		window.draw(n4);
	}
}

bool Indicateur::casePossible(RenderWindow& window) {
	int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY = laSouris.getPosition().y - window.getPosition().y;

	for (Sprite casePoss : listeCasePossible) {
		if (casePoss.getGlobalBounds().contains(positionSourisX, positionSourisY)) {
			return true;
		}
	}
	return false;
}

void Indicateur::loadTextureIndicateur() {

	if (!texture_indicateur.loadFromFile("res/img/autorise.png") || !texture_indicateur_possible.loadFromFile("res/img/possible.png") || !texture_indicateur_impossible.loadFromFile("res/img/impossible.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		//Je charge la texture
		sprite_indicateur.setTexture(texture_indicateur);
		sprite_indicateur_possible.setTexture(texture_indicateur_possible);
		sprite_indicateur_impossible.setTexture(texture_indicateur_impossible);
	}

};