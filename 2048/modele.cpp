#include "modele.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
#include <random>
#include <curses.h>
using namespace std;


void paire_couleurs(){
    //Associe a chaque valeur corresepondant aux puissances de 2 de la tuile un couple de couleurs.
    init_pair(0, COLOR_BLACK, COLOR_WHITE);    // Couleur pour 0
    init_pair(1, COLOR_BLACK, COLOR_WHITE);    // Couleur pour 2
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);  // Couleur pour 4
    init_pair(3, COLOR_BLACK, COLOR_GREEN);   // Couleur pour 8
    init_pair(4, COLOR_BLACK, COLOR_CYAN);    // Couleur pour 16
    init_pair(5, COLOR_BLACK, COLOR_BLUE);    // Couleur pour 32
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA); // Couleur pour 64
    init_pair(7, COLOR_WHITE, COLOR_RED);     // Couleur pour 128
    init_pair(8, COLOR_WHITE, COLOR_YELLOW);  // Couleur pour 256
    init_pair(9, COLOR_WHITE, COLOR_GREEN);   // Couleur pour 512
    init_pair(10, COLOR_WHITE, COLOR_CYAN);   // Couleur pour 1024
    init_pair(11, COLOR_WHITE, COLOR_BLUE);   // Couleur pour 2048 et plus
}

int couleur_tuile(int valeur) {
    //renvoie la valeur de la puissance k-eme de 2 de la tuile du plateua jusqu'a 2048 (ie 2^11)
    if (valeur == 2) return 1;
    else if (valeur == 4) return 2;
    else if (valeur == 8) return 3;
    else if (valeur == 16) return 4;
    else if (valeur == 32) return 5;
    else if (valeur == 64) return 6;
    else if (valeur == 128) return 7;
    else if (valeur == 256) return 8;
    else if (valeur == 512) return 9;
    else if (valeur == 1024) return 10;
    else if (valeur >= 2048) return 11;
    else return 0;
}

int tireDeuxOuQuatre(){
    if (random(1,10) == 1){
        return 4;                    //4 a une probabilité de 1/10 de tomber
    }
    else{
        return 2;                    //2 a une probabilité de 9/10 de tomber
    }
}

PlateauJeu genereTuile(PlateauJeu jeu){
    for(int i = 0; i<4;i++){
        for(int j = 0; j<4; j++){
            //vérifie qu'il soit bien possible de générer une nouvelle tuile (si une case est libre pour accueillir une tuile)
            if (jeu.plateau[i][j] == 0){ 
                int ligneRandom;
                int colonneRandom;
                while(true){

                    //choisit une ligne et une colonne aléatoire
                    ligneRandom = random(0,3); 
                    colonneRandom = random(0,3); 
                    
                    //si la case est libre, ajoute la tuile à cette case
                    if(jeu.plateau[ligneRandom][colonneRandom] == 0){ 
                        int value = tireDeuxOuQuatre();
                        jeu.plateau[ligneRandom][colonneRandom] = value;
                        return jeu;
                    }
                }
            }
            }
        }
    
    return jeu;
}

int random(int m,int n){
    random_device rd; //permet de générer un nombre aléatoire 
    mt19937 gen(rd()); //permet de générer un nombre aléatoire à partir d'une graine générée grace à un générateur de nombres pseudo-aléatoires
    uniform_int_distribution<> dist(m,n); //la plage sur laquelle on veut que le nombre soit généré

    return dist(gen);
}

void afficher(PlateauJeu jeu){
    for(int i = 0; i<4;i++){
        for(int j = 0; j<4; j++){
            cout << jeu.plateau[i][j] << "  ";
            
        }
        cout << endl;
    }
    cout<< endl;
}


Plateau plateauVide(){
    vector<int> sousTab(4, 0);                // déclaration ,allocation et initialisation d'un sous tableau de quatre 0
    Plateau tab(4, sousTab);                  // déclaration ,allocation et initialisation du tableau tab de 4 tableaux
    
    return tab;
}

Plateau plateauInitial(){
    Plateau plateau = plateauVide();
    int random1 = 0;
    int random2 = 0;
    int i = 0;

    while(i < 2){
        random1 = random(0,3); 
        random2 = random(0,3);
        
        //Si la case plateau[random1][random2] est vide, tirer un chiffre au hasard entre 2 et 4
        if(plateau[random1][random2] == 0){
            plateau[random1][random2] = tireDeuxOuQuatre();
            i++;
        }
    }
    return plateau;
}

