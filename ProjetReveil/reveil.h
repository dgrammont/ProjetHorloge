#ifndef REVEIL_H
#define REVEIL_H
#include "horloge.h"
#include "sonnerie.h"
enum MODE_REVEIL{
    REGLAGE_HEURES_ALARME=3,
    REGLAGE_MINUTES_ALARME,
    ACTIVATION_ALARME
};

class Reveil : public Horloge
{
public:
    Reveil(const short _nbModes=6,const short _resolution=24);
    void AvancerHeuresAlarme();
    void AvancerMinutesAlarme();
    void ReculerHeuresAlarme();
    void ReculerMinutesAlarme();
    void SurveillerAlarme();
    TOUCHES_CLAVIER Controler( TOUCHES_CLAVIER _numTouche=AUCUNE);
private:
    Sonnerie laSonnerie;
    int heuresAlarme;
    int minutesAlarme;
    bool alarme;
    bool enAlarme;
};

#endif // REVEIL_H
