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

/**
 * @brief Manages player turns
 */
class GameManager
{
public:
    void miseEnPlaceBateaux(Joueur* player, Grille& grid);
    void tourJoueur(Joueur* player, Joueur* opponent, Grille &grid);
};

#endif /* gameManager_hpp */
