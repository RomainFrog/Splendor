#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "../carte/carte.h"
#include <map>
#include <array>

using namespace std;

namespace Splendor{


class Jeu{
    protected:
        map<Type, vector<Carte*>> cartes;

        struct Handler{
            Jeu* instance;
            Handler():instance(nullptr) {}
        };
        static Handler handler;

        Jeu();
        ~Jeu() = default;
        Jeu(const Jeu&) = delete;
        Jeu& operator=(const Jeu&) = delete;
        
    public:
        static Jeu& getInstance();
        static void freeInstance();
        /* //TODO: const*/ vector<Carte*> getCartes(Type t){ return cartes[t]; }
        int getNbCartes(Type t){return cartes[t].size();}

};

/*class Jeu_Classique:public Jeu{
    Jeu_Classique();
};

class Jeu_Cite:public Jeu{
    Jeu_Cite();
};*/

}

#endif // JEU_H_INCLUDED