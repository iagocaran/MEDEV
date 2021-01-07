//
// Created by iagoc on 07/01/2021.
//

#ifndef TDDOC_JOUEURIAPLUS_HPP
#define TDDOC_JOUEURIAPLUS_HPP

#include <vector>
#include "point.hpp"
#include "joueur.hpp"

/**
 * An idea on how to implement a little more advanced AI player
 */
class joueurIAPlus {
private:
    std::vector<Point> prochaines;
public:
    bool attaquer(Joueur * j);
};


#endif //TDDOC_JOUEURIAPLUS_HPP
