#include "baseDeDonnee.h"

//Constructeur perso 
BaseDeDonnee::BaseDeDonnee() {

};

void BaseDeDonnee::ajoutJoueur(Perso& perso, String personnageChoisi) {
	leJoueur.push_back(perso);
	leJoueur.at(0).loadTexturePerso(1);
	leJoueur.at(0).loadTexturePersoPortrait(personnageChoisi);
	srand(time(NULL));
}

void BaseDeDonnee::updateJoueur(int x, int y) {
	leJoueur.at(0).setPosX(x);
	leJoueur.at(0).setPosY(y);
	leJoueur.at(0).sprite_perso.setPosition(x,y);
	leJoueur.at(0).sprite_vision.setPosition(x - 175 + 32, y - 175 + 32);
}

void BaseDeDonnee::ajoutAdversaires(Adversaire& adv1, Adversaire& adv2, Adversaire& adv3, Adversaire& adv4, String personnageChoisi1, String personnageChoisi2, String personnageChoisi3, String personnageChoisi4) {
	listeAdversaire.push_back(adv1);
	listeAdversaire.push_back(adv2);
	listeAdversaire.push_back(adv3);
	listeAdversaire.push_back(adv4);
	listeAdversaire.at(0).loadTextureAdversaire();
	listeAdversaire.at(1).loadTextureAdversaire();
	listeAdversaire.at(2).loadTextureAdversaire();
	listeAdversaire.at(3).loadTextureAdversaire();
	listeAdversaire.at(0).loadTextureAdversairePortrait(personnageChoisi1);
	listeAdversaire.at(1).loadTextureAdversairePortrait(personnageChoisi2);
	listeAdversaire.at(2).loadTextureAdversairePortrait(personnageChoisi3);
	listeAdversaire.at(3).loadTextureAdversairePortrait(personnageChoisi4);
}

void BaseDeDonnee::affichageChosesDansVision(RenderWindow& window) {
	
	leJoueur.at(0).affichePerso(window);

	for (int i = 0; i < listeAdversaire.size(); i++)
	{
		//cout << listeAdversaire.at(i).sprite_adversaire.getPosition().x << endl;
		if (dansChampDeVision(listeAdversaire.at(i).posAdversaire.posX, listeAdversaire.at(i).posAdversaire.posY)) {
			listeAdversaire.at(i).afficheAdversaire(window);
		}
	}
}

bool BaseDeDonnee::dansChampDeVision(int x, int y) {
	int positionJoueurX = leJoueur.at(0).getPos().posX;
	int positionJoueurY = leJoueur.at(0).getPos().posY;

	if (x >= positionJoueurX - 2 * 64 && x <= positionJoueurX + 2 * 64 && y >= positionJoueurY && y <= positionJoueurY) {
		return true;
	}
	if (y >= positionJoueurY - 2 * 64 && y <= positionJoueurY + 2 * 64 && x >= positionJoueurX && x <= positionJoueurX) {
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

/*
void BaseDeDonnee::resolutionActions(Objet& objets, Hud& hud, RenderWindow& window) {
	for (int i = 0; i < 4; i++)
	{
		if (leJoueur.at(0).numeroDeFile == i) {
			//Deplacement
			if (leJoueur.at(0).choix == 1) {
				for (int i = 0; i < leJoueur.at(0).listeCase.size(); i++) {
					while (deplacementClock.getElapsedTime().asMilliseconds() < 1250);
					updateJoueur(leJoueur.at(0).listeCase.at(i).posX, leJoueur.at(0).listeCase.at(i).posY);
					deplacementClock.restart();
				}
			}
			//Fouilles
			else if (leJoueur.at(0).choix == 2) {
				objets.gainObjet(0);

			}
			//Utilisation d'un Objet
			else if (leJoueur.at(0).choix == 3) {
				objets.effetObjet(objets.numChoisi, leJoueur, leJoueur.at(0).listeCase.at(0).posX, leJoueur.at(0).listeCase.at(0).posY);
				objets.inventairePerso.erase(objets.inventairePerso.begin() + objets.numChoisiParRapportAInventaire);
				objets.numChoisiParRapportAInventaire = -1;
				objets.numChoisi = -1;
			}
			hud.menuAction = true;
			hud.hud_Actif = false;
			leJoueur.at(0).listeCase.clear();
			leJoueur.at(0).choix = 0;
		}
		else {
			
			for (int t = 0; t < 3; t++) {
				if (listeAdversaire.at(t).numeroDeFile == i) {
					if (listeAdversaire.at(t).choix == 1) {
						for (int k = 0; k < listeAdversaire.at(t).listeCase.size(); k++) {
							while (deplacementClock.getElapsedTime().asMilliseconds() < 1250);
							listeAdversaire.at(t).posAdversaire.posX = listeAdversaire.at(t).listeCase.at(k).posX;
							listeAdversaire.at(t).posAdversaire.posY = listeAdversaire.at(t).listeCase.at(k).posY;
							listeAdversaire.at(t).sprite_adversaire.setPosition(listeAdversaire.at(t).posAdversaire.posX, listeAdversaire.at(t).posAdversaire.posY);
							deplacementClock.restart();
						}
					}
				}
			}
		}
	}
	melangeOrdreDePassage();
	for (int u = 0; u < 3; u++) {
		listeAdversaire.at(u).choixDeSesActions();
	}
}*/