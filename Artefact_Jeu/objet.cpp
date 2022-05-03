#include "objet.h"

//Constructeur perso 
Objet::Objet() {

};

/*
Liste des ID :
0 - Kit de soin
1 - Couteau antique
*/
void Objet::loadTextureObjets() {
	const int nbrObjetEnTout = 2;
	String nomsObjets[nbrObjetEnTout] = { "kit_de_soin","couteau_antique" };
	for (int i = 0; i <= nbrObjetEnTout-1; i++) {
		Texture nouvelleTexture;
		listeTexture.push_back(nouvelleTexture);
		if (!listeTexture.at(listeTexture.size()-1).loadFromFile("res/img/objets/"+nomsObjets[i]+".png")) {
			cout << "erreur de chargement de l'objet" << endl;
		}
	}
	if (!ecriture.loadFromFile("res/img/font/chinese rocks rg.otf")) {
		cout << "erreur de chargement de l'ecriture" << endl;
	}
	else {
		nomItem.setFont(ecriture);
		nomItem.setScale(Vector2f(0.5,0.5));
	}
};

String Objet::getNomObjet(int num) {
	switch (num)
	{
	case 0:
		return "Kit de Soin";
	case 1:
		return "Couteau Antique";
	}
	return "";
}

int Objet::numeroIndicateurObjetUtilisation(int num) {
	switch (num)
	{
	case 0:
		return 1;
	case 1:
		return 1;
	}
	return -1;
}

void Objet::effetObjet(int num, vector<Perso>& leJoueur,int caseX, int caseY) {
	switch (num)
	{
	case 0:
		if (caseX == leJoueur.at(0).getPos().posX && caseY == leJoueur.at(0).getPos().posY) {
			leJoueur.at(0).pv = leJoueur.at(0).pv + 1;
		}
		cout << leJoueur.at(0).pv << endl;
		break;
	case 1:
		break;
	}
}

void Objet::afficheObjets(RenderWindow& window, bool enGros) {
	int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
	int positionSourisY = laSouris.getPosition().y - window.getPosition().y;

	int i = 0;
	int compt = 0;
	for (Item item : inventairePerso) {
		
		if (!enGros) {
			nomItem.setScale(Vector2f(0.5, 0.5));
			item.image.setScale(Vector2f(1, 1));
			item.image.setPosition(window.getPosition().x - 140 + i, window.getPosition().y + ((window.getSize().y / 100) * 87));
			i += 64;
		}
		else {
			nomItem.setScale(Vector2f(1, 1));
			item.image.setScale(Vector2f(2, 2));
			item.image.setPosition(window.getPosition().x - 280 + i, window.getPosition().y + ((window.getSize().y / 100) * 50));
			i += 64*2;
		}
		window.draw(item.image);

		if (item.image.getGlobalBounds().contains(positionSourisX, positionSourisY)) {
			//Affiche texte
			nomItem.setString(getNomObjet(item.num));
			if (!enGros) {
				nomItem.setPosition(positionSourisX - 30, positionSourisY - 40);
			}
			else {
				nomItem.setPosition(positionSourisX - 60, positionSourisY - 60);
				//Si choisi
				if (laSouris.isButtonPressed(laSouris.Left)) {
					numChoisi = item.num;
					numChoisiParRapportAInventaire = compt;
				}
			}
			window.draw(nomItem);
		}

		compt += 1;
	}
}

void Objet::gainObjet(int num) {
	Item nouvelItem;
	nouvelItem.num = num;
	nouvelItem.image.setTexture(listeTexture.at(num));
	inventairePerso.push_back(nouvelItem);
}

