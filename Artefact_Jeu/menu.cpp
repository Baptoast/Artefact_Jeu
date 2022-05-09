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

	Sprite portraitJoueur1;
	Sprite portraitJoueur2;
	Sprite portraitJoueur3;
	Sprite portraitJoueur4;
	portraitJoueurs.push_back(portraitJoueur1);
	portraitJoueurs.push_back(portraitJoueur2);
	portraitJoueurs.push_back(portraitJoueur3);
	portraitJoueurs.push_back(portraitJoueur4);

	Sprite joueur1pret;
	Sprite joueur2pret;
	Sprite joueur3pret;
	Sprite joueur4pret;
	joueurPret.push_back(joueur1pret);
	joueurPret.push_back(joueur2pret);
	joueurPret.push_back(joueur3pret);
	joueurPret.push_back(joueur4pret);
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
	if (!ecriture.loadFromFile("res/img/font/chinese rocks rg.otf")) {
		cout << "erreur de chargement de l'ecriture" << endl;
	}
	else {
	}
}

bool Menu::isOpen() {
	return window.isOpen();
}

int Menu::connexionAuServeur() {
	status = socket.connect("192.168.1.27", 53000);
	while (status != Socket::Done) {}

	while (window.isOpen()) {
		char data[100];
		std::size_t received;

		//Demande du nombre de joueur
		sprintf_s(data, "nbrDeJoueurCo");
		if (socket.send(data, 100) != Socket::Done) {}
		if (socket.receive(data, 100, received) != Socket::Done) {}
		sscanf_s(data, "%d", &nbrDeJoueurCo);

		//Demande des personnages choisi par chaques joueurs
		sprintf_s(data, "portraitsJoueurs");
		if (socket.send(data, 100) != Socket::Done) {}
		if (socket.receive(data, 100, received) != Socket::Done) {}
		for (int k = 0; k < nbrDeJoueurCo; k++) {
			if (data[k] == '0') {
				portraitJoueurs.at(k).setTexture(texture_portrait_Jon);
			}else if (data[k] == '1') {
				portraitJoueurs.at(k).setTexture(texture_portrait_Helene);
			}
			
		}

		//Demande qui est pret
		sprintf_s(data, "joueursPret");
		if (socket.send(data, 100) != Socket::Done) {}
		if (socket.receive(data, 100, received) != Socket::Done) {}
		for (int k = 0; k < nbrDeJoueurCo; k++) {

			if (data[k] == '0') {
				joueurPret.at(k).setTexture(texture_pasPret);
			}
			else if (data[k] == '1') {
				joueurPret.at(k).setTexture(texture_Pret);
			}

		}

		//Envoie d'une demande de changement de perso
		if (demandeChangementPerso != -1) {
			if (demandeChangementPerso == 0) {
				sprintf_s(data, "ChangePersonnageJon");
			}
			else if (demandeChangementPerso == 1) {
				sprintf_s(data, "ChangePersonnageHelene");
			}
			if (socket.send(data, 100) != Socket::Done) {}
			demandeChangementPerso = -1;
		}

		//Envoie d'une demande de confirmation que l'on veux être pret
		if (demandeEstPret) {
			sprintf_s(data, "readyBro");
			if (socket.send(data, 100) != Socket::Done) {}
			demandeEstPret = false;
		}

		//Demande si la partie peux commencer
		sprintf_s(data, "debutDeLaPartie");
		if (socket.send(data, 100) != Socket::Done) {}
		if (socket.receive(data, 100, received) != Socket::Done) {}
		if (data[0] == '1' || data[0] == '2'|| data[0] == '3' || data[0] == '4') {
			queLaPartieCommence = true;
			return (int)data[0] - 48;
		}
		
		
	}
}

