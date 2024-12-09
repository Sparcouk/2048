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
    keypad(stdscr,TRUE);
    
    while (estTerminé(etat) == false){
        
        clear();
        printw("Votre score est de %d\n", etat.score);
        dessine(etat);
        
        refresh();
        deplacer = getch();
        etat = deplacement(etat, deplacer);
        
    }
    
    endwin();
    
    return 0;
    
}