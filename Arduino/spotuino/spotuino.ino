/***************************************************************************
* Author   : 
* Created  : 
* Edited   : 
*
* >>> spotuino.ino : sketch principal du projet
*
* Comments :
*****************************************************************************/

// Inclure les bibliothèques (header files = .h)
#include "pitches.h"    // Bibliothèque pour les notes de musique
#include "vma209.h"     // Défintions du mapping des pins du shield
#include "spotuino.h"   // Fonctions du projet

// Global variables


// Setting pins mode and init
void setup() {

}

/* ************************************* MAIN LOOP ******************************************* */
void loop() {
    char choix = 'y';

    bool reponse = ModifieMonVehicule(choix);

}
/* ********************************* END MAIN LOOP *******************************************  */
