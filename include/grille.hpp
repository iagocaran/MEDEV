//
//  grille.hpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//

#ifndef grille_hpp
#define grille_hpp

#include "joueur.hpp"

/**
 * @brief Represents the game's grid
 * Defines functions to display the grid in OpenGL, as well as to check if game ended
 */
class Grille {

public:
    static constexpr int taille = 10;
    static constexpr int width = 600;
    static constexpr int height = 600;
    static constexpr int default_x = 100;
    static constexpr int default_y = 100;
    static constexpr const char* default_name = "Bataille Navale";
private:
    //taille de la grille
    int n;
    Joueur *j1;
    Joueur *j2;
    //pour l'openGL
    const char* nom_ligne[taille] = {"A","B","C","D","E","F","G","H","I","J"};
    const char* nom_colonne[taille] = {"0","1","2","3","4","5","6","7","8","9"};
public:
    int getTaille() const;
    void afficherGrille();
    bool partieFinie();
    Grille(int _n, Joueur *_j1, Joueur *_j2);
};


#endif /* grille_hpp */
