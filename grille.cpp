//
//  grille.cpp
//  PROJETMEDEV
//
//  Created by Hugo ALLEMAND on 11/12/2020.
//  Copyright © 2020 Hugo ALLEMAND. All rights reserved.
//
#define GL_SILENCE_DEPRECATION

#include "grille.hpp"
#include <iostream>

#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

int Grille::getTaille() const
{
    return n;
}

bool Grille::partieFinie()
{
    if (j1->aPerdu())
    {
        cout << "J2 gagne" << endl;
        return true;
    }
    if (j2->aPerdu())
    {
        cout << "J1 gagne" << endl;
        return true;
    }
    return false;
}

Grille::Grille(int _n, Joueur* _j1, Joueur* _j2) : n(_n), j1(_j1), j2(_j2)
{}

void Grille::afficherGrille() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();//test

    float epaisseur = 5;
    float margin_left = -400;
    float margin_right = -500;
    float pos_x = margin_left;
    float pos_y = margin_right;
    float pas = 100;

    // Affichage du jeu
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < Grille::taille; i++) {
        glRasterPos2f(pos_x / Grille::width, pos_y / Grille::height);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *nom_ligne[i]);
        pos_x += pas;
    }

    pos_x = margin_left - pas /2;
    pos_y = margin_right;

    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < Grille::taille + 1; i++) {
        glBegin(GL_QUADS);
        glVertex2f(pos_x / Grille::width, pos_y / Grille::height);
        glVertex2f(pos_x / width, (pos_y + (Grille::taille+0.5) * pas) / Grille::height);
        glVertex2f((pos_x + epaisseur) / Grille::width, (pos_y + (Grille::taille+0.5) * pas) / Grille::height);
        glVertex2f((pos_x + epaisseur) / Grille::width, pos_y / Grille::height);
        glEnd();
       
        pos_x += pas;
    }

    pos_x = margin_right;
    pos_y = margin_left - pas /2;

    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < Grille::taille + 1; i++) {
        glBegin(GL_QUADS);
        glVertex2f(pos_x / Grille::width, pos_y / Grille::height);
        glVertex2f((pos_x + (Grille::taille+0.5)*pas) / Grille::width, pos_y / Grille::height);
        glVertex2f((pos_x + (Grille::taille+0.5)*pas) / Grille::width, (pos_y + epaisseur) / Grille::height);
        glVertex2f(pos_x / Grille::width, (pos_y + epaisseur) / Grille::height);
        glEnd();

        pos_y += pas;
    }

    pos_x = margin_right;
    pos_y = margin_left;

    for (int i = 0; i < Grille::taille; i++) {
        glRasterPos2f(pos_x / Grille::width, pos_y / Grille::height);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *nom_colonne[i]);
        pos_y += pas;
    }


    // Affichage des bateaux du joueur
    pos_x = margin_left;
    pos_y = margin_right;

    for (int i = 0; i < j1->getListeBateau().size(); i++) {
        for (int j = 0; j < j1->getListeBateau()[i].getPositionsBateau().size(); j++) {
            if (j1->getListeBateau()[i].estEnVie()) {
                bool point_touche = false;
                pos_x += pas * j1->getListeBateau()[i].getPositionsBateau()[j].getX();
                pos_y += pas * j1->getListeBateau()[i].getPositionsBateau()[j].getY();

                for (int p = 0; p < j2->getDejaTeste().size(); p++) {
                    if (pos_x == j2->getDejaTeste()[p].getX() && pos_y == j2->getDejaTeste()[p].getY())
                        point_touche = true;
                }

                if (!point_touche) {
                    glColor3f(0.0, 1.0, 0.0);
                    glBegin(GL_QUADS);
                    glVertex2f(pos_x / width, pos_y / height);
                    glVertex2f((pos_x + pas) / width, pos_y / height);
                    glVertex2f((pos_x + pas) / width, (pos_y + pas) / height);
                    glVertex2f(pos_x / width, (pos_y + pas) / height);
                    glEnd();
                }
            }
        }
    }


    // Affichage des points touchés par le joueur
    pos_x = margin_left;
    pos_y = margin_right;

    int deja_x, deja_y;
    for (int i = 0; i < j1->getDejaTeste().size(); i++) {
        bool isRed = false;
        deja_x = j1->getDejaTeste()[i].getX();
        deja_y = j1->getDejaTeste()[i].getY();
        for (int k = 0; k < j2->getListeBateau().size(); k++) {
            for (int j = 0; j < j2->getListeBateau()[k].getPositionsBateau().size(); j++) {
                if (deja_x == j2->getListeBateau()[k].getPositionsBateau()[j].getX() && deja_y == j2->getListeBateau()[k].getPositionsBateau()[j].getY())
                    isRed = true;
            }
        }

        glColor3f(1.0, 1.0, 1.0);
        if (isRed)
            glColor3f(1.0, 0.0, 0.0);

        pos_x += deja_x * pas;
        pos_y += deja_y * pas;

        glBegin(GL_QUADS);
        glVertex2f((pos_x + (pas / 4)) / width, (pos_y + (pas / 4)) / height);
        glVertex2f((pos_x + (3 * pas / 4)) / width, (pos_y + (pas / 4)) / height);
        glVertex2f((pos_x + (3 * pas / 4)) / width, (pos_y + (3 * pas / 4)) / height);
        glVertex2f((pos_x + (pas / 4)) / width, (pos_y + (3 * pas / 4)) / height);
        glEnd();
    }
}
