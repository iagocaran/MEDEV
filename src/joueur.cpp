//
//  joueur.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#include "joueur.hpp"

using namespace std;

bool Joueur::aPerdu()
{
    for (Bateau b : ListeBateau)
    {
        if (b.estEnVie())
        {
            return false;
        }
    }
    return true;
}

bool Joueur::dejaTeste(Point p)
{
    for (Point i : DejaTeste)
    {
        if (i == p)
        {
            return true;
        }
    }
    return false;
}

vector<Bateau>& Joueur::getListeBateau()
{
    return ListeBateau;
}

std::vector<Point>& Joueur::getDejaTeste()
{
    return DejaTeste;
}

bool Joueur::detruire(Point p) {
    for (Bateau b : ListeBateau) {
        if (b.estTouche(p)) return true;
    }
    return false;
}

void Joueur::ajouterBateau(Bateau b)
{
    ListeBateau.push_back(b);
}
