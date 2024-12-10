#include <string>
#include <stdexcept>
#include <iostream>
#include <random>
using namespace std;

using Plateau = vector<vector<int>>;
// Vous pouvez ajouter des fonctions à ce fichier si besoin est

/** Attribue a une tuile une couleur en fonction de sa valeur
*@param int la valeur de la tuile
*@return la puissance de deux auxquel elle correspond (jusqu'a un max de 2048 ie 2^11)
*Auteur : Léandre LEMOINE
*Degré de confiance : 100%, la fonction a été implémantée sans problème et n'est composée que de tests booléens simples;
**/
int couleur_tuile(int valeur);


/** Définie les paires de couleurs à utiliser en fonction de la k-ème puissance de 2 de la tuile
*Auteur : Léandre LEMOINE
*Degré de confiance : 100%, l'implémentation de la fonction a été faite sans problème.
**/
void paire_couleurs();


/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 *  Auteurs : Julien WENG & Léandre LEMOINE
 **/
Plateau plateauInitial();

//Initialise une structure associant le plateau de jeu et son score;
struct PlateauJeu{

    int score = 0;
    Plateau plateau = plateauInitial();
	Plateau test;

	
};

/**génère une nouvelle tuile valant 2 ou 4 sur une tuile vide après chaque déplacement
*@param plateau le plateau de jeu
*@return le plateau de jeu avec la tuile ajoutée
*Auteur : Julien WENG
**/
PlateauJeu genereTuile(PlateauJeu jeu);


/** génère un nombre aléatoire entre m et n
   *@param m un entier avec m < n
   *@param n un entier avec n > m
   *@return un nombre entier entre m et n
   *Auteurs : Julien WENG & Léandre LEMOINE
**/
int random(int m,int n);


/**Affiche le plateau
  *@param un PlateauJeu plateau
**/
void afficher(PlateauJeu plateau);


/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @param PlateauJeu jeu
 *  @return 2 ou 4
 *  Auteurs : Julien WENG & Léandre LEMOINE
 **/
int tireDeuxOuQuatre(PlateauJeu jeu);


/** génère un plateau de dimensions 4*4 ne contenant que des 0
 *  @return un plateau vide
 *  Auteurs : Julien WENG & Léandre LEMOINE
 **/
Plateau plateauVide();


/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param PlateauJeu jeu structure
 *  @return le plateau une fois déplacé vers la gauche
 *  Auteur : Julien WENG
 **/
PlateauJeu deplacementGauche(PlateauJeu jeu);


/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param PlateauJeu jeu structure
 *  @return le plateau une fois déplacé vers la droite
 *  Auteur : Julien WENG
 **/
PlateauJeu deplacementDroite(PlateauJeu jeu);

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param PlateauJeu jeu structure
 *  @return le plateau une fois déplacé vers le haut
 *  Auteur : Léandre LEMOINE
 **/
PlateauJeu deplacementHaut(PlateauJeu jeu);


/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param PlateauJeu jeu structure
 *  @return le plateau une fois déplacé vers le bas
 *  Auteur : Léandre LEMOINE
 **/
PlateauJeu deplacementBas(PlateauJeu plateau);


/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param PlateauJeu jeu structure
 *  @param direction la direction
 *  @return le plateau déplacé dans la direction
 *  Auteur : Julien WENG
 **/
PlateauJeu deplacement(PlateauJeu jeu, int direction);


/** affiche un plateau
 * @param PlateauJeu p structure
 * Auteurs : Julien WENG & Léandre LEMOINE
 **/
void dessine(PlateauJeu p);


/** permet de savoir si une partie est terminée
 *  @param PlateauJeu plateau structure
 *  @return true si le plateau est vide, false sinon
 *  Auteur : Julien WENG
 **/
bool estTerminé(PlateauJeu plateau);
    

/** permet de savoir si une partie est gagnée
 * @param @param PlateauJeu plateau structure
 * @return true si le plateau contient un 2048, false sinon
 * Auteurs : Julien WENG & Léandre LEMOINE
 **/
bool estGagnant(PlateauJeu plateau);
