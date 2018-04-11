/********* Moteur de tournoi : joueur ***************/

#include <stdio.h>
#include "avalam.h"
#include "moteur.h"



void choisirCoup(T_Position currentPosition, T_ListeCoups listeCoups) {

    int flag = 0;
    int i = 0;
    int j = 0;
    int positionDestination;
    octet couleurOrigine;
    int numeroCoup;
    T_Colonne posOrigine;
    int nbDeCoups = 0;


    do{
        positionDestination = i;

        if(currentPosition.cols[i].nb <= 4){

            for (j = 0; j < listeCoups.nb; ++j){

                posOrigine = currentPosition.cols[listeCoups.coups[j].origine];
                //positionDuVoisin = listeCoups.coups[j].origine;
                if(listeCoups.coups[j].destination == positionDestination){
                    if(posOrigine.nb+currentPosition.cols[positionDestination].nb==5 && posOrigine.couleur == currentPosition.trait){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        else {

            for (j = 0; j < listeCoups.nb; ++j) {

                if (currentPosition.cols[j].couleur != currentPosition.trait) {

                    if (listeCoups.coups[j].destination == positionDestination) {
                        nbDeCoups++;
                    }

                    if (nbDeCoups == 1 && currentPosition.cols[listeCoups.coups[j].origine].couleur == currentPosition.trait){
                        flag = 1;
                    }
                }
            }
        }

        i++;
    }while(i<47 && flag!=1);

    if(flag == 1){
        ecrireIndexCoup(j);
    } else ecrireIndexCoup(rand()%listeCoups.nb);


}