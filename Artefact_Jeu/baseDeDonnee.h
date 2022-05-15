#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "adversaire.h"
#include "perso.h"
#include "hud.h"
#include "objet.h"

using namespace sf;
using namespace std;

class BaseDeDonnee {

	Clock deplacementClock;

public:
	vector<Perso> leJoueur;
	vector<Adversaire> listeAdversaire;

	//Proto du contructeur
	BaseDeDonnee();

	bool dansChampDeVision(int x, int y);
	void affichageChosesDansVision(RenderWindow& window);
	void ajoutJoueur(Perso& perso, String personnageChoisi);
	void updateJoueur(int x, int y);
	void ajoutAdversaires(Adversaire& adv1, Adversaire& adv2, Adversaire& adv3, Adversaire& adv4, String personnageChoisi1, String personnageChoisi2, String personnageChoisi3, String personnageChoisi4);
	bool attenteDesAutresJoueurs();
	void melangeOrdreDePassage();
	void resolutionActions(Objet& objets, Hud& hud, RenderWindow& window);

private:

};
#endif




