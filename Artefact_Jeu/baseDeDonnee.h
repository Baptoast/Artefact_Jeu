#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "adversaire.h"
#include "perso.h"

using namespace sf;
using namespace std;

class BaseDeDonnee {

	vector<Adversaire> listeAdversaire;
	vector<Perso> leJoueur;


public:
	//Proto du contructeur
	BaseDeDonnee();

	bool dansChampDeVision(int x, int y);
	void affichageChosesDansVision(RenderWindow& window);
	void ajoutJoueur(Perso& perso);
	void ajoutAdversaires(Adversaire& adv1, Adversaire& adv2, Adversaire& adv3);


private:

};
#endif