PlateauJeu deplacementGauche(PlateauJeu jeu){
    int colonne = 0;

    //On parcourt les lignes
    for(int i = 0; i<4; i++){ 
        
        for(int j = 1; j < 4 ;j++){
            colonne = j; 
            
            //Les cases non nulles sont déplacées vers la Gauche
            if(jeu.plateau[i][colonne] != 0){ 
                colonne = j;
                while(jeu.plateau[i][colonne - 1] == 0 and colonne >= 1  ){ 
                    jeu.plateau[i][colonne - 1] =  jeu.plateau[i][colonne];
                    jeu.plateau[i][colonne] = 0;
                    colonne--;
                }
            }
        }

        //les cases pouvant être fusionnées sont fusionnées
        for(int j = 0; j < 4  ; j++){
            if(jeu.plateau[i][j] != 0 and jeu.plateau[i][j] == jeu.plateau[i][j+1]){ 
                jeu.plateau[i][j] *= 2;
                jeu.plateau[i][j+1] = 0;
                jeu.score += jeu.plateau[i][j];
            }
        }

        //On redéplace les cases le plus à droite possible
        for(int j = 1; j < 4; j++){
            if(jeu.plateau[i][j] != 0){
                colonne = j;
                while(jeu.plateau[i][colonne - 1] == 0 and colonne >= 1){
                    jeu.plateau[i][colonne - 1] =  jeu.plateau[i][colonne];
                    jeu.plateau[i][colonne] = 0;
                    colonne--;

                }
            }
        }
    }
    return jeu;
} 

PlateauJeu deplacementDroite(PlateauJeu jeu){
    int colonne = 0;
    //On parcourt les lignes
    for(int i = 0; i<4; i++){ 

        //On parcourt les colonnes
        for(int j = 2; j >= 0;j--){
            colonne = j; 

            //Les cases non nulles sont déplacées vers la Droite
            if(jeu.plateau[i][colonne] != 0){
                colonne = j;
                while(jeu.plateau[i][colonne + 1] == 0 and colonne < 3  ){
                    jeu.plateau[i][colonne + 1] =  jeu.plateau[i][colonne];
                    jeu.plateau[i][colonne] = 0;
                    colonne++;
                }
            }
        }
        
        //les cases pouvant être fusionnées sont fusionnées
        for(int j = 3; j >= 0 ; j--){
            if(jeu.plateau[i][j] != 0 and jeu.plateau[i][j] == jeu.plateau[i][j-1]){
                jeu.plateau[i][j] *= 2;
                jeu.plateau[i][j-1] = 0;
                jeu.score += jeu.plateau[i][j];
            }
        }

        //On redéplace les cases le plus à droite possible
        for(int j = 2; j >= 0; j--){
            if(jeu.plateau[i][j] != 0){
                colonne = j;
                while(colonne < 3 and jeu.plateau[i][colonne + 1] == 0){
                    jeu.plateau[i][colonne + 1] =  jeu.plateau[i][colonne];
                    jeu.plateau[i][colonne] = 0;
                    colonne++;
                }
            }
        }
    }
    return jeu;
}

PlateauJeu deplacementHaut(PlateauJeu jeu){
    int ligne = 0;
    for (int j = 0; j < 4; j++){ // parcours des colonnes
        
        // les cases non nulles sont déplacées vers le haut
        for (int i = 1; i <4; i++){
            if (jeu.plateau[i][j] != 0){
                ligne = i;
                while (ligne > 0 and jeu.plateau[ligne - 1][j] == 0){
                    jeu.plateau[ligne - 1][j] = jeu.plateau[ligne][j];
                    jeu.plateau[ligne][j] = 0;
                    ligne--;
                }
            }
        }
        
        // les cases adjacentes pouvant être fusionnées le sont
        for (int i = 0; i< 3; i++){
            if(jeu.plateau[i][j] != 0 and jeu.plateau[i][j] == jeu.plateau[i+1][j]){
                jeu.plateau[i][j] *= 2;
                jeu.plateau[i + 1][j] = 0;
                jeu.score += jeu.plateau[i][j];
            }
        }
        
        // les cases sont déplacées une dernière fois vers le haut
        for(int i = 1; i<4; i++){
            if(jeu.plateau[i][j] != 0){
                ligne = i;
                while(ligne > 0 and jeu.plateau[ligne -1][j] == 0){
                    jeu.plateau[ligne -1][j] = jeu.plateau[ligne][j];
                    jeu.plateau[ligne][j] = 0;
                    ligne--;
                }
            }
        }
    }
    
    return jeu;
    
}

PlateauJeu deplacementBas(PlateauJeu jeu){
    int ligne = 0;
    for (int j = 0; j < 4; j++){ 
        
        //les cases non nulles sont déplacées vers le bas sans être fusionnées
        for (int i = 2; i >=0; i--){
            if (jeu.plateau[i][j] != 0){
                ligne = i;
                while (ligne < 3 and jeu.plateau[ligne + 1][j] == 0){
                    jeu.plateau[ligne + 1][j] = jeu.plateau[ligne][j];
                    jeu.plateau[ligne][j] = 0;
                    ligne++;
                }
            }
        }
        // les cases adjacentes pouvant être fusionnées le sont
        for (int i = 3; i>0; i--){
            if(jeu.plateau[i][j] != 0 and jeu.plateau[i][j] == jeu.plateau[i-1][j]){
                jeu.plateau[i][j] *= 2;
                jeu.plateau[i - 1][j] = 0;
                jeu.score += jeu.plateau[i][j];
            }
        }
        // les cases sont déplacées une dernière fois vers le bas
        for(int i = 2; i >= 0; i--){
            if(jeu.plateau[i][j] != 0){
                ligne = i;
                while(ligne < 3 and jeu.plateau[ligne +1][j] == 0){
                    jeu.plateau[ligne +1][j] = jeu.plateau[ligne][j];
                    jeu.plateau[ligne][j] = 0;
                    ligne++;
                }
            }
        }
    }
    return jeu;
}

PlateauJeu deplacement(PlateauJeu jeu, int direction){
    if(direction == KEY_LEFT and deplacementGauche(jeu).plateau != jeu.plateau){
        
        return genereTuile(deplacementGauche(jeu));
        
    }
    else if(direction == KEY_RIGHT and deplacementDroite(jeu).plateau != jeu.plateau){

        return genereTuile(deplacementDroite(jeu));

    }
    else if(direction == KEY_DOWN and deplacementBas(jeu).plateau != jeu.plateau){
        
        return genereTuile(deplacementBas(jeu));
        
    }
    else if(direction == KEY_UP and deplacementHaut(jeu).plateau != jeu.plateau){
        
        return genereTuile(deplacementHaut(jeu));
        
    }
    else{
        
    return jeu;
        
    }
}

void dessine(PlateauJeu p){
    paire_couleurs();
    printw("*************************\n");
    int nombreDeChiffres;
    for(int i = 0; i<4; i++){
        printw("*"); 
        for(int j = 0; j<4; j++){
            int valeur = p.plateau[i][j];
            int paire = couleur_tuile(valeur);
            nombreDeChiffres = to_string(p.plateau[i][j]).size();      //nombreDeChiffres contient le nombre de chiffres dans le nombre à la ligne i et la colonne j
                attron(COLOR_PAIR(paire));
                if(valeur == 0){
                    printw("     ");
                    attroff(COLOR_PAIR(paire));
                    printw("*");
                }
                else if(nombreDeChiffres == 1){
                    printw("  %d  ", valeur);
                    attroff(COLOR_PAIR(paire));
                     printw("*");
                }
                else if(nombreDeChiffres == 2){
                    printw(" %d  ", valeur);
                    attroff(COLOR_PAIR(paire));
                    printw("*");
                }
                else if(nombreDeChiffres == 3){
                    printw(" %d ", valeur);
                    attroff(COLOR_PAIR(paire));
                    printw("*");
                }
                else{
                    printw(" %d ", valeur);
                    attroff(COLOR_PAIR(paire));
                    printw("*");
                }
        
        } 
        printw("\n");
        printw("*************************\n");
    }
}
bool estTerminé(PlateauJeu jeu){
    if(deplacement(jeu,KEY_LEFT).plateau == deplacement(jeu,KEY_RIGHT).plateau and deplacement(jeu,KEY_LEFT).plateau == deplacement(jeu,KEY_DOWN).plateau and deplacement(jeu,KEY_LEFT).plateau == deplacement(jeu,KEY_UP).plateau){     //si chaque déplacement est égal, le jeu.plateau ne change pas donc la partie est terminée
        return true;
    }
    return false;
}


bool estGagnant(PlateauJeu jeu){
    for(int i = 0; i<4; i++){        
        for(int j = 0; j < 4; j++){                        
            if(jeu.plateau[i][j] >= 2048)
                return true;
        }
    }
    return false;
}
