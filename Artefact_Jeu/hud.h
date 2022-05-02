#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Hud {

	Mouse laSouris;

	//HUD ACTIF
	Sprite sprite_inventaire;
	Texture texture_inventaire;
	Sprite sprite_bulleEmote;
	Texture texture_bulleEmote;
	Sprite sprite_ordreJoueurs;
	Texture texture_ordreJoueurs;
	Sprite sprite_tempsTour;
	Texture texture_tempsTour;
	vector<Sprite> vieJoueur;
	Texture texture_coeur;
	Texture texture_coeurVide;
	Texture texture_coeurPasActif;
	
	//MENU ACTION ACTIF
	Sprite sprite_conteneurActions;
	Texture texture_conteneurActions;
	Sprite sprite_hexaDeplacement;
	Texture texture_hexaDeplacement;
	Sprite sprite_hexaFouille;
	Texture texture_hexaFouille;
	Sprite sprite_hexaObjets;
	Texture texture_hexaObjets;
	Sprite sprite_hexaEboulement;
	Texture texture_hexaEboulement;
	Sprite sprite_confirmation;
	Texture texture_confirmation;

public:
	//Proto du contructeur
	Hud();
	void afficheHud(RenderWindow& window);
	void loadTextureHud(RenderWindow& window);
	void menuActionReaction(RenderWindow& window);
	void confirmationBouton(RenderWindow& window);
	bool hud_Actif = false;
	bool menuAction = true;
	bool actionDeplacement = false;
	bool actionFouille = false;
	bool actionObjets = false;
	bool actionEboulement = false;
	bool confirmationChoix = false;

private:

};
#endif

