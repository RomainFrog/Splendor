#include <iostream>

#include <QApplication>

//#include "../src/controleur/controleur.h"
#include "../src/carte/carte.h"
#include "../src/jeu/jeu.h"
#include "../src/pioche/pioche.h"
#include "../src/niveau/niveau.h"
#include "../src/plateau/plateau.h"
#include "../src/joueur/joueur.h"
#include "../src/controleur/controleur.h"

#include "../src/partie/vuePartie.h"
#include "../src/menu/vueNumberOfPlayers.h"

using namespace Splendor;

int main(int argc, char* argv[]){

    /*
    unsigned int nbj = 4;
    vector<std::string>names;
    names.push_back("Arthur");
    names.push_back("Emma");
    names.push_back("Francois");
    names.push_back("Romain"); */
    QApplication app(argc, argv);

    //VuePartie partie(nbj,names);
    //partie.show();
    vueNumberOfPlayers menu;
    menu.show();

    return app.exec();
}


//g++ -std=c++11 main.cpp ../src/carte/carte.cpp ../src/controleur/controleur.cpp ../src/jeu/jeu.cpp ../src/joueur/joueur.cpp ../src/niveau/niveau.cpp ../src/plateau/plateau.cpp ../src/type/type.cpp ../src/pioche/pioche.cpp -o main && ./main

//g++ -std=c++11 main.cpp ../src/controleur/controleur.cpp ../src/carte/carte.cpp ../src/niveau/niveau.cpp ../src/jeu/jeu.cpp ../src/type/type.cpp ../src/pioche/pioche.cpp ../src/plateau/plateau.cpp ../src/joueur/joueur.cpp -o main && ./main
