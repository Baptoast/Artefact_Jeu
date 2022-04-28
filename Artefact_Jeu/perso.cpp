#include "perso.h"

//Constructeur perso 
Perso::Perso() {

};

Perso::Perso(int x, int y) {
    //attribut la position du joueur à sa génération
    setPosX(x);
    setPosY(y);
}

//Getter
Perso::Pos Perso::getPos(void) const
{
    return posJoueur;
}

void Perso::setPosX(int x)
{
    posJoueur.posX = x;
}
void Perso::setPosY(int y)
{
    posJoueur.posY = y;
}