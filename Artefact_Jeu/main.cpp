#include "main.h"

void deroulementTourMain() {
    jeu.deroulementTour();
}

void connexionServ() {
    menu.connexionAuServeur();
}

int main()
{
    menu.loadTextureMenu();
    menu.creationMenu();
    sf::Thread thread(connexionServ);
    thread.launch();
    while (menu.isOpen()) {
        menu.bouclePrincipale();
    }
    jeu.creationJeu();
    sf::Thread thread2(deroulementTourMain);
    thread2.launch();
    while (jeu.isOpen()) {
        jeu.bouclePrincipale();
    }
    return 0;
}