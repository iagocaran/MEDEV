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
bool verifierCase(Point p, vector<Point> listePoints)
{
    for (Point x : listePoints)
    {
        if (x == p)
        {
            return false;
        }
    }
    return true;
}


//A appeler en debut de partie pour chaque joueur pour qu'il place ses bateaux
void GameManager::miseEnPlaceBateaux(Joueur* player, Grille& g)
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
            if (x<0 || x > g.getTaille() || y < 0 || y > g.getTaille())
            {
                positionValide = false;
            }
            //si le bateau est place horizontalement et depasse de la grille, ce n'est pas valide
            else if ((choixSens == 0) && (x+longueurBateaux[i] >g.getTaille()))
            {
                positionValide = false;
            }
            //si le bateau est place verticalement et depasse de la grille, ce n'est pas valide
            else if ((choixSens == 1) && (y+longueurBateaux[i]>g.getTaille()))
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
                    //Et on ajoute le bateau a la liste de bateau du joueur
                    Bateau b(placeHypothetique);
                    player->ajouterBateau(b);
            }
            else
            {
                cout << "position invalide, veuillez recommencer" << endl;
            }
        }
        //et on affiche la grille chaque fois qu'on a place un bateau
        g.afficherGrille();
    }
}


void GameManager::tourJoueur(Joueur* j, Joueur* adversaire, Grille &g)
{
    bool attaqueReussi = true;
    while(attaqueReussi)
    {
        attaqueReussi = j->attaquer(adversaire);
        if (attaqueReussi)
        {
            cout << "touché ! Veuillez rejouer" << endl;
        }
        else
        {
            cout << "Plouf ! Attaque loupée" << endl;
        }
        g.afficherGrille();
    }
}
