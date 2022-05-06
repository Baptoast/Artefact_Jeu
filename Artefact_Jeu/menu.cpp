#include "menu.h"

//Constructeur perso 
Menu::Menu() {

};

void Menu::creationMenu() {
	POINT Ecran = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

	window.create(VideoMode(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT), "Artefact");

	window.setPosition(Vector2i((Ecran.x / 2) - (Ecran.x / 5), Ecran.y / 18));

	vue.setSize(Vector2f(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT));
	vue.setCenter(SCREEN_SIZE_WEIGHT / 2, SCREEN_SIZE_HEIGHT / 2);
	//window.setActive(false);
}

void Menu::loadTextureMenu() {
	if (!texture_bouton.loadFromFile("res/img/valide.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_bouton.setTexture(texture_bouton);
		sprite_bouton.setPosition(SCREEN_SIZE_WEIGHT / 2 - 32, SCREEN_SIZE_HEIGHT / 2 - 32);
		sprite_bouton.setColor(Color(0, 0, 0, 255));
	}
	if (!texture_bg.loadFromFile("res/img/menu.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_bg.setTexture(texture_bg);
	}
}

bool Menu::isOpen() {
	return window.isOpen();
}


void Menu::bouclePrincipale() {

	window.clear(Color::Black);

	window.draw(sprite_bg);
	window.draw(sprite_bouton);

	window.setView(vue);
	window.display();

	int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY = laSouris.getPosition().y - window.getPosition().y;

	if (!estConnecte) {
		status = socket.connect("192.168.1.27", 53000);
		while (status != sf::Socket::Done){}
		sprite_bouton.setColor(Color(255,255,255,255));
		estConnecte = true;
	}
	if (sprite_bouton.getGlobalBounds().contains(positionSourisX, positionSourisY)) {
		window.close();
	}

	
}