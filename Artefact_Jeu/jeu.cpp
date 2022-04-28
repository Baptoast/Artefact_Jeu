#include "jeu.h"

Jeu::Jeu() {
    salle = Salle(1);
    salle.LoadTextureSalle();
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

    salle.afficheSalle(window);

    window.setView(vue);
    window.display();

}


