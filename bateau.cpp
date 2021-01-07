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
 * @param target Takes the Point against which the check is made
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
 * @return true if there are still parts of the boat left
 * false otherwise
 */
bool Bateau::estEnVie()
{
    return !PositionsBateau.empty();
}

/**
 * Takes a ListePositions as positions to initialize the boat
 * @brief Constructor
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
 * @brief Returns the positions of the boat
 * @return A reference to the positions of the boat
 */
vector<Point>& Bateau::getPositionsBateau()
{
    return PositionsBateau;
}
