#include "sonnerie.h"
#include "cadran.h"
#include <ostream>
#include <fstream>

/**
 * @brief Sonnerie::Sonnerie
 * @details crée dynamique un cadran et le suprime si il est diferent de nulptr
 */
Sonnerie::Sonnerie():
    cadranAlarme(nullptr)
{
    if(cadranAlarme!=nullptr)
        delete cadranAlarme;
    cadranAlarme = new Cadran(10,10);
}
/**
 * @brief Sonnerie::~Sonnerie
 * @details suprime le cadran si
 */
Sonnerie::~Sonnerie()
{
    if(cadranAlarme!=nullptr)
        delete cadranAlarme;
    cadranAlarme=nullptr;
}

void Sonnerie::FaireSonner()
{

    cadranAlarme->Afficher("Alarme");

}

void Sonnerie::ArreterAlarme()
{
    cadranAlarme->Effcaer();
}
