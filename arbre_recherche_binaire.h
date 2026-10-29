#ifndef NOEUD_BINAIRE_H
#define NOEUD_BINAIRE_H

#include <iostream>
using namespace std;

class NoeudBinaire {
private:
    int valeur;
    NoeudBinaire* gauche;
    NoeudBinaire* droite;

public:
    // Constructeur
    NoeudBinaire(int val) : valeur(val), gauche(nullptr), droite(nullptr) {}

    // Getters
    int getValeur() { return valeur; }
    NoeudBinaire* getGauche() {return gauche;}
    NoeudBinaire* getDroite() {return droite;}
    // Construction : insertion d'une valeur
    NoeudBinaire* inserer(int val) {
        if (val < valeur) {
            if (gauche == nullptr)
                gauche = new NoeudBinaire(val);
            else
                gauche->inserer(val);
        }
        else if (val > valeur) {
            if (droite == nullptr)
                droite = new NoeudBinaire(val);
            else
                droite->inserer(val);
        }

        return this;
    }

    // Recherche
    bool rechercher(int val) {
        if (val == valeur)
            return true;

        if (val < valeur) {
            if (gauche == nullptr)
                return false;
            return gauche->rechercher(val);
        }

        if (droite == nullptr)
            return false;

        return droite->rechercher(val);
    }
    // cherche le minimum dans l'arbre binaire de recherche
    NoeudBinaire* minimum() {
        NoeudBinaire* courant = this;

        while (courant->gauche != nullptr) {
            courant = courant->gauche;
        }

        return courant;
    }

    NoeudBinaire* suppression(int val) {
        if (val < valeur) {
            if (gauche != nullptr) {
                gauche = gauche->suppression(val);
            }
        }
        else if (val > valeur) {
            if (droite != nullptr) {
                droite = droite->suppression(val);
            }
        }
        else {
            // Cas 1 : aucun fils
            if (gauche == nullptr && droite == nullptr) {
                delete this;
                return nullptr;
            }

            // Cas 2 : un seul fils droite
            if (gauche == nullptr) {
                NoeudBinaire* temp = droite;
                gauche = nullptr;
                droite = nullptr;
                delete this;
                return temp;
            }

            // Cas 2 : un seul fils  gauche
            if (droite == nullptr) {
                NoeudBinaire* temp = gauche;
                gauche = nullptr;
                droite = nullptr;
                delete this;
                return temp;
            }

            // Cas 3 : deux fils
            NoeudBinaire* temp = droite->minimum();
            valeur = temp->valeur;
            droite = droite->suppression(temp->valeur);
        }

        return this;
    }
    int taille() {
    int compteur = 1; // Le nœud actuel

    if (gauche != nullptr) {
        compteur += gauche->taille();
    }

    if (droite != nullptr) {
        compteur += droite->taille();
    }

    return compteur;
}


    // Affichage infixe
    void afficher() {
        if (gauche != nullptr) gauche->afficher();

        cout << valeur << " ";

        if (droite != nullptr)  droite->afficher();
    }
};
#endif