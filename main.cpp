
#include <iostream>
#include <chrono>
#include <iomanip>
#include "arbre_recherche_binaire.h"
#include "map_recherche.h"

using namespace std;
using namespace std::chrono;

const int N = 40000;
const int REPETITIONS = 100000;

int main() {
    NoeudBinaire* racine = new NoeudBinaire(7);
    ArbreMap arbreMap;

    // ==========================================
    // 1. INSERTION
    // ==========================================

    auto debutManuel = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        racine->inserer(i);
    }

    auto finManuel = high_resolution_clock::now();

    auto tempsInsertionManuel =
        duration_cast<microseconds>(finManuel - debutManuel);

    auto debutMap = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        arbreMap.inserer(i);
    }

    auto finMap = high_resolution_clock::now();

    auto tempsInsertionMap =
        duration_cast<microseconds>(finMap - debutMap);

    cout << "\n========== INSERTION ==========\n";

    cout << "Taille arbre manuel : "
         << racine->taille() << endl;

    cout << "Taille map          : "
         << arbreMap.taille() << endl;

    cout << "Temps arbre manuel : "
         << tempsInsertionManuel.count()
         << " microsecondes\n";

    cout << "Temps map          : "
         << tempsInsertionMap.count()
         << " microsecondes\n";


    // ==========================================
    // 2. RECHERCHE
    // ==========================================

    int valRecherche;

    cout << "\nDonner le nombre a rechercher (0 a "
         << N - 1 << ") : ";
    cin >> valRecherche;

    int compteurManuel = 0;
    int compteurMap = 0;

    auto debutRechercheManuel = high_resolution_clock::now();

    for (int i = 0; i < REPETITIONS; i++) {
        if (racine->rechercher(valRecherche)) {
            compteurManuel++;
        }
    }

    auto finRechercheManuel = high_resolution_clock::now();

    auto tempsRechercheManuel =
        duration_cast<microseconds>(
            finRechercheManuel - debutRechercheManuel
        );

    auto debutRechercheMap = high_resolution_clock::now();

    for (int i = 0; i < REPETITIONS; i++) {
        if (arbreMap.rechercher(valRecherche)) {
            compteurMap++;
        }
    }

    auto finRechercheMap = high_resolution_clock::now();

    auto tempsRechercheMap =
        duration_cast<microseconds>(
            finRechercheMap - debutRechercheMap
        );

    cout << "\n========== RECHERCHE ==========\n";

    cout << "Resultat arbre manuel : "
         << (compteurManuel > 0 ? "Valeur trouvee" : "Non trouvee")
         << endl;

    cout << "Resultat map          : "
         << (compteurMap > 0 ? "Valeur trouvee" : "Non trouvee")
         << endl;

    cout << "Nombre de recherches : "
         << REPETITIONS << endl;

    cout << fixed << setprecision(2);

    cout << "Temps total arbre manuel : "
         << tempsRechercheManuel.count()
         << " microseconds\n";

    cout << "Temps total map          : "
         << tempsRechercheMap.count()
         << " microseconds\n";

    cout << "Temps moyen arbre manuel : "
         << (double)tempsRechercheManuel.count() / REPETITIONS
         << " microseconds/recherche\n";

    cout << "Temps moyen map          : "
         << (double)tempsRechercheMap.count() / REPETITIONS
         << " microseconds/recherche\n";


    // ==========================================
    // 3. SUPPRESSION
    // ==========================================

    int valSuppression;

    cout << "\nDonner le nombre a supprimer (0 a "
         << N - 1 << ") : ";
    cin >> valSuppression;

    auto debutSuppressionManuel = high_resolution_clock::now();

    bool existeManuel = racine->rechercher(valSuppression);

    if (existeManuel) {
        racine = racine->suppression(valSuppression);
    }

    auto finSuppressionManuel = high_resolution_clock::now();

    auto tempsSuppressionManuel =
        duration_cast<microseconds>(
            finSuppressionManuel - debutSuppressionManuel
        );

    auto debutSuppressionMap = high_resolution_clock::now();

    bool existeMap = arbreMap.supprimer(valSuppression);

    auto finSuppressionMap = high_resolution_clock::now();

    auto tempsSuppressionMap =
        duration_cast<microseconds>(
            finSuppressionMap - debutSuppressionMap
        );

    cout << "\n========== SUPPRESSION ==========\n";

    cout << "Suppression arbre manuel : "
         << (existeManuel ? "Reussie" : "Valeur inexistante")
         << endl;

    cout << "Suppression map          : "
         << (existeMap ? "Reussie" : "Valeur inexistante")
         << endl;

    cout << "Temps arbre manuel : "
         << tempsSuppressionManuel.count()
         << " microseconds\n";

    cout << "Temps map          : "
         << tempsSuppressionMap.count()
         << " microseconds\n";


    // ==========================================
    // 4. TAILLE FINALE
    // ==========================================

    cout << "\n========== TAILLE FINALE ==========\n";

    cout << "Arbre manuel : "
         << (racine != nullptr ? racine->taille() : 0)
         << endl;

    cout << "Map          : "
         << arbreMap.taille() << endl;

    return 0;
}
