#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>

#include "../carte/carte.h"
#include "../jeu/jeu.h"
#include "../joueur/joueur.h"
#include "../niveau/niveau.h"
#include "../plateau/plateau.h"
#include "../splendorException/splendorexception.h"
#include "../type/type.h"


namespace Splendor{


    class Controleur{
        private:
            //Attributes
            unsigned int nbJoueurs;
            Plateau plateau;
            vector<Joueur*> joueurs;

        public:
            Controleur(unsigned int nbj);

            ~Controleur() = default;
            Controleur(const Controleur&) = default;
            Controleur& operator=(const Controleur&) = default;

            int getNbJoueurs() const { return nbJoueurs; }
            Plateau& getPlateau() { return plateau; }
            Joueur& getJoueur(unsigned int i);

            // ------------ Action du joueur --------------
            void acheterCarte(Joueur& j, const Carte& c, Plateau& p);
            void prendreRessource(Joueur& j, unsigned int i, Plateau& p);
            void selectCarte(Joueur& j, const Carte&c, Plateau &p);

            // ------------ Controle des tours --------------
            

    };
}



#endif