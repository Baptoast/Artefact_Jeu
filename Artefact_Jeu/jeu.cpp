#include "jeu.h"

Jeu::Jeu() {
    salle = Salle(1);
    salle.loadTextureSalle();
    sol = Sol(1);
    sol.loadTextureSol();
    perso = Perso(-64,-64);
    objets = Objet();
    objets.loadTextureObjets();
    
    bdd = BaseDeDonnee();

    adversaire1 = Adversaire(-64, -64);
    adversaire2 = Adversaire(-64, -64);
    adversaire3 = Adversaire(-64, -64);

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

    window.create(VideoMode(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT), "Artefact");

    window.setPosition(Vector2i((Ecran.x/2)- (Ecran.x / 5), Ecran.y/18));

    vue.setSize(Vector2f(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT));
    vue.setCenter(SCREEN_SIZE_WEIGHT / 2, SCREEN_SIZE_HEIGHT / 2);
    window.requestFocus();
}

bool Jeu::isOpen() {
    return window.isOpen();
}

//Thread
void Jeu::connexionAuServeur(int ticket) {
    char data[100];
    std::size_t received;
    numeroJoueur = ticket;

    int port = 53000 + ticket;
    status = socket.connect("192.168.1.27", port);
    while (status != Socket::Done) {}

    //Demande premieres info (Personnage,positionX,positionY,OrdreDansPremierTour) et les initialises
    if (socket.receive(data, 100, received) != Socket::Done) {}

    bdd.leJoueur.at(0).numPerso = (int)data[0] - 48;
    bdd.updateJoueur(convertisseurCoordonnees(data[1])*64, convertisseurCoordonnees(data[2])*64);
    bdd.leJoueur.at(0).numeroDeFile = (int)data[3] - 48;
    
    deroulementTour();
}



void Jeu::bouclePrincipale() {

    //fonction qui capte si un bouton est appuyé (avant il y avait un while).
    
    if (window.pollEvent(event)) {

    }
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
    char data[100];
    std::size_t received;
    if (socket.receive(data, 100, received) != Socket::Done) {}
    sprintf_s(data, "");

    while (window.isOpen()) {
        int positionSourisX = laSouris.getPosition().x - window.getPosition().x;
        int positionSourisY = laSouris.getPosition().y - window.getPosition().y;
        
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
                    cout << "une action confirmee" << endl;
                    initialisationPremiereCase = false;
                    attenteCaseSuivante = false;
                    confirmation = false;
                    hud.actionDeplacement = false;
                    
                    //bdd.leJoueur.at(0).choix = 1;
                    //Partie transfert de l'action
                    sprintf_s(data, "%sD", data);
                    for(int y = 0; y != 3; y++) {
                        sprintf_s(data, "%s%c%c", data,convertisseurCoordonneesVersLettres((bdd.leJoueur.at(0).listeCase.at(y+1).posX)/64),convertisseurCoordonneesVersLettres((bdd.leJoueur.at(0).listeCase.at(y+1).posY)/64));
                    }
                    nombreActions +=1;
                    if (nombreActions < 2) {
                        hud.menuAction = true;
                    }
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
                cout << "une action confirmee" << endl;
                confirmation = false;
                hud.actionFouille = false;
                
                //bdd.leJoueur.at(0).choix = 2;
                //Partie transfert de l'action
                sprintf_s(data, "%sF", data);
                nombreActions +=1;
                if (nombreActions < 2) {
                    hud.menuAction = true;
                }
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
                       
                        //bdd.leJoueur.at(0).choix = 3;
                        //Partie transfert de l'action
                        sprintf_s(data, "%sF", data);
                        nombreActions +=1;
                        if (nombreActions < 2) {
                            hud.menuAction = true;
                        }
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
            
        //Envoi des donnees
        if (nombreActions == 2) {
            cout << "envoie actions" << endl;
            if (socket.send(data, 100) != Socket::Done) {}
            while (strcmp(data, "Z") != 0) {
                if (socket.receive(data, 100, received) != Socket::Done) {}
                cout << "reçoit actions" << endl;
                //Action joueurs (ennemis ou le joueur)
                if (data[0] == 'J') {
                       //Action joueur
                    if ((int)data[1] == numeroJoueur) {
                        switch (data[2])
                        {
                        //Le joueur ce déplace
                        case 'D': {
                            bdd.updateJoueur(convertisseurCoordonnees(data[3]) * 64, convertisseurCoordonnees(data[4]) * 64);
                            break;
                        }
                        //Le joueur fouille
                        case 'F': {
                            objets.gainObjet(convertisseurIdObjets(data[3], data[4]));
                            break;
                        }
                        }
                    }
                    //Actions des adversaires
                    else {
                        int numeroDeLadversaire = (int)data[1];

                    }
                    
                }
            }
            nombreActions = 0;
        }
            
    }
}



int Jeu::convertisseurCoordonnees(char lettre) {
    switch (lettre) {
    case 'a': return 0;
    case 'b': return 1;
    case 'c': return 2;
    case 'd': return 3;
    case 'e': return 4;
    case 'f': return 5;
    case 'g': return 6;
    case 'h': return 7;
    case 'i': return 8;
    case 'j': return 9;
    case 'k': return 10;
    case 'l': return 11;
    case 'm': return 12;
    case 'n': return 13;
    case 'o': return 14;
    }
    return -1;
}

char Jeu::convertisseurCoordonneesVersLettres(int nombre) {
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

int Jeu::convertisseurIdObjets(char chiffre1, char chiffre2) {
    return ((int)chiffre1 - 48) * 10 + (int)chiffre2 - 48;
}
