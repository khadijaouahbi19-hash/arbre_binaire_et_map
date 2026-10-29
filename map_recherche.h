
#ifndef ARBRE_MAP_H
#define ARBRE_MAP_H

#include <map>

class ArbreMap {
private:
    std::map<int, int> arbre;

public:
    void inserer(int val) {
        arbre[val] = val;
    }

    bool rechercher(int val) {
        return arbre.find(val) != arbre.end();
    }

    bool supprimer(int val) {
        return arbre.erase(val) > 0;
    }

    int taille() {
        return static_cast<int>(arbre.size());
    }
};

#endif
