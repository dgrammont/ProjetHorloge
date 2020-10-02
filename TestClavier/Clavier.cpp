/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clavier.cpp
 * Author: philippe
 *
 * Created on 31 décembre 2018, 17:11
 */

#include <cstdio>

#include "Clavier.h"

Clavier::Clavier() {
    struct termios etatCourant;
    // char toucheAvant;
    tcgetattr(STDIN_FILENO, &etatInitial);
    etatCourant = etatInitial;
    etatCourant.c_lflag &= ~ICANON;
    etatCourant.c_lflag &= ~ECHO;
    etatCourant.c_lflag &= ~ISIG;
    etatCourant.c_oflag &= ~NL0;
    etatCourant.c_oflag &= ~CR0;
    etatCourant.c_oflag &= ~TAB0;
    etatCourant.c_oflag &= ~BS0;
    etatCourant.c_cc[VMIN] = 0;
    etatCourant.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &etatCourant);
    //   read(STDIN_FILENO, &toucheAvant, 1);
    //  touche = toucheAvant;
}

Clavier::~Clavier() {
    tcsetattr(STDIN_FILENO, TCSANOW, &etatInitial);
}

TOUCHES_CLAVIER Clavier::ScruterClavier() 
{
    
    TOUCHES_CLAVIER retour = AUCUNE;
    char touche = 0;
    int test = read(STDIN_FILENO, &touche, 1);

    if (test != -1) {
        switch (touche) {
        case '+':
            retour=PLUS;
            break;
        case '-':
            retour=MOINS;
            break;
        case ' ':
            retour=MODE;
            break;
        case '\n':
        case '\r':
            retour=FIN;
            break;
        default:
            retour=AUCUNE;
            break;

        }
    }

    return retour;
}

