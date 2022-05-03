#include "jeu.h"

Jeu::Jeu() {
    salle = Salle(1);
    salle.loadTextureSalle();
    sol = Sol(1);
    sol.loadTextureSol();
    perso = Perso(64*3,64*3);
    objets = Objet();
    objets.loadTextureObjets();
    
    bdd = BaseDeDonnee();

    Adversaire adversaire1 = Adversaire(64 * 3, 64 * 11);
    Adversaire adversaire2 = Adversaire(64 * 11, 64 * 3);
    Adversaire adversaire3 = Adversaire(64 * 11, 64 * 11);

    bdd.ajoutJoueur(perso,"Jon");
    bdd.ajoutAdversaires(adversaire1, adversaire2, adversaire3);

    indicateur.loadTextureIndicateur();
    hud.loadTextureHud(window);

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
    /*
    if (window.pollEvent(event)) {
        input.InputHandler(event, window);
    }*/
    window.clear(Color::Black);

    sol.afficheSol(window);
    bdd.affichageChosesDansVision(window);
    salle.afficheSalle(window);
    deroulementTour(); //et affichage indicateur
    hud.afficheHud(window,objets);

    window.setView(vue);
    window.display();

}

void Jeu::deroulementTour() {
    int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
    int positionSourisY = laSouris.getPosition().y - window.getPosition().y;
    if (!hud.menuAction) {
        hud.hud_Actif = true;
        if (hud.actionDeplacement) {
            if (listeCase.size() <= 3) {
                if (!initialisationPremiereCase) {
                    Case posJoueurActuel;
                    posJoueurActuel.posX = bdd.leJoueur.at(0).getPos().posX;
                    posJoueurActuel.posY = bdd.leJoueur.at(0).getPos().posY;
                    listeCase.push_back(posJoueurActuel);
                    initialisationPremiereCase = true;
                }
                indicateur.afficheIndicateur(window, 1, listeCase.at(listeCase.size() - 1).posX, listeCase.at(listeCase.size() - 1).posY);
                if (laSouris.isButtonPressed(laSouris.Left) && indicateur.casePossible(window) && !attenteCaseSuivante) {
                    Case caseSuivante;
                    caseSuivante.posX = (positionSourisX / 64) * 64;
                    caseSuivante.posY = (positionSourisY / 64) * 64;
                    listeCase.push_back(caseSuivante);
                    indicateur.listeCasePossible.clear();
                    attenteCaseSuivante = true;
                }
                else if (attenteCaseSuivante && !laSouris.isButtonPressed(laSouris.Left)) attenteCaseSuivante = false;
            }
            else {
                if (confirmation && !hud.confirmationChoix) {
                    //ICI ON PASSE EN ATTENTE
                    cout << "c'est confirmer, on attend maintenant" << endl;
                    initialisationPremiereCase = false;
                    attenteCaseSuivante = false;
                    confirmation = false;
                    hud.actionDeplacement = false;
                    choix = 1;
                }
                else if (confirmation && hud.confirmationChoix) {
                    hud.confirmationBouton(window);
                }
                else if (!confirmation && !hud.confirmationChoix) {
                    hud.confirmationChoix = true;
                    hud.confirmationBouton(window);
                    confirmation = true;
                }
            }
            
        }
        if (hud.actionFouille) {
            if (confirmation && !hud.confirmationChoix) {
                //ICI ON PASSE EN ATTENTE
                cout << "c'est confirmer, on attend maintenant" << endl;
                confirmation = false;
                hud.actionFouille = false;
                choix = 2;
            }
            else if (confirmation && hud.confirmationChoix) {
                hud.confirmationBouton(window);
            }
            else if (!confirmation && !hud.confirmationChoix) {
                hud.confirmationChoix = true;
                hud.confirmationBouton(window);
                confirmation = true;
            }
        }
        if (hud.actionObjets) {
            hud.inventaireGros = true;
            if (objets.numChoisi !=-1) {
                if (listeCase.size() <= 0) {
                    indicateur.afficheIndicateur(window, objets.numeroIndicateurObjetUtilisation(objets.numChoisi), bdd.leJoueur.at(0).getPos().posX, bdd.leJoueur.at(0).getPos().posY);
                    if (laSouris.isButtonPressed(laSouris.Left) && indicateur.casePossible(window) && !attenteCaseSuivante) {
                        Case caseSuivante;
                        caseSuivante.posX = (positionSourisX / 64) * 64;
                        caseSuivante.posY = (positionSourisY / 64) * 64;
                        listeCase.push_back(caseSuivante);
                        indicateur.listeCasePossible.clear();
                        attenteCaseSuivante = true;
                    }
                    else if (attenteCaseSuivante && !laSouris.isButtonPressed(laSouris.Left)) attenteCaseSuivante = false;
                }
                else {
                    if (confirmation && !hud.confirmationChoix) {
                        //ICI ON PASSE EN ATTENTE
                        cout << "c'est confirmer, on attend maintenant" << endl;
                        confirmation = false;
                        hud.actionObjets = false;
                        hud.inventaireGros = false;
                        attenteCaseSuivante = false;
                        choix = 3;
                    }
                    else if (confirmation && hud.confirmationChoix) {
                        hud.confirmationBouton(window);
                    }
                    else if (!confirmation && !hud.confirmationChoix) {
                        hud.confirmationChoix = true;
                        hud.confirmationBouton(window);
                        confirmation = true;

                    }
                }
            }
        }
        if (!attenteDesAutresJoueurs()) {
            //A METTRE DANS UNE FONCTION SPECIALE DE RESOLUTION D'ACTION !!
            if (perso.numeroDeFile == 1) {
                //Deplacement
                if (choix == 1) {
                    for (int i = 0; i < listeCase.size(); i++) {
                        bdd.updateJoueur(listeCase.at(i).posX, listeCase.at(i).posY);
                    }
                }
                //Fouilles
                else if (choix == 2) {
                    objets.gainObjet(0);

                }
                //Utilisation d'un Objet
                else if (choix == 3) {
                    objets.effetObjet(objets.numChoisi, bdd.leJoueur, listeCase.at(0).posX, listeCase.at(0).posY);
                    objets.inventairePerso.erase(objets.inventairePerso.begin() + objets.numChoisiParRapportAInventaire);
                    objets.numChoisiParRapportAInventaire = -1;
                    objets.numChoisi = -1;
                }
                hud.menuAction = true;
                hud.hud_Actif = false;
                listeCase.clear();
                choix = 0;
            }
        }
    }
}

//Attend que tout le monde (y compris nous) aies choisi
bool Jeu::attenteDesAutresJoueurs() {
    if (choix != 0) { //&& que les autres joueurs ont choisi
        return false;
    }
    return true;
}


