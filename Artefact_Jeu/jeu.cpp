#include "jeu.h"

Jeu::Jeu() {
    salle = Salle(1);
    salle.loadTextureSalle();
    sol = Sol(1);
    sol.loadTextureSol();
    perso = Perso(64*3,64*3);
    
    bdd = BaseDeDonnee();

    Adversaire adversaire1 = Adversaire(64 * 3, 64 * 11);
    Adversaire adversaire2 = Adversaire(64 * 11, 64 * 3);
    Adversaire adversaire3 = Adversaire(64 * 11, 64 * 11);

    bdd.ajoutJoueur(perso);
    bdd.ajoutAdversaires(adversaire1, adversaire2, adversaire3);

    indicateur.loadTextureIndicateur();
    hud.loadTextureHud(window);

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
    /*
    if (window.pollEvent(event)) {
        input.InputHandler(event, window);
    }*/
    window.clear(Color::Black);

    sol.afficheSol(window);
    bdd.affichageChosesDansVision(window);
    salle.afficheSalle(window);
    deroulementTour(); //et affichage indicateur
    hud.afficheHud(window);

    window.setView(vue);
    window.display();

}

void Jeu::deroulementTour() {
    if (!hud.menuAction) {
        hud.hud_Actif = true;
        if (hud.actionDeplacement) {
            indicateur.afficheIndicateur(window,1,perso.getPos().posX + nbrClick*64,perso.getPos().posY);
            if (laSouris.isButtonPressed(laSouris.Left) && indicateur.casePossible(window)) {
                nbrClick += 1; //RENDU ICI
            }
        }
    }
}


