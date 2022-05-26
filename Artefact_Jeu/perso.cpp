#include "perso.h"

//Constructeur perso 
Perso::Perso() {

};

Perso::Perso(int x, int y) {
    //attribut la position du joueur à sa génération
    setPosX(x);
    setPosY(y);
	sprite_perso.setPosition(posJoueur.posX,posJoueur.posY);
	sprite_vision.setPosition(posJoueur.posX-175+32, posJoueur.posY - 175+32);
	pv = 4;
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

void Perso::loadTexturePerso(int numPerso) {
	Texture text_jon;
	Texture text_helene;
	Texture text_mickael;
	Texture text_teneia;
	texture_perso.push_back(text_jon);
	texture_perso.push_back(text_helene);
	texture_perso.push_back(text_mickael);
	texture_perso.push_back(text_teneia);
	
    if (!texture_perso.at(0).loadFromFile("res/img/portrait/Jon_sprite.png") || !texture_perso.at(1).loadFromFile("res/img/portrait/Helene_sprite.png") || !texture_perso.at(2).loadFromFile("res/img/portrait/Mickael_sprite.png") || !texture_perso.at(3).loadFromFile("res/img/portrait/Teneia_sprite.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_perso.setTexture(texture_perso.at(numPerso-1));
	}
	if (!texture_vision.loadFromFile("res/img/vision.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_vision.setTexture(texture_vision);
	}
	if (!texture_perso_clone.loadFromFile("res/img/pieges/bouletJ.png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_perso_clone.setTexture(texture_perso_clone);
	}
};

void Perso::loadTexturePersoPortrait(String personnageChoisi) {
	if (!texture_portrait.loadFromFile("res/img/portrait/"+ personnageChoisi +".png")) {
		cout << "erreur de chargement du personnage" << endl;
	}
	else {
		//Je charge la texture
		sprite_portrait.setTexture(texture_portrait);
	}
};

void Perso::affichePerso(RenderWindow& window) {

	sprite_vision.setTextureRect(IntRect(0, 0, 350, 350));

	animationPerso(directionMarche);

	sprite_perso.setPosition(posJoueur.posX+8, posJoueur.posY+8);
	sprite_vision.setPosition(posJoueur.posX - 175 + 32, posJoueur.posY - 175 + 32);
	window.draw(sprite_vision);
	window.draw(sprite_perso);
}

//Fonction qui donne l'annimation du perso en fonction de sa direction
void Perso::animationPerso(int direction) {

	int y = 0;
	if (direction == 4) {
		y = 3;
		posJoueur.posY = posJoueur.posY - 0.27;
	}
	else if (direction == -1) {
		y = 2;
		posJoueur.posX = posJoueur.posX + 0.27;
	}
	else if (direction == 2) {
		y = 0;
		posJoueur.posY = posJoueur.posY + 0.27;
	}
	else if (direction == 1) {
		y = 1;
		posJoueur.posX = posJoueur.posX - 0.27;
	}

    if (direction != 3 && direction != 0) {
        if (timeAnimationPerso.getElapsedTime().asMilliseconds() >= 140) {
            anim.x++;
            if (anim.x * 48 >= sprite_perso.getTexture()->getSize().x) {
                anim.x = 0;
            }
            timeAnimationPerso.restart();
        }
    }
    else {
        anim.x = 1;
    }
    
    sprite_perso.setTextureRect(IntRect(anim.x * 48, anim.y * 48 + y*48, 48, 48));
}

//gives the angle from point one to point two
float Perso::anglePoints(int x1, int y1, int x2, int y2)
{
	return atan2(y2 - y1, x2 - x1);
}