#ifndef HORLOGE_H
#define HORLOGE_H
#include <unistd.h>
#include <Clavier.h>
#include <cadran.h>
#include <time.h>
enum modeHorloge{
    AUCUN_REGLAGE,
    REGLAGE_HEURE,
    REGLAGE_MINUTES
};

class Horloge
{
public:
    Horloge(const int _nbMode=3,const int _resolution=24);
    ~Horloge();
    bool AvancerHeures();
    bool AvancerMinutes();
    void ReculerHeures();
    void ReculerMinutes();
    void ActualiserHeure();
    void Controler();
    TOUCHES_CLAVIER Controler(TOUCHES_CLAVIER _numTouche=AUCUNE);
    void ChangerMode();
private:
    int heures=10;
    int minutes=43;
    const int resolution;
    const int nbModes;
    int mode=0;
    time_t valAvant;
    Clavier *leClavier;
    Cadran *leCadran;

};

#endif // HORLOGE_H
