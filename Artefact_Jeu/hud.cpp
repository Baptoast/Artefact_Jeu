#include "hud.h"

Hud::Hud() {

}

void Hud::afficheHud(RenderWindow& window, Objet& objets, vector<Perso>& leJoueur, vector<Adversaire>& adversaires) {

	if (hud_Actif) {
		if (!inventaireGros) {
			sprite_inventaire.setScale(Vector2f(1, 1));
			sprite_inventaire.setPosition(window.getPosition().x - 140, window.getPosition().y + ((window.getSize().y / 100) * 87));
			window.draw(sprite_inventaire);
			objets.afficheObjets(window, false);
		}

		leJoueur.at(0).sprite_portrait.setPosition(calculDistanceOrdreJoueursX(leJoueur.at(0).numeroDeFile,window), calculDistanceOrdreJoueursY(leJoueur.at(0).numeroDeFile, window));
		for (Adversaire var : adversaires) {
			var.sprite_portrait.setPosition(calculDistanceOrdreJoueursX(var.numeroDeFile, window), calculDistanceOrdreJoueursY(var.numeroDeFile, window));
			window.draw(var.sprite_portrait);
		}
		window.draw(leJoueur.at(0).sprite_portrait);

		sprite_bulleEmote.setPosition(window.getPosition().x - 400, window.getPosition().y + ((window.getSize().y / 100) * 88));
		sprite_ordreJoueurs.setPosition(window.getPosition().x + 400, window.getPosition().y + ((window.getSize().y / 100) * 30));
		sprite_tempsTour.setPosition(window.getPosition().x - 450, window.getPosition().y - 25);

		window.draw(sprite_bulleEmote);
		window.draw(sprite_ordreJoueurs);
		window.draw(sprite_tempsTour);

		for (Sprite var : vieJoueur)
		{
			window.draw(var);
		}
	}
	if (menuAction) {
		menuActionReaction(window);
		window.draw(sprite_conteneurActions);
		window.draw(sprite_hexaDeplacement);
		window.draw(sprite_hexaFouille);
		window.draw(sprite_hexaObjets);
		window.draw(sprite_hexaEboulement);
	}
	if (confirmationChoix) {
		sprite_confirmation.setPosition(30, 700);
		window.draw(sprite_confirmation);
	}
	if (inventaireGros) {
		sprite_inventaire.setPosition(window.getPosition().x - 280, window.getPosition().y + ((window.getSize().y / 100) * 50));
		sprite_inventaire.setScale(Vector2f(2,2));
		window.draw(sprite_inventaire);
		objets.afficheObjets(window,true);
	}
}

int Hud::calculDistanceOrdreJoueursX(int num, RenderWindow& window) {
	switch (num)
	{
	case 0:
		return window.getPosition().x + 400 + 3;
		break;
	case 1:
		return window.getPosition().x + 400 + 6;
		break;
	case 2:
		return window.getPosition().x + 400 + 6;
		break;
	case 3:
		return window.getPosition().x + 400 + 6;
		break;
	}
	return 0;
}

int Hud::calculDistanceOrdreJoueursY(int num, RenderWindow& window) {
	switch (num)
	{
	case 0:
		return window.getPosition().y + ((window.getSize().y / 100) * 30) + 3;
		break;
	case 1:
		return window.getPosition().y + ((window.getSize().y / 100) * 38);
		break;
	case 2:
		return window.getPosition().y + ((window.getSize().y / 100) * 44);
		break;
	case 3:
		return  window.getPosition().y + ((window.getSize().y / 100) * 52);
		break;
	}
	return 0;
}

void Hud::menuActionReaction(RenderWindow& window) {
	int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY = laSouris.getPosition().y - window.getPosition().y;

	if (sprite_hexaDeplacement.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		cout << "clique deplacement" << endl;
		actionDeplacement = true;
		menuAction = false;
	}
	else if (sprite_hexaFouille.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		cout << "clique fouille" << endl;
		actionFouille = true;
		menuAction = false;
	}
	else if (sprite_hexaObjets.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		cout << "clique utilisation objet" << endl;
		actionObjets = true;
		menuAction = false;
	}
	else if (sprite_hexaEboulement.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		cout << "clique declenchement eboulement" << endl;
		actionEboulement = true;
		menuAction = false;
	}
}

void Hud::confirmationBouton(RenderWindow& window) {
	int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY = laSouris.getPosition().y - window.getPosition().y;

	if (sprite_confirmation.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		cout << "confirmation" << endl;
		confirmationChoix = false;
	}
}

void Hud::loadTextureHud(RenderWindow& window) {

	if (!texture_inventaire.loadFromFile("res/img/inventaire.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		//Je charge la texture
		sprite_inventaire.setTexture(texture_inventaire);
	}
	if (!texture_bulleEmote.loadFromFile("res/img/bulleEmote.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		//Je charge la texture
		sprite_bulleEmote.setTexture(texture_bulleEmote);
	}
	if (!texture_ordreJoueurs.loadFromFile("res/img/ordreJoueurs.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		//Je charge la texture
		sprite_ordreJoueurs.setTexture(texture_ordreJoueurs);
	}
	if (!texture_tempsTour.loadFromFile("res/img/tempsTour.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		//Je charge la texture
		sprite_tempsTour.setTexture(texture_tempsTour);
	}
	if (!texture_coeurPasActif.loadFromFile("res/img/coeurPasActif.png") || !texture_coeur.loadFromFile("res/img/coeur.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		Sprite c1, c2, c3, c4, c5, c6, c7, c8;
		c1.setTexture(texture_coeur);
		c2.setTexture(texture_coeur);
		c3.setTexture(texture_coeur);
		c4.setTexture(texture_coeur);
		c5.setTexture(texture_coeurPasActif);
		c6.setTexture(texture_coeurPasActif);
		c7.setTexture(texture_coeurPasActif);
		c8.setTexture(texture_coeurPasActif);
		vieJoueur.push_back(c1);
		vieJoueur.push_back(c2);
		vieJoueur.push_back(c3);
		vieJoueur.push_back(c4);
		vieJoueur.push_back(c5);
		vieJoueur.push_back(c6);
		vieJoueur.push_back(c7);
		vieJoueur.push_back(c8);
		for (int i = 0; i < vieJoueur.size(); i++)
		{
			vieJoueur.at(i).setPosition(8, 200+i*60);
		}
	}
	if (!texture_conteneurActions.loadFromFile("res/img/conteneurActions.png") || !texture_hexaDeplacement.loadFromFile("res/img/hexaDeplacement.png") || !texture_hexaEboulement.loadFromFile("res/img/hexaEboulement.png") || !texture_hexaObjets.loadFromFile("res/img/hexaObjets.png") || !texture_hexaFouille.loadFromFile("res/img/hexaFouille.png") || !texture_confirmation.loadFromFile("res/img/confirmation.png")) {
		cout << "erreur de chargement du background" << endl;
	}
	else {
		sprite_conteneurActions.setTexture(texture_conteneurActions);
		sprite_hexaDeplacement.setTexture(texture_hexaDeplacement);
		sprite_hexaFouille.setTexture(texture_hexaFouille);
		sprite_hexaObjets.setTexture(texture_hexaObjets);
		sprite_hexaEboulement.setTexture(texture_hexaEboulement);
		sprite_confirmation.setTexture(texture_confirmation);

		sprite_conteneurActions.setPosition(30,320);
		sprite_hexaDeplacement.setPosition(50, 360);
		sprite_hexaFouille.setPosition(270, 360);
		sprite_hexaObjets.setPosition(490, 360);
		sprite_hexaEboulement.setPosition(710, 360);
		
	}


};