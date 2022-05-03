#include "baseDeDonnee.h"

//Constructeur perso 
BaseDeDonnee::BaseDeDonnee() {

};

void BaseDeDonnee::ajoutJoueur(Perso& perso, String personnageChoisi) {
	leJoueur.push_back(perso);
	leJoueur.at(0).loadTexturePerso();
	leJoueur.at(0).loadTexturePersoPortrait(personnageChoisi);
}

void BaseDeDonnee::updateJoueur(int x, int y) {
	leJoueur.at(0).setPosX(x);
	leJoueur.at(0).setPosY(y);
	leJoueur.at(0).sprite_perso.setPosition(x,y);
	leJoueur.at(0).sprite_vision.setPosition(x - 175 + 32, y - 175 + 32);
}

void BaseDeDonnee::ajoutAdversaires(Adversaire& adv1, Adversaire& adv2, Adversaire& adv3) {
	listeAdversaire.push_back(adv1);
	listeAdversaire.push_back(adv2);
	listeAdversaire.push_back(adv3);
	listeAdversaire.at(0).loadTextureAdversaire();
	listeAdversaire.at(1).loadTextureAdversaire();
	listeAdversaire.at(2).loadTextureAdversaire();
}

void BaseDeDonnee::affichageChosesDansVision(RenderWindow& window) {
	leJoueur.at(0).affichePerso(window);
	for (int i = 0; i < listeAdversaire.size(); i++)
	{
		if (dansChampDeVision(listeAdversaire.at(i).getPos().posX, listeAdversaire.at(i).getPos().posY)) {
			listeAdversaire.at(i).afficheAdversaire(window);
		}
	}
}

bool BaseDeDonnee::dansChampDeVision(int x, int y) {
	int positionJoueurX = leJoueur.at(0).getPos().posX;
	int positionJoueurY = leJoueur.at(0).getPos().posY;

	if (x >= positionJoueurX - 2 * 64 && x <= positionJoueurX + 3 * 64 && y >= positionJoueurY + 64 && y <= positionJoueurY) {
		return true;
	}
	if (y >= positionJoueurY - 2 * 64 && y <= positionJoueurY + 3 * 64 && x >= positionJoueurX + 64 && x <= positionJoueurX) {
		return true;
	}
	if (x >= positionJoueurX - 1 * 64 && x <= positionJoueurX + 2 * 64 && y >= positionJoueurY - 1 * 64 && y <= positionJoueurY + 2 * 64) {
		return true;
	}
	return false;
}