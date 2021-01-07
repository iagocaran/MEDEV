//
//  gameManager.hpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#ifndef gameManager_hpp
#define gameManager_hpp

#include "joueur.hpp"
#include "grille.hpp"

class GameManager
{
public:
    //A appeler en debut de partie pour chaque joueur pour qu'il place ses bateaux
    void miseEnPlaceBateaux(Joueur* j, Grille& g);
    
    //Gere le tour d'un joueur
    void tourJoueur(Joueur* j, Joueur* adversaire, Grille &g);
    
};

#endif /* gameManager_hpp */
