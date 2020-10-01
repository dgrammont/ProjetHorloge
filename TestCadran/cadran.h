/**
  * @file   :   cadran.h
  * @author :   Philippe Cruchet
  * @author :   modifié par Dylan Grammont
  * @date   :   24/08/2020
  * @date   :   fini le 01/09/2020
  * @detail :   Assure la gestion d'un cadran en mode texte
  *             à partir des séquences d’échappement ANSI
  */

#ifndef CADRAN_H
#define CADRAN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>

using namespace std;

class Cadran
{
public:
    Cadran(const int _posX=1,const int _posY=1,const int _hauteur=1,const int _largeur=7,const int _couleurFond=42,const int _couleurTtext=33);
    ~Cadran();
    void Afficher(const string _texte, const int _position=0,const int _ligne=1);
    void Afficher(const int _valeur, const int _position=0,const int _ligne=1);
    void Effcaer();
private:
    void PositionnerCurseur(const int _posx, const int _posy);
    /// coordonnée en X du premier caractère dans le cadran
    int ligne;
    /// coordonnée en Y du premier caractère dans le cadran
    int colone;
    /// nombre de lignes du cadran
    int hauteur;
    /// nombre de caractères par ligne
    int largeur;
    ///couleur du fond
    int couleurFond;
    /// couleur du Text
    int couleurText;
};

#endif // CADRAN_H
