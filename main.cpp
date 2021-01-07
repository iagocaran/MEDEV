//
//  main.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//
#define GL_SILENCE_DEPRECATION

#include <iostream>

#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

#include "point.hpp"
#include "grille.hpp"
#include "JoueurReel.h"
#include "gameManager.hpp"

JoueurReel *j1 = new JoueurReel;
JoueurReel *j2 = new JoueurReel;

Grille g(10, j1, j2);

GameManager GM;

void affichageJeu()
{
    g.afficherGrille();
    glutSwapBuffers();
}

void InitGlutSettings() {
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, Grille::width, Grille::height, 0);
}

// Fonction de gestion du clavier (touche enfoncee)
void clavier(unsigned char key, int xx, int yy) {
    glutPostRedisplay();
}

// Le main
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(Grille::default_x, Grille::default_y);
    glutInitWindowSize(Grille::width, Grille::height);
    glutCreateWindow(Grille::default_name);
    InitGlutSettings();
    glutDisplayFunc(affichageJeu);

    glutMainLoop();
    
    
    cout << "Au premier joueur de placer ses bateaux" << endl;
    GM.miseEnPlaceBateaux(j1, g);
    
    cout << "Au deuxieme joueur de placer ses bateaux" << endl;
    GM.miseEnPlaceBateaux(j2, g);
     
     while (!g.partieFinie())
     {
         cout << "A J1 d'attaquer" << endl;
         GM.tourJoueur(j1, j2, g);
         cout << "A J2 d'attaquer" << endl;
         GM.tourJoueur(j2, j1, g);
     }
    
    return 0;
}

