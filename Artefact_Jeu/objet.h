#ifndef OBJET_H
#define OBJET_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"
#include "perso.h"
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Objet {

	Mouse laSouris;
	Font ecriture;
	Text nomItem;

public:
	struct Item { int num;
				  Sprite image; };

	vector<Texture> listeTexture;
	vector<Item> inventairePerso;

	int numChoisi = -1;
	int numChoisiParRapportAInventaire = -1;

	//Proto du contructeur
	Objet();

	//fontion
	void loadTextureObjets();
	void afficheObjets(RenderWindow& window, bool enGros);
	void gainObjet(int num);
	String getNomObjet(int num);
	int numeroIndicateurObjetUtilisation(int num);
	void effetObjet(int num, vector<Perso>& leJoueur, int caseX, int caseY);

	string utilisationObjet(int num, vector<Perso>& leJoueur, int caseX, int caseY);
	char convertisseurCoordonneesVersLettres(int nombre);



	//attribut private
private:

};
#endif
