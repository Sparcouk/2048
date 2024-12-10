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

	
		//Test déplacementDroite
	jeu.plateau = {{2,2,2,0},
	              {0,2,16,0},
	              {0,0,2,0},
	              {0,0,0,2}};
	jeu.test = {{0,0,2,4},
	            {0,0,2,16},
	            {0,0,0,2},
	            {0,0,0,2}};
	CHECK(deplacementDroite(jeu).plateau == jeu.test);


	
	//Test déplacementGauche
	jeu.plateau = {{2,2,2,0},
	              {0,2,16,0},
	              {0,0,2,0},
	              {0,0,0,2}};
	jeu.test = {{4,2,0,0},
	            {2,16,0,0},
	            {2,0,0,0},
	            {2,0,0,0}};

	CHECK(deplacementGauche(jeu).plateau == jeu.test);


	
	//Test déplacementHaut
	jeu.plateau = {{2,2,0,0},
				  {0,2,16,0},
				  {0,4,2,2},
				  {0,0,0,2}};
	jeu.test = {{2,4,16,4},
	            {0,4,2,0},
	            {0,0,0,0},
	            {0,0,0,0}};

	CHECK(deplacementHaut(jeu).plateau == jeu.test);


	
	//Test déplacementBas
	jeu.plateau = {{2,16,0,8},
				  {2,2,2,0},
				  {0,0,2,0},
				  {0,0,2,2}};
	jeu.test = {{0,0,0,0},
	            {0,0,0,0},
	            {0,16,2,8},
	            {4,2,4,2}};

	CHECK(deplacementBas(jeu).plateau == jeu.test);


	
	//Test PlateauVide
	Plateau test1 = {{0,0,0,0},
					 {0,0,0,0},
					 {0,0,0,0},
					 {0,0,0,0}};
	CHECK(plateauVide() == test1);




	
	//Test estTerminé
	jeu.plateau = {{2,4,8,16},
					 {4,2,4,8},
					 {8,4,2,4},
					 {16,8,4,2}};
	CHECK(estTerminé(jeu) == true);
	
	jeu.plateau = {{2,4,8,16},
					 {2,2,4,8},
					 {8,4,2,4},
					 {16,8,4,2}};
	CHECK(estTerminé(jeu) == false);






	
	//Test estGagnant
		jeu.plateau = {{2,4,8,16},
					   {2,2,4,8},
					   {8,4,2,4},
				   	   {16,8,4,2}};
	CHECK(estGagnant(jeu) == false);

			jeu.plateau = {{2,4,8,16},
						   {2,2,4,8},
						   {8,4,2,4},
						   {16,8,4,2048}};
	CHECK(estGagnant(jeu) == true);



	
	
	//Test genereTuile et plateauInitial
	cout << "************ début test genereTuile et plateauInitial  ************" << endl << endl;
	
	jeu.plateau = plateauInitial();
	cout << "plateauInitial avant genereTuile :" << endl;
	cout << endl;
	afficher(jeu);
	cout << "Plateau genereTuile : " << endl;
	cout << endl;
	jeu = genereTuile(jeu);
	afficher(jeu);
	
	cout << "************ fin test genereTuile et plateauInitial ************" << endl << endl;
	cout << endl;




	
	//Test random
	cout << "************ début test random  ************" << endl << endl;

	cout << " - tests entre 1 et 10 : " << endl << endl;

	for(int i = 0; i<10; i++){
		cout << random(1,10) << " ";
	}
	cout << endl << endl;
	cout <<" - tests entre 0 et 3 " << endl << endl;
	cout << endl;
		for(int i = 0; i<10; i++){
		cout << random(0,3) << " ";
	}
	cout << endl << endl;
	cout << "************ fin test random ************" << endl << endl;



	//Test tireDeuxOuQuatre
	cout << "************ début test tireDeuxOuQuatre  ************" << endl << endl;

	for(int i = 0; i<10; i++){
		cout << tireDeuxOuQuatre() << " ";
	}
	cout << endl << endl;
	cout << "************ fin test tireDeuxOuQuatre ************" << endl << endl;
	
}







int main(){
	test1();
	return 0;
}
