#include "modele.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
#include <random>
#include <curses.h>
using namespace std;
using Plateau = vector<vector<int>>;

int main(){
    PlateauJeu etat;
    int deplacer;
    initscr();
    start_color();
    paire_couleurs();
    keypad(stdscr,TRUE);
    
    while (estTerminé(etat) == false){
        
        clear(); 
        printw("Votre score est de %d\n", etat.score);
        dessine(etat);
        refresh();
        deplacer = getch();
        etat = deplacement(etat, deplacer);
        afficher(etat);
        
    }
    clear();
    printw("La partie est terminée !\n");
    printw("Score final :%d\n", etat.score);
    dessine(etat);
    if(estGagnant(etat) == true){
            printw("Félicitation vous avez fait une case valant 2048 ou plus au cours de la partie !\n");
    }
	int touche;
    printw("Appuyez sur la touche entrée pour quitter le jeu.\n");
	touche = getch();
	if( touche == KEY_ENTER){
	dessine(etat);
    refresh();
    getch();
    endwin();
	}
    endwin();
    return 0;
    
}
