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
    void miseEnPlaceBateaux(Joueur* player, Grille& grid);
    
    //Gere le tour d'un joueur
    void tourJoueur(Joueur* j, Joueur* adversaire, Grille &g);
    
};

#endif /* gameManager_hpp */
