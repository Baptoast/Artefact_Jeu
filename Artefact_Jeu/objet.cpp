#include "objet.h"

//Constructeur perso 
Objet::Objet() {

};

/*
Liste des ID :
0 - Kit de soin
1 - Couteau antique
2 - Maillet de l'empereur
3 - Faux de l'ère Edo
4 - Pistolet rouillé
5 - Grenade Maya
6 - Sondeur tonique
7 - Balise des anciens
8 - Cape d'invisibilité
9 - Pelle perceuse
10 - Hologramme trompeur
11 - Bombe cachée
12 - Fosse camouflée
13 - Rocher roulant
14 - Piège-à-rat
*/
void Objet::loadTextureObjets() {
	const int nbrObjetEnTout = 15;
	String nomsObjets[nbrObjetEnTout] = { "kit_de_soin","couteau_antique","maillet_de_l_empereur","faux_de_l_ere_edo", "pistolet_rouille", "grenade_maya", "sondeur_tonique", "balise_des_anciens", "cape_d_invisibilite","pelle_perceuse","hologramme_trompeur","bombe-cachee","fosse_camouflee","rocher_roulant","piege_a_rat"};
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
	case 2:
		return "Maillet de l'empereur";
	case 3:
		return "Faux de l'ère Edo";
	case 4:
		return "Pistolet rouillé";
	case 5:
		return "Grenade Maya";
	case 6:
		return "Sondeur Tonique";
	case 7:
		return "Balise des anciens";
	case 8:
		return "Cape d'invisibilité";
	case 9:
		return "Pelle perceuse";
	case 10:
		return "Hologramme trompeur";
	case 11:
		return "Bombe cachée";
	case 12:
		return "Fosse camouflée";
	case 13:
		return "Rocher roulant";
	case 14:
		return "Piège-à-rat";
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

string Objet::utilisationObjet(int num, vector<Perso>& leJoueur, int caseX, int caseY) {
	char data[100] = "";
	int dizaine = num / 10;
	int unite = num - (dizaine * 10);
	sprintf_s(data, "U%d%d%c%c%c%c", dizaine, unite, convertisseurCoordonneesVersLettres(leJoueur.at(0).getPos().posX), convertisseurCoordonneesVersLettres(leJoueur.at(0).getPos().posY), convertisseurCoordonneesVersLettres(caseX), convertisseurCoordonneesVersLettres(caseY));
	return string(data);
}

char Objet::convertisseurCoordonneesVersLettres(int nombre) {
	switch (nombre) {
	case 0: return 'a';
	case 1: return 'b';
	case 2: return 'c';
	case 3: return 'd';
	case 4: return 'e';
	case 5: return 'f';
	case 6: return 'g';
	case 7: return 'h';
	case 8: return 'i';
	case 9: return 'j';
	case 10: return 'k';
	case 11: return 'l';
	case 12: return 'm';
	case 13: return 'n';
	case 14: return 'o';
	}
	return 'z';
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

