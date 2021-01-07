#pragma once

#include "joueur.hpp"
#include "point.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Represents a human player
 * Defines a method to get a position to attack from the keyboard
 */
class JoueurReel : public Joueur
{
private:
	Point getPoint();
public:
	bool attaquer(Joueur *j);
};