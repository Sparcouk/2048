#include "modele.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
#include <random>
#include <curses.h>
using namespace std;
using Plateau = vector<vector<int>>;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl


void test1(){
	PlateauJeu jeu;
		//Teste déplacementDroite
	jeu.plateau = {{2,0,0,0},
	              {0,2,0,0},
	              {0,0,2,0},
	              {0,0,0,2}};
	jeu.test = {{0,0,0,2},
	            {0,0,0,2},
	            {0,0,0,2},
	            {0,0,0,2}};
	CHECK( deplacementDroite(jeu).plateau == jeu.test );

	//Teste déplacementGauche
	jeu.plateau = {{2,0,0,0},
	              {0,2,0,0},
	              {0,0,2,0},
	              {0,0,0,2}};
	jeu.test = {{2,0,0,0},
	            {2,0,0,0},
	            {2,0,0,0},
	            {2,0,0,0}};

	CHECK( deplacementGauche(jeu).plateau == jeu.test );

	//Teste déplacementHaut
	jeu.plateau = {{2,0,0,0},
				  {0,2,0,0},
				  {0,0,2,0},
				  {0,0,0,2}};
	jeu.test = {{2,2,2,2},
	            {0,0,0,0},
	            {0,0,0,0},
	            {0,0,0,0}};

	CHECK( deplacementHaut(jeu).plateau == jeu.test );

	//Teste déplacementBas
	jeu.plateau = {{2,0,0,0},
				  {0,2,0,0},
				  {0,0,2,0},
				  {0,0,0,2}};
	jeu.test = {{0,0,0,0},
	            {0,0,0,0},
	            {0,0,0,0},
	            {2,2,2,2}};

	CHECK( deplacementBas(jeu).plateau == jeu.test );

}







int main(){
	test1();
	return 0;
}