//
//  main.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//
#define GL_SILENCE_DEPRECATION

#include <Windows.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include "point.hpp"
#include "grille.hpp"
#include "JoueurReel.h"
#include "gameManager.hpp"

JoueurReel *joueur1 = new JoueurReel();
JoueurReel *joueur2 = new JoueurReel();

Grille g(10, joueur1, joueur2);

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

/**
 * @brief Program entry point
 * @param argc is the number of arguments passed
 * @param argv is an array of the arguments as strings (char*)
 * @return exit code to the OS
 */
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
    GM.miseEnPlaceBateaux(joueur1, g);
    
    cout << "Au deuxieme joueur de placer ses bateaux" << endl;
    GM.miseEnPlaceBateaux(joueur2, g);
     
     while (!g.partieFinie())
     {
         cout << "A J1 d'attaquer" << endl;
         GM.tourJoueur(joueur1, joueur2, g);
         cout << "A J2 d'attaquer" << endl;
         GM.tourJoueur(joueur2, joueur1, g);
     }
    
    return EXIT_SUCCESS;
}

