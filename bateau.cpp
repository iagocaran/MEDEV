//
//  bateau.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#include "bateau.hpp"

using namespace std;

bool Bateau::estTouche(Point p)
{
    for (int i = 0; i< PositionsBateau.size(); i++)
    {
        if (p == PositionsBateau[i])
        {
            //si le bateau est touche, on retire le point touche de la liste
            //des coordonnee du bateau et on renvoie true
            PositionsBateau.erase(PositionsBateau.begin()+i);
            return true;
        }
    }
    return false;
}

bool Bateau::estEnVie()
{
    return PositionsBateau.size() > 0;
}

Bateau::Bateau(vector<Point> const& ListePositions)
{
    for (int i=0; i<ListePositions.size(); i++)
    {
        PositionsBateau.push_back(ListePositions[i]);
    }
}

vector<Point>& Bateau::getPositionsBateau()
{
    return PositionsBateau;
}