void Menu::bouclePrincipale() {
	int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY = laSouris.getPosition().y - window.getPosition().y;
	if (window.pollEvent(event)) {
	}
	
	window.clear(Color::Black);

	window.draw(sprite_bg);
	window.draw(sprite_bouton);
	window.draw(sprite_portrait_Jon);
	window.draw(sprite_portrait_Helene);

	if (sprite_portrait_Jon.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		demandeChangementPerso = 0;
	}
	else if (sprite_portrait_Helene.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		demandeChangementPerso = 1;
	}

	if (sprite_bouton.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
		demandeEstPret = true;
	}

	if (nbrDeJoueurCo >= 1) {
		//Nom du joueur
		Text nomJoueur;
		nomJoueur.setFont(ecriture);
		nomJoueur.setString("Joueur1");
		nomJoueur.setPosition(SCREEN_SIZE_WEIGHT / 8 + 25, SCREEN_SIZE_HEIGHT / 2 - 180);
		window.draw(nomJoueur);

		//Portrait du perso choisi
		if (portraitJoueurs.size() >= 1) {
			joueurPret.at(0).setPosition(SCREEN_SIZE_WEIGHT / 8 - 30, SCREEN_SIZE_HEIGHT / 2 - 80);
			window.draw(joueurPret.at(0));

			portraitJoueurs.at(0).setPosition(SCREEN_SIZE_WEIGHT / 8 + 60, SCREEN_SIZE_HEIGHT / 2 - 140);
			portraitJoueurs.at(0).setScale(Vector2f(2, 2));
			window.draw(portraitJoueurs.at(0));
		}
	}
	if (nbrDeJoueurCo >= 2) {
		//Nom du joueur
		Text nomJoueur;
		nomJoueur.setFont(ecriture);
		nomJoueur.setString("Joueur2");
		nomJoueur.setPosition((SCREEN_SIZE_WEIGHT / 8) * 4 + 25, SCREEN_SIZE_HEIGHT / 2 - 180);
		window.draw(nomJoueur);

		//Portrait du perso choisi
		if (portraitJoueurs.size() >= 2) {
			joueurPret.at(1).setPosition((SCREEN_SIZE_WEIGHT / 8) * 4 - 30, SCREEN_SIZE_HEIGHT / 2 - 80);
			window.draw(joueurPret.at(1));

			portraitJoueurs.at(1).setPosition((SCREEN_SIZE_WEIGHT / 8) * 4 + 60, SCREEN_SIZE_HEIGHT / 2 - 140);
			portraitJoueurs.at(1).setScale(Vector2f(2, 2));
			window.draw(portraitJoueurs.at(1));
		}
	}

	if (nbrDeJoueurCo >= 3) {
		//Nom du joueur
		Text nomJoueur;
		nomJoueur.setFont(ecriture);
		nomJoueur.setString("Joueur3");
		nomJoueur.setPosition(SCREEN_SIZE_WEIGHT / 8 + 25, SCREEN_SIZE_HEIGHT / 2 - 180 + 200);
		window.draw(nomJoueur);

		//Portrait du perso choisi
		if (portraitJoueurs.size() >= 1) {
			joueurPret.at(2).setPosition(SCREEN_SIZE_WEIGHT / 8 - 30, SCREEN_SIZE_HEIGHT / 2 - 80 + 200);
			window.draw(joueurPret.at(2));

			portraitJoueurs.at(2).setPosition(SCREEN_SIZE_WEIGHT / 8 + 60, SCREEN_SIZE_HEIGHT / 2 - 140 + 200);
			portraitJoueurs.at(2).setScale(Vector2f(2, 2));
			window.draw(portraitJoueurs.at(2));
		}
	}

	if (nbrDeJoueurCo == 4) {
		//Nom du joueur
		Text nomJoueur;
		nomJoueur.setFont(ecriture);
		nomJoueur.setString("Joueur4");
		nomJoueur.setPosition((SCREEN_SIZE_WEIGHT / 8) * 4 + 25, SCREEN_SIZE_HEIGHT / 2 - 180 + 200);
		window.draw(nomJoueur);

		//Portrait du perso choisi
		if (portraitJoueurs.size() >= 2) {
			joueurPret.at(3).setPosition((SCREEN_SIZE_WEIGHT / 8) * 4 - 30, SCREEN_SIZE_HEIGHT / 2 - 80 + 200);
			window.draw(joueurPret.at(3));

			portraitJoueurs.at(3).setPosition((SCREEN_SIZE_WEIGHT / 8) * 4 + 60, SCREEN_SIZE_HEIGHT / 2 - 140 + 200);
			portraitJoueurs.at(3).setScale(Vector2f(2, 2));
			window.draw(portraitJoueurs.at(3));
		}
	}

	window.setView(vue);
	window.display();
	window.setActive(true);

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