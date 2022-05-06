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

    adversaire1 = Adversaire(64 * 3, 64 * 11);
    adversaire2 = Adversaire(64 * 11, 64 * 3);
    adversaire3 = Adversaire(64 * 11, 64 * 11);

    bdd.ajoutJoueur(perso,"Jon");
    bdd.ajoutAdversaires(adversaire1, adversaire2, adversaire3,"Helene", "Helene", "Helene");

    indicateur.loadTextureIndicateur();
    hud.loadTextureHud(window);

    //bdd.listeAdversaire.at(0).choixDeSesActions();
    //bdd.listeAdversaire.at(1).choixDeSesActions();
    //bdd.listeAdversaire.at(2).choixDeSesActions();
    bdd.melangeOrdreDePassage();

}

void Jeu::creationJeu() {
    POINT Ecran = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

    window.create(VideoMode(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT), "Artefact", sf::Style::None);

    window.setPosition(Vector2i((Ecran.x/2)- (Ecran.x / 5), Ecran.y/18));

    vue.setSize(Vector2f(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT));
    vue.setCenter(SCREEN_SIZE_WEIGHT / 2, SCREEN_SIZE_HEIGHT / 2);
    //window.setActive(false);
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
    indicateur.afficheIndicateur(window);
    hud.afficheHud(window, objets, bdd.leJoueur, bdd.listeAdversaire);

    window.setView(vue);
    window.display();

    
    
}

void Jeu::deroulementTour() {
    while (window.isOpen()) {
        int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
        int positionSourisY = laSouris.getPosition().y - window.getPosition().y;
        
        if (!hud.menuAction) {
            hud.hud_Actif = true;
            if (hud.actionDeplacement) {
                if (bdd.leJoueur.at(0).listeCase.size() <= 3) {
                    if (!initialisationPremiereCase) {
                    
                        Perso::Case posJoueurActuel;
                        posJoueurActuel.posX = bdd.leJoueur.at(0).getPos().posX;
                        posJoueurActuel.posY = bdd.leJoueur.at(0).getPos().posY;
                        bdd.leJoueur.at(0).listeCase.push_back(posJoueurActuel);
                        initialisationPremiereCase = true;
                    }
                    indicateur.updateIndicateur(1, bdd.leJoueur.at(0).listeCase.at(bdd.leJoueur.at(0).listeCase.size() - 1).posX, bdd.leJoueur.at(0).listeCase.at(bdd.leJoueur.at(0).listeCase.size() - 1).posY);
                    if (laSouris.isButtonPressed(laSouris.Left) && indicateur.casePossible(window) && !attenteCaseSuivante) {
                        Perso::Case caseSuivante;
                        caseSuivante.posX = (positionSourisX / 64) * 64;
                        caseSuivante.posY = (positionSourisY / 64) * 64;
                        bdd.leJoueur.at(0).listeCase.push_back(caseSuivante);
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
                        bdd.leJoueur.at(0).choix = 1;
                    }
                    else if (confirmation && hud.confirmationChoix) {
                        hud.confirmationBouton(window);
                    }
                    else if (!confirmation && !hud.confirmationChoix) {
                        hud.confirmationChoix = true;
                        hud.confirmationBouton(window);
                        indicateur.updateIndicateur(-1, -64, -64);
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
                    bdd.leJoueur.at(0).choix = 2;
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
                    if (bdd.leJoueur.at(0).listeCase.size() <= 0) {
                        indicateur.updateIndicateur(objets.numeroIndicateurObjetUtilisation(objets.numChoisi), bdd.leJoueur.at(0).getPos().posX, bdd.leJoueur.at(0).getPos().posY);
                        if (laSouris.isButtonPressed(laSouris.Left) && indicateur.casePossible(window) && !attenteCaseSuivante) {
                            Perso::Case caseSuivante;
                            caseSuivante.posX = (positionSourisX / 64) * 64;
                            caseSuivante.posY = (positionSourisY / 64) * 64;
                            bdd.leJoueur.at(0).listeCase.push_back(caseSuivante);
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
                            bdd.leJoueur.at(0).choix = 3;
                        }
                        else if (confirmation && hud.confirmationChoix) {
                            hud.confirmationBouton(window);
                        }
                        else if (!confirmation && !hud.confirmationChoix) {
                            hud.confirmationChoix = true;
                            hud.confirmationBouton(window);
                            confirmation = true;
                            indicateur.updateIndicateur(-1, -64, -64);

                        }
                    }
                }
            }
            if (!bdd.attenteDesAutresJoueurs()) {
                bdd.resolutionActions(objets, hud,window);
            }
        }
    }
}



