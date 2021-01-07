//
//  joueurIA.hpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#ifndef joueurIA_hpp
#define joueurIA_hpp

#include "joueur.hpp"
#include <ctime>
#include <cstdlib>

/**
 * @brief An implementation of an AI player that chooses at random
 */
class JoueurIA : public Joueur
{
public:
    virtual bool attaquer(Joueur * j);
};

#endif /* classeIA_hpp */
