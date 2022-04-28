#include "main.h"

int main()
{
    jeu.creationJeu();
    while (jeu.isOpen()) {
        jeu.bouclePrincipale();
    }
    return 0;
}