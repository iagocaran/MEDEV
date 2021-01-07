//
// Created by iagoc on 07/01/2021.
//

#include "joueurIAPlus.hpp"
#include <cstdlib>

bool joueurIAPlus::attaquer(Joueur *j) {/*
    srand((unsigned) time(0));
    Point p;

    if (prochaines.size() > 0) {
        do {
            p = prochaines.pop_back();
        } while (dejaTeste(p));
    } else {
        do {
            p = Point(rand() % 10, rand() % 10);
        } while (dejaTeste(p));
    }

    Joueur::DejaTeste.push_back(p);
    if (j.detruire(Point p)) {
        if ((p.getY() + 1) <= 9)
            prochaines.push_back(Point(p.getX(), p.getY() + 1));
        if ((p.getX() + 1) <= 9)
            prochaines.push_back(Point(p.getX() + 1, p.getY()));
        if ((p.getX() - 1) >= 0)
            prochaines.push_back(Point(p.getX() - 1, p.getY()));
        if ((p.getY() - 1) >= 0)
            prochaines.push_back(Point(p.getX(), p.getY() - 1));
        return true;
    }*/
    return false;
}
