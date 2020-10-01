#include <iostream>
#include <unistd.h>
#include "cadran.h"
using namespace std;

/**
 * @brief main
 * @details le programme principale qui teste le bon fonctionnement du programme et des fonctions
 * @details ici un cadran qui fait un compte a rebours de 0 a 10 et l'ou on peut modifier la couleur du texte et du cadran en changant les parametre dans le constructeur
 * @author dylan grammont
 * @date   :   01/09/2020
 */

int main()
{


    Cadran leCadran;
    Cadran unAutreCadran(5,1,2,20,100,93);
    leCadran.Afficher(10,0);
    leCadran.Afficher("h",2);
    leCadran.Afficher(50,3);
    leCadran.Afficher("m",5);
    unAutreCadran.Afficher(10,2,2);
    unAutreCadran.Effcaer();
    for(int i=10;i>=0;i--){

        unAutreCadran.Afficher(i,5,2);
        sleep(1);
        unAutreCadran.Effcaer();
    }
    unAutreCadran.Afficher("Fin",5,2);

    char touche;
    cin>>touche;
    return 0;
}
//Quelle est la position du cadran sur l’écran,
//indiquer le nombre de ligne et lalargeur de l’afficheur (nombre de caractères affichables)
//pos = 2 , ligne = 3 , largeur = 8
