//
//  gameManager.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#include "gameManager.hpp"
#include "bateau.hpp"
#include "grille.hpp"

#include <iostream>

using namespace std;

//verifie si un Point est deja present dans le vector de Point donne en parametre
//si le point est present dans la liste de point, retourne faux (faux pour case invalide)
/**
 * @brief Verifies if a Point is inside listePoints
 * @param point : point to be verified
 * @param listePoints : list of points in which to verify
 * @return true if point inside listePoints
 * false otherwise
 */
bool verifierCase(Point point, vector<Point> listePoints)
{
    for (Point x : listePoints)
    {
        if (x == point)
        {
            return false;
        }
    }
    return true;
}

/**
 * Must be called once for each player before the start of a match.
 * @brief Controls the boat placing of each player.
 * @param player Reference to the player whose boats will be placed
 * @param grid Reference to the active grid
 */
void GameManager::miseEnPlaceBateaux(Joueur* player, Grille& grid)
{
    cout << "Veuillez placer vos bateaux" << endl;
    cout << "Vous en possedez 5 en tout, 2 de longueur 2, puis 1 de longueur 3,4 et 5" << endl;
    cout << "tout les bateaux a l'horizontal sont reperes par leur coordonnee a l'extreme gauche" << endl;
    cout << "tout les bateaux a la verticale sont reperes par leur coordonnee la plus basse" << endl;
    
    //tableau donnant la taille de chaque bateau
    int longueurBateaux[5] = {2,2,3,4,5};
    //tableau repertoriant les case deja occupee par les bateaux
    vector<Point> caseDejaOccupee;
    
    unsigned int choixSens = 2; // 0 si horizontal, 1 si vertical
    
    //pour chaque bateau a placer
    for (int i = 0; i<5; i++)
    {
        cout << "Ou voulez vous placer le bateau de longueur " << longueurBateaux[i] << " ? " << endl;
        
        //tant que le sens entre est incorrect, on redemande a l'utilisateur
        choixSens = 2;
        while (choixSens >1)
        {
            cout << "choisir le sens du bateau : 0 pour horizontal, 1 pour vertical" << endl;
            cin >> choixSens;
        }
        
        bool positionValide = false;
        int x,y;
        //tant que la position entree pour le bateau est invalide, on redemande la position
        while (!positionValide)
        {
            cout << "entrer la coordonnee en x" << endl;
            cin >> x;
            cout << "entrer la coordonne en y" << endl;
            cin >> y;
            
            //on met positionValide a true pour le moment
            positionValide = true;
            
            //on ecrit les points sur lesquels serait positionne le bateau sur la grille
            vector<Point> placeHypothetique;
            placeHypothetique.push_back(Point(x,y));
            
            for (int j = 1; j < longueurBateaux[i]; j++)
            {
                //si le bateau est place horizontalement
                if (choixSens == 0)
                {
                    placeHypothetique.push_back(Point(x,y+j));
                }
                //si le bateau est place verticalement
                if (choixSens == 1)
                {
                    placeHypothetique.push_back(Point(x+j,y));
                }
            }
            
            //si le point entre est en dehors de la grille, ce n'est pas valide
            if (x<0 || x > grid.getTaille() || y < 0 || y > grid.getTaille())
            {
                positionValide = false;
            }
            //si le bateau est place horizontalement et depasse de la grille, ce n'est pas valide
            else if ((choixSens == 0) && (x+longueurBateaux[i] > grid.getTaille()))
            {
                positionValide = false;
            }
            //si le bateau est place verticalement et depasse de la grille, ce n'est pas valide
            else if ((choixSens == 1) && (y+longueurBateaux[i] > grid.getTaille()))
            {
                positionValide = false;
            }
            else
            {
                //pour chaque cases deja occupee
                //on verifie que le nouveau bateau ne veut pas se placer dessus
                for (Point p : caseDejaOccupee)
                {
                    positionValide = verifierCase(p, placeHypothetique) && positionValide;
                }
            }
            
            //si finalement, la position du bateau est valide
            if (positionValide)
            {
                    //on ajoute les points dans la liste de cases deja occupee
                    for (Point x : placeHypothetique)
                    {
                        caseDejaOccupee.push_back(x);
                    }
                    //Et on ajoute le bateau a la liste de bateau du player
                    Bateau b(placeHypothetique);
                    player->ajouterBateau(b);
            }
            else
            {
                cout << "position invalide, veuillez recommencer" << endl;
            }
        }
        //et on affiche la grille chaque fois qu'on a place un bateau
        grid.afficherGrille();
    }
}

/**
 * @brief Manages player turns
 * @param player Reference to the player that should play
 * @param opponent Reference to the opponent of the player
 * @param grid Reference to the active grid
 */
void GameManager::tourJoueur(Joueur* player, Joueur* opponent, Grille &grid)
{
    bool attaqueReussi = true;
    while(attaqueReussi)
    {
        attaqueReussi = player->attaquer(opponent);
        if (attaqueReussi)
        {
            cout << "touché ! Veuillez rejouer" << endl;
        }
        else
        {
            cout << "Plouf ! Attaque loupée" << endl;
        }
        grid.afficherGrille();
    }
}
