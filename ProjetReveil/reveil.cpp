#include "reveil.h"

/**
 * @brief Reveil::Reveil
 * @param _nbModes
 * @param _resolution
 * @details le constructeur qui met par defaut l'alarme en desactiver
 */
Reveil::Reveil(const short _nbModes, const short _resolution):
    Horloge(_nbModes,_resolution)
{
    enAlarme=false;
    alarme=false;
}
/**
 * @brief Reveil::AvancerHeuresAlarme
 * @details permet d'avancer l'heure de l'alarme
 */
void Reveil::AvancerHeuresAlarme()
{

    heuresAlarme++;
    if(resolution==12){
        if(heuresAlarme==13){
            heuresAlarme=1;
        }
    }
    else{
        if(heuresAlarme==24){
            heuresAlarme=0;
        }
    }
}
/**
 * @brief Reveil::AvancerMinutesAlarme
 * @details permet d'avancer la minute de l'alarme
 */
void Reveil::AvancerMinutesAlarme()
{
    {

        minutesAlarme++;
        if(minutesAlarme==60){
            minutesAlarme=0;

        }


    }
}
/**
 * @brief Reveil::ReculerHeuresAlarme
 * @details permet de reculer l'heure de l'alarme
 */
void Reveil::ReculerHeuresAlarme()
{
    heuresAlarme--;
    if(resolution==12){
        if(heuresAlarme==-1){
            heuresAlarme=12;

        }

    }else{
        if(heuresAlarme==-1){
            heuresAlarme=23;

        }


    }

}
/**
 * @brief Reveil::ReculerMinutesAlarme
 * @details permet de reculer les minutes de l'alarme
 */
void Reveil::ReculerMinutesAlarme()
{
    {
        minutesAlarme--;
        if(minutesAlarme==-1){
            minutesAlarme=60;
        }
    }
}
/**
 * @brief Reveil::SurveillerAlarme
 * @details verifi si il est la meme heure que l'alarme
 */
void Reveil::SurveillerAlarme()
{
    if(alarme==true){
        if(heures==heuresAlarme && minutes==minutesAlarme){
            laSonnerie.FaireSonner();
            enAlarme=true;
        }
    }
}
/**
 * @brief Reveil::Controler
 * @param _numTouche
 * @return
 * @details la fonction qui verifis quel touche est appyer pour donne un ordre en fonctionne de celle-ci
 */
TOUCHES_CLAVIER Reveil::Controler( TOUCHES_CLAVIER _numTouche)
{

    _numTouche=Horloge::Controler(_numTouche);
    if((_numTouche==PLUS || _numTouche ==MOINS) && enAlarme){
        laSonnerie.ArreterAlarme();
        enAlarme =false;
        _numTouche=AUCUNE;
    }

    switch (mode) {

    case AUCUN_REGLAGE:
        SurveillerAlarme();
        break;
    case REGLAGE_HEURES_ALARME:
        if(_numTouche==PLUS){
            AvancerHeuresAlarme();
        }
        if(_numTouche==MOINS){
            ReculerHeuresAlarme();
        }
        leCadran->Afficher("HA",1);
        leCadran->Afficher(heuresAlarme,4);
        break;
    case REGLAGE_MINUTES_ALARME:
        if(_numTouche==PLUS){
            AvancerMinutesAlarme();
        }
        if(_numTouche==MOINS){
            ReculerMinutesAlarme();
        }
        leCadran->Afficher("MA",1);
        leCadran->Afficher(minutesAlarme,4);
        break;
    case ACTIVATION_ALARME:

        leCadran->Afficher("AA ",1);
        if(_numTouche==PLUS){
            alarme=true;

        }
        if(_numTouche==MOINS){
           alarme=false;

        }
        if(alarme){
            leCadran->Afficher("ON ",4);
        }
        else {
            leCadran->Afficher("OFF",4);
        }

        break;

    default:
        break;
    }
    return _numTouche;
}

