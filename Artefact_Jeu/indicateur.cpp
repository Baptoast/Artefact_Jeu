#include "indicateur.h"

Indicateur::Indicateur() {

}

void Indicateur::updateIndicateur(int numTy, int x, int y) {
	numType = numTy;
	posJoueurX = x;
	posJoueurY = y;
}

void Indicateur::afficheIndicateur(RenderWindow& window, vector<int>& listeMurCaseX, vector<int>& listeMurCaseY) {
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

		bool n1Possible = true;
		bool n2Possible = true;
		bool n3Possible = true;
		bool n4Possible = true;

		for (int i = 0; i < listeMurCaseX.size(); i++)
		{
			for (int j = 0; j < listeMurCaseY.size(); j++)
			{
				if (listeMurCaseX.at(i) == posJoueurX + 64 && listeMurCaseY.at(i) == posJoueurY) {
					n1Possible = false;
				}
				if (listeMurCaseX.at(i) == posJoueurX - 64 && listeMurCaseY.at(i) == posJoueurY) {
					n2Possible = false;
				}
				if (listeMurCaseX.at(i) == posJoueurX && listeMurCaseY.at(i) == posJoueurY +64) {
					n3Possible = false;
				}
				if (listeMurCaseX.at(i) == posJoueurX && listeMurCaseY.at(i) == posJoueurY -64) {
					n4Possible = false;
				}
			}
		}
		n0.setPosition(posJoueurX, posJoueurY);
		n1.setPosition(posJoueurX + 64, posJoueurY);
		n2.setPosition(posJoueurX - 64, posJoueurY);
		n3.setPosition(posJoueurX, posJoueurY + 64);
		n4.setPosition(posJoueurX, posJoueurY - 64);

		listeCasePossible.push_back(n0);
		window.draw(n0);
		if (n1Possible) {
			listeCasePossible.push_back(n1);
			window.draw(n1);
		}
		if (n2Possible) {
			listeCasePossible.push_back(n2);
			window.draw(n2);
		}
		if (n3Possible) {
			listeCasePossible.push_back(n3);
			window.draw(n3);
		}
		if (n4Possible) {
			listeCasePossible.push_back(n4);
			window.draw(n4);
		}
		
		sprite_indicateur.setPosition(affichageX * 64, affichageY * 64);
		window.draw(sprite_indicateur);
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