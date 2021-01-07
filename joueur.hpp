//
//  joueur.hpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#ifndef joueur_hpp
#define joueur_hpp

#include <vector>

#include "point.hpp"
#include "bateau.hpp"

class Joueur
{
private:
    std::vector<Point> DejaTeste;
    std::vector<Bateau> ListeBateau;
public:
    bool aPerdu();
    virtual bool attaquer(Joueur* j)=0;
    bool dejaTeste(Point p);
    std::vector<Bateau>& getListeBateau();
    std::vector<Point>& getDejaTeste();
    
    //Verifie si une attaque est reussie 
    bool detruire(Point p);
    
    void ajouterBateau(Bateau b);
    
};

#endif /* joueur_hpp */

