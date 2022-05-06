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

	View vue = View();
	RenderWindow window;

	Mouse laSouris;

	Texture texture_bouton;
	Texture texture_bg;

	TcpSocket socket;
	Socket::Status status;
	bool estConnecte = false;

public:
	Sprite sprite_bouton;
	Sprite sprite_bg;

	//Proto du contructeur
	Menu();

	void creationMenu();
	void bouclePrincipale();
	void loadTextureMenu();

	bool isOpen();

private:

};
#endif
