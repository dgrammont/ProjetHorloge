#include <iostream>
#include "reveil.h"
using namespace std;

int main()
{
    Reveil unReveil;
    TOUCHES_CLAVIER laTouche=AUCUNE;
    do{
        laTouche=unReveil.Controler(laTouche);
    }while(laTouche!=FIN);
    return 0;


}
