#ifndef SONNERIE_H
#define SONNERIE_H
#include "cadran.h"
class Sonnerie
{
public:
    Sonnerie();
    ~Sonnerie();
    void FaireSonner();
    void ArreterAlarme();
private:
    Cadran * cadranAlarme;
};

#endif // SONNERIE_H
