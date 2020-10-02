/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clavier.h
 * Author: philippe
 *
 * Created on 31 décembre 2018, 17:11
 */

#ifndef CLAVIER_H
#define CLAVIER_H
#include <termios.h>
#include <unistd.h>

enum TOUCHES_CLAVIER
{
    AUCUNE,
    FIN,
    MODE,
    PLUS,
    MOINS
};

class Clavier {
public:
    Clavier();
    ~Clavier();
    TOUCHES_CLAVIER ScruterClavier();
    
private:
    struct termios etatInitial ;

};

#endif /* CLAVIER_H */

