#include "main.h"

void connexionServ() {
    ticket = menu.connexionAuServeur();
    lancementDeLaPartie = true;
    jeu.deroulementTour();
    thread.terminate();
    
}

int main()
{
    //Menu
    menu.loadTextureMenu();
    menu.creationMenu();
    thread.launch();
  
    while (!lancementDeLaPartie) {
        menu.bouclePrincipale();
    }
    menu.window.close();

    //Jeu
    jeu.creationJeu();
    while (jeu.isOpen()) {
        jeu.bouclePrincipale();
    }
    return 0;
}