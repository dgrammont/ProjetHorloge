#include "horloge.h"



Horloge::Horloge(const int _nbMode, const int _resolution):
    resolution(_resolution),
    nbModes(_nbMode)

{

    leCadran = new Cadran(5,5);
    leClavier = new Clavier();
    valAvant = time(NULL);
}

Horloge::~Horloge()
{
    delete leCadran;
    delete leClavier;
}

bool Horloge::AvancerHeures()
{
    bool retour = false;
    heures++;
    if(resolution==12){
        if(heures==13){
            heures=1;
            retour=true;
        }
        else{
            retour=false;
        }
    }else{
        if(heures==24){
            heures=0;
            retour = true;
        }

        else{
            retour = false;
        }

    }

    return retour;
}

bool Horloge::AvancerMinutes()
{
    bool retour = false;
    minutes++;
    if(minutes==60){
        minutes=0;
        retour=true;
    }
    else
    {
        retour=false;
    }
    return retour;
}



void Horloge::ReculerHeures()
{
    heures--;
    if(resolution==12){
        if(heures==-1){
            heures=12;

        }

    }else{
        if(heures==-1){
            heures=23;

        }


    }

}

void Horloge::ReculerMinutes()
{
    minutes--;
    if(minutes==-1){
        minutes=60;
    }
}

void Horloge::ActualiserHeure()
{
    time_t valCourante = time(NULL);
    double seconde=difftime(valCourante,valAvant);
    if(seconde>1)//àmodifierpourallerplusvitependantletest
    {
        valAvant=valCourante;
        if(AvancerMinutes())
            AvancerHeures();
    }
}

TOUCHES_CLAVIER Horloge::Controler(const TOUCHES_CLAVIER _numTouche)
{
    TOUCHES_CLAVIER touche=leClavier->ScruterClavier();
    if(touche==MODE){
        ChangerMode();
    }
    switch (mode) {
    case REGLAGE_HEURE:
            if(touche==PLUS){
            AvancerHeures();
            }
            if(touche==MOINS){
                ReculerHeures();
            }
            leCadran->Afficher("HH",1);
            leCadran->Afficher(heures,4);
        break;
    case REGLAGE_MINUTES:
        if(touche==PLUS){
            AvancerMinutes();
        }
        if(touche==MOINS){
            ReculerMinutes();
        }
        leCadran->Afficher("MM",1);
        leCadran->Afficher(minutes,4);
        break;

    case AUCUN_REGLAGE:
        ActualiserHeure();
        leCadran->Afficher(heures,1);
        leCadran->Afficher(minutes,4);
        break;
    }

    return touche;
}




void Horloge::ChangerMode()
{
    mode++;
    if(mode==nbModes){
        mode=0;
    }
}
