#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "input.h"
#include "sol.h"
#include "perso.h"
#include "baseDeDonnee.h"
#include "adversaire.h"
#include "salle.h"
#include "indicateur.h"
#include "hud.h"
#include "objet.h"
#include <Windows.h>
#include <vector>
#include <SFML/Network.hpp>

//Constantes du Programme
const int SCREEN_SIZE_WEIGHT = 960;
const int SCREEN_SIZE_HEIGHT = 960;

using namespace sf;
using namespace std;

class Jeu {
	View vue = View();
	Clock clk;
	Mouse laSouris;

	RenderWindow window;
	Font font;

	Input input;
	Event event;

	Sol sol;
	Perso perso;
	Adversaire adversaire1;
	Adversaire adversaire2;
	Adversaire adversaire3;
	Adversaire adversaire4;
	BaseDeDonnee bdd;
	Salle salle;
	Indicateur indicateur;
	Hud hud;

	Objet objets;
	//struct Case { int posX, posY; };
	//vector<Case> listeCase;
	bool initialisationPremiereCase = false;
	bool attenteCaseSuivante = false;
	bool confirmation = false;

	TcpSocket socket;
	Socket::Status status;

	int nombreActions = 0;
	int numeroJoueur = -1;

public:
	//Proto du contructeur
	Jeu();

	//getter

	//setter

	//fonction
	void creationJeu();
	void bouclePrincipale();
	void deroulementTour();
	bool isOpen();
	void boucleAlternative();
	void connexionAuServeur(int ticket);

	int convertisseurCoordonnees(char lettre);
	char convertisseurCoordonneesVersLettres(int nombre);
	int convertisseurIdObjets(char chiffre1, char chiffre2);

private:
	void loadFont();
	bool bloquageCameraX();
	bool bloquageCameraY();
};
#endif

