#include "jeu.h"

Jeu::Jeu() {
    salle = Salle(1);
    salle.loadTextureSalle();
    sol = Sol(1);
    sol.loadTextureSol();
    perso = Perso(64*5,64*5);
    
    bdd = BaseDeDonnee();

    Adversaire adversaire1 = Adversaire(64 * 10, 64 * 2);
    Adversaire adversaire2 = Adversaire(64 * 4, 64 * 4);
    Adversaire adversaire3 = Adversaire(64 * 10, 64 * 10);

    bdd.ajoutJoueur(perso);
    bdd.ajoutAdversaires(adversaire1, adversaire2, adversaire3);
    
    

}

void Jeu::creationJeu() {
    POINT Ecran = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

    window.create(VideoMode(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT), "Artefact", sf::Style::None);

    window.setPosition(Vector2i((Ecran.x/2)- (Ecran.x / 5), Ecran.y/18));

    vue.setSize(Vector2f(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT));
    vue.setCenter(SCREEN_SIZE_WEIGHT / 2, SCREEN_SIZE_HEIGHT / 2);

}

bool Jeu::isOpen() {
    return window.isOpen();
}



void Jeu::bouclePrincipale() {

    //fonction qui capte si un bouton est appuyé (avant il y avait un while).
    if (window.pollEvent(event)) {
        input.InputHandler(event, window);
        //joueur.setInput(input);
    }
    window.clear(Color::Black);

    sol.afficheSol(window);
    //perso.affichePerso(window);
    bdd.affichageChosesDansVision(window);
    //adversaire.afficheAdversaire(window);
    salle.afficheSalle(window);
    //indicateur.afficheIndicateur(window);
    //hud.afficheHud(window);

    window.setView(vue);
    window.display();

}


