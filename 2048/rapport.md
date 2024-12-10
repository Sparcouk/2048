---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

## Auteurs

- WENG, Julien, julien.weng@etu-upsaclay.fr, MI-4
- LEMOINE, Léandre, leandre.lemoine@etu-upsaclay.fr, MI-4

+++

## Résumé du travail effectué

:::{admonition} Consignes

Pour chaque niveau du sujet, décrivez brièvement l'avancement de votre
projet.

Exemples de réponses : «non traitée», «réalisée, documentée, testée»,
«réalisée, sauf 2.3», «réalisée mais non testée», «réalisée sauf ...
pour lequel notre programme ne compile pas» ou «pour lequel les tests
de la fonction D ne passent pas».

Pour les questions «Aller plus loin» plus ouvertes, décrivez plus en
détail ce que vous avez choisi de réaliser. Précisez les difficultés
rencontrées, les choix d'implantation que vous avez fait, etc.

En plus du rapport, la documentation de chaque fonction dans le code
devra préciser son auteur et votre degré de confiance dans
l'implantation, ainsi que les éléments factuels motivant cette
confiance: présence de tests, bogues et limitations connus, etc.

:::


- Niveau 0:  
      - Fonctions principales du jeu entièrements réalisées, testées et documentées.  
      - Le plateau de jeu est bien de taille 4x4 intialisée avec des zéros et deux tuiles placées aléatoirement valant 2 ou 4 avec
        une probabilité respective de 9/10 et 1/10.  
      - Les tuiles peuvent être déplacées vers le haut, bas, gauche et la droite, les tuiles adjacentes sont fusionnées lors de leurs déplacement.  
      - La valeur de la tuile crée lors du déplacement est ajoutée au score à chaque fusion.  
      - Les tailles de chaque tuiles sont égales peu importe la taille de leurs valeurs (Une limitation est notée pour les valeurs
        supérieures ou égales à 16384).  
      - Le jeu s'arrête lorsque plus aucun déplacement n'est possible, le plateau final est alors affichée avec le score obtenu.  
- Niveau 1:  
      1.1 - Couleurs ajoutées à la console : chaque valeur de tuile jusqu'à 2048 à une combinaison de couleurs unique.  
      1.2 - Les déplacements avec les flèches directionnelles ont été implémantés grâce a la bibliothèque ncurses, il n'est plus
            necessaire de valider l'action avec la touche entrée.  
      1.3 - L'affichage du plateau est actualisé à chaque déplacement.  
      1.4 - Une structure de donnée associant le plateau de jeu et son score a été implémantée dans "modele.hpp".
- Niveau 2:  
      2.1 - Un Makefile dédiée au projet a été conçu pour compiler plus efficacement les différents fichiers.  
      2.2 - L'ensemble des fichiers a été déposé sur un [GitHub](https://github.com/julienwng/2048/tree/main/2048) afin de plus efficacement géré les versions et sources du projet

+++

## Démonstration

:::{admonition} Consignes

Soutenez ce que vous affirmez dans la section précédente au moyen de
quelques exemples **bien choisis**. Vous pouvez par exemple compiler
et lancer certains de vos programmes, lancer des tests, etc.

À titre d'inspiration, vous trouverez ci-dessous comment compiler un
programme du projet depuis cette feuille. 

Notez comment on lance une commande shell en la préfixant d'un point
d'exclamation (mais cela ne permet pas l'interaction avec
l'utilisateur).

Ne gardez que des exemples pertinents qui mettent en valeur votre
travail. Inutile de perdre du temps sur le premier programme si vous
avez fait les suivants plus compliqués; l'auditeur se doutera bien que
vous avez réussi à le faire.

:::

Pour compiler le projet, vous pouvez exécuter la commande suivante :

```{code-cell} ipython3
!make jeu
```

```{code-cell} ipython3
!make test
```

Vous pourrez alors lancer le jeu depuis un terminal avec :

+++

./jeu

+++

## Organisation du travail

Le projet à dû prendre en tout une trentaine d'heure pour être finalisé, les différentes tâches a réaliser ont été séparées entre les deux membres du binôme
avec des mises en commun régulières pour assurer le bon fonctionnement du programme. Les fichiers étaient principalement partagés par la messagerie dédiée
de l'Université Paris-Saclay mais un repositoire GitHub a été utilisé vers les dernières heures de développements du projet pour gérer plus efficacement
les modifications.  
Le projet était souvent testé pour vérifier le bon fonctionnements des programmes lors des parties.

+++

## Prise de recul

:::{admonition} Consignes
Décrivez en quelques phrases les difficultés rencontrées, ce que vous
avez appris à l'occasion du projet, le cas échéant comment vous vous y
prendriez si vous aviez à le refaire.
:::

Les difficultés principales qui ont été rencontrées lors du développemnts sont:  
    -L'implémentation des fonctions gérant le déplacement et la fusion des tuiles, ce challenge nous a permis d'apprendre à visualiser plus efficacement l'execution des programmes.  
    -L'implémentation de la structure associant le plateau de jeu et son score : il a été nécessaire de modifier quasiment l'entièreté des fonctions pour qu'elles s'adaptent au nouveau type d'objets   
     pris en argument, si on devait être menée a refaire un projet similaire il serait sûrement lus judicieux d'implémenter immédiatement la structure afin de ne pas rencontrer
     ces problèmes plus tard.
