//Include
#include "jeu.h"
#include "menu.h"

bool jeuOuvert = true;
bool leMenu = true;
bool parametre = false;
bool leJeu = false;
bool creationPartie = false;
bool threadBDD = false;
bool lancementDeLaPartie = false;

int ticket = -1;

void connexionServ();
void deroulementTourMain();

Jeu jeu;
Menu menu;
Thread thread(connexionServ);
