#include "main.h"

void deroulementTourMain() {
    jeu.deroulementTour();
}

int main()
{
    menu.loadTextureMenu();
    menu.creationMenu();
    while (menu.isOpen()) {
        menu.bouclePrincipale();
    }
    jeu.creationJeu();
    sf::Thread thread(deroulementTourMain);
    thread.launch();
    while (jeu.isOpen()) {
        jeu.bouclePrincipale();
    }
    return 0;
}