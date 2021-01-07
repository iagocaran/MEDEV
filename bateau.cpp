//
//  bateau.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#include "bateau.hpp"

using namespace std;

/**
 * @brief Verifies if one of the boat parts is in target position
 * @param target Point against which the check is made
 * @return true if the boat was touched
 * false otherwise
 */
bool Bateau::estTouche(Point target)
{
    for (int i = 0; i< PositionsBateau.size(); i++)
    {
        if (target == PositionsBateau[i])
        {
            //si le bateau est touche, on retire le point touche de la liste
            //des coordonnee du bateau et on renvoie true
            PositionsBateau.erase(PositionsBateau.begin()+i);
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if the boat is alive
 * @return returns true if there are still parts of the boat left
 * false otherwise
 */
bool Bateau::estEnVie()
{
    return PositionsBateau.size() > 0;
}

/**
 * @brief Constructor
 * Takes a ListePositions as positions to initialize the boat
 * @param ListePositions list of positions for the boat parts
 */
Bateau::Bateau(vector<Point> const& ListePositions)
{
    for (int i=0; i<ListePositions.size(); i++)
    {
        PositionsBateau.push_back(ListePositions[i]);
    }
}

/**
 * @brief returns the positions of the boat
 * @return a reference to the positions of the boat
 */
vector<Point>& Bateau::getPositionsBateau()
{
    return PositionsBateau;
}
