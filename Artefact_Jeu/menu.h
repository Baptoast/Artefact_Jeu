#ifndef MENU_H
#define MENU_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <SFML/Network.hpp>


//namespaces
using namespace sf;
using namespace std;

class Menu {
	const int SCREEN_SIZE_WEIGHT = 960;
	const int SCREEN_SIZE_HEIGHT = 960;
	Event event;
	View vue = View();
	

	Mouse laSouris;
	Font ecriture;

	Texture texture_bouton;
	Texture texture_bg;

	Texture texture_portrait_Jon;
	Texture texture_portrait_Helene;

	Texture texture_pasPret;
	Texture texture_Pret;

	vector<Sprite> portraitJoueurs;
	vector<Sprite> joueurPret;

	TcpSocket socket;
	Socket::Status status;
	bool estConnecte = false;
	bool demandeEstPret = false;
	int demandeChangementPerso = 1;

	int nbrDeJoueurCo = 1;

	bool queLaPartieCommence = false;

public:
	Sprite sprite_bouton;
	Sprite sprite_bg;

	Sprite sprite_portrait_Jon;
	Sprite sprite_portrait_Helene;

	RenderWindow window;

	//Proto du contructeur
	Menu();

	int connexionAuServeur();
	void creationMenu();
	void bouclePrincipale();
	void loadTextureMenu();
	void espaceServeur();

	bool isOpen();

private:

};
#endif
