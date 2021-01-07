#pragma once

#include "joueur.hpp"
#include "point.hpp"
#include <iostream>

using namespace std;

class JoueurReel : public Joueur
{
private:
	Point getPoint();
public:
	bool attaquer(Joueur *j);
};