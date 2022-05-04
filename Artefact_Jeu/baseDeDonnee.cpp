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

void BaseDeDonnee::ajoutAdversaires(Adversaire& adv1, Adversaire& adv2, Adversaire& adv3, String personnageChoisi1, String personnageChoisi2, String personnageChoisi3) {
	listeAdversaire.push_back(adv1);
	listeAdversaire.push_back(adv2);
	listeAdversaire.push_back(adv3);
	listeAdversaire.at(0).loadTextureAdversaire();
	listeAdversaire.at(1).loadTextureAdversaire();
	listeAdversaire.at(2).loadTextureAdversaire();
	listeAdversaire.at(0).loadTextureAdversairePortrait(personnageChoisi1);
	listeAdversaire.at(1).loadTextureAdversairePortrait(personnageChoisi2);
	listeAdversaire.at(2).loadTextureAdversairePortrait(personnageChoisi3);
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

	if (x >= positionJoueurX - 2 * 64 && x <= positionJoueurX + 3 * 64 && y >= positionJoueurY && y <= positionJoueurY) {
		return true;
	}
	if (y >= positionJoueurY - 2 * 64 && y <= positionJoueurY + 3 * 64 && x >= positionJoueurX && x <= positionJoueurX) {
		return true;
	}
	if (x >= positionJoueurX - 1 * 64 && x <= positionJoueurX + 1 * 64 && y >= positionJoueurY - 1 * 64 && y <= positionJoueurY + 1 * 64) {
		return true;
	}
	return false;
}

//Attend que tout le monde (y compris nous) aies choisi
bool BaseDeDonnee::attenteDesAutresJoueurs() {
	if (leJoueur.at(0).choix != 0) { //&& que les autres joueurs ont choisi
		return false;
	}
	return true;
}

void BaseDeDonnee::melangeOrdreDePassage() {
	int ancienNumeroJoueur = leJoueur.at(0).numeroDeFile;
	vector<int> numAdv;
	numAdv.push_back(listeAdversaire.at(0).numeroDeFile);
	numAdv.push_back(listeAdversaire.at(1).numeroDeFile);
	numAdv.push_back(listeAdversaire.at(2).numeroDeFile);

	int memo1;
	int memo2;
	int memo3;

	vector<int> urne;

	bool redone = true;
	while (redone) {
		urne.clear();
		urne.push_back(0);
		urne.push_back(1);
		urne.push_back(2);
		urne.push_back(3);

		memo1 = -1;
		memo2 = -1;
		memo3 = -1;

		srand((unsigned int)time(0));

		int alea1 = rand() % 4;
		while (urne.at(alea1) == ancienNumeroJoueur) {
			alea1 = rand() % 4;
		}
		memo1 = urne.at(alea1);
		urne.erase(urne.begin() + alea1);

		alea1 = rand() % 3;
		while (urne.at(alea1) == listeAdversaire.at(0).numeroDeFile) {
			alea1 = rand() % 3;
		}
		memo2 = urne.at(alea1);
		urne.erase(urne.begin() + alea1);

		alea1 = rand() % 2;
		while (urne.at(alea1) == listeAdversaire.at(1).numeroDeFile) {
			alea1 = rand() % 2;
		}
		memo3 = urne.at(alea1);
		urne.erase(urne.begin() + alea1);

		if (urne.at(0) != listeAdversaire.at(2).numeroDeFile) {
			redone = false;
		}
	}
	leJoueur.at(0).numeroDeFile = memo1;
	listeAdversaire.at(0).numeroDeFile = memo2;
	listeAdversaire.at(1).numeroDeFile = memo3;
	listeAdversaire.at(2).numeroDeFile = urne.at(0);
}