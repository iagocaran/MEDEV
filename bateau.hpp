//
//  bateau.hpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#ifndef bateau_hpp
#define bateau_hpp

#include <vector>
#include "point.hpp"

/**
 * @brief Represents a boat with it's positions
 * The associated functions will help to determine if it was targeted and if it's still alive
 */
class Bateau
{
public:
    Bateau(std::vector<Point> const& ListePositions);
    bool estTouche(Point target);
    bool estEnVie();
    std::vector<Point>& getPositionsBateau();
private:
    std::vector<Point> PositionsBateau;
};

#endif /* bateau_hpp */
