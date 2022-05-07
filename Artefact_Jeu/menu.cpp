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
	if (!texture_bouton.loadFromFile("res/img/ready.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_bouton.setTexture(texture_bouton);
		sprite_bouton.setPosition(32, SCREEN_SIZE_HEIGHT - 180);
	}
	if (!texture_bg.loadFromFile("res/img/sol.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_bg.setTexture(texture_bg);
	}
	if (!texture_portrait_Helene.loadFromFile("res/img/portrait/Helene.png") || !texture_portrait_Jon.loadFromFile("res/img/portrait/Jon.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_portrait_Jon.setTexture(texture_portrait_Jon);
		sprite_portrait_Jon.setPosition(SCREEN_SIZE_WEIGHT/8-30, 60);
		sprite_portrait_Jon.setScale(Vector2f(2.5, 2.5));

		sprite_portrait_Helene.setTexture(texture_portrait_Helene);
		sprite_portrait_Helene.setPosition((SCREEN_SIZE_WEIGHT / 8)*3-30, 60);
		sprite_portrait_Helene.setScale(Vector2f(2.5, 2.5));
	}
	if (!texture_pasPret.loadFromFile("res/img/pasPret.png") || !texture_Pret.loadFromFile("res/img/pret.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
	}
}

bool Menu::isOpen() {
	return window.isOpen();
}

void Menu::connexionAuServeur() {
	cout << "etape1" << endl;
	status = socket.connect("192.168.1.27", 53000);
	while (status != Socket::Done) {}
	cout << "etape2" << endl;
	while (window.isOpen()) {
		char data[100];
		std::size_t received;

		sprintf_s(data, "nbrDeJoueurCo");
		if (socket.send(data, 100) != sf::Socket::Done) {}
		cout << "data envoyer" << endl;
		if (socket.receive(data, 100, received) != Socket::Done) {}
		sscanf_s(data, "%d", &nbrDeJoueurCo);
		cout << nbrDeJoueurCo << endl;
	}
}

void Menu::bouclePrincipale() {
	int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY = laSouris.getPosition().y - window.getPosition().y;

	
	window.clear(Color::Black);

	window.draw(sprite_bg);
	window.draw(sprite_bouton);
	window.draw(sprite_portrait_Jon);
	window.draw(sprite_portrait_Helene);

	if (nbrDeJoueurCo >= 1) {
		Sprite verif;
		verif.setTexture(texture_pasPret);
		verif.setPosition(SCREEN_SIZE_WEIGHT / 8 - 30, SCREEN_SIZE_HEIGHT/2-80);
		window.draw(verif);
	}
	if (nbrDeJoueurCo >= 2) {
		Sprite verif;
		verif.setTexture(texture_pasPret);
		verif.setPosition((SCREEN_SIZE_WEIGHT / 8)*4 - 30, SCREEN_SIZE_HEIGHT / 2 - 80);
		window.draw(verif);
	}

	window.setView(vue);
	window.display();

	/*
	char data[100];
	std::size_t received;

	// TCP socket:
	if (socket.receive(data, 100, received) != Socket::Done)
	{
		// error...
	}
	std::cout << "Recu : " << data << std::endl;

	char data2[100];
	sprintf_s(data2, "yo mec je suis le 1");

	// TCP socket:
	if (socket.send(data2, 100) != sf::Socket::Done) {}
	*/
	
}