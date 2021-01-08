//
//  joueurIA.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#include "joueurIA.hpp"

#include <ctime>
#include <cstdlib>

bool JoueurIA::attaquer(Joueur * j)
{
    srand((unsigned) time(0));
    Point p;
    do
    {
        p = Point(rand() % 10, rand() % 10);
    } while (dejaTeste(p));
    return j->detruire(p);
}


