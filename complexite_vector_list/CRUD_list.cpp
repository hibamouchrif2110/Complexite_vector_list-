#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace std::chrono;

int main() {
    list<string> coll;
    string mot;

    // 1. Ouvrir le fichier
    ifstream fichier("million.txt");

    if (!fichier.is_open()) {
        cout << "Erreur : impossible d'ouvrir million.txt" << endl;
        return 1;
    }

    // 2. Lire le fichier et mesurer le temps d'insertion
    auto debutInsertionFichier = high_resolution_clock::now();

    while (fichier >> mot) {
        coll.push_back(mot);
    }

    auto finInsertionFichier = high_resolution_clock::now();
    fichier.close();

    cout << "Nombre de mots lus : " << coll.size() << endl;
    cout << "Temps d'insertion depuis le fichier : "
         << duration_cast<microseconds>(
                finInsertionFichier - debutInsertionFichier
            ).count()
         << " microsecondes" << endl;

    int choix;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Inserer un mot au debut" << endl;
        cout << "2. Inserer un mot a une position choisie" << endl;
        cout << "3. Inserer un mot a la fin" << endl;
        cout << "4. Rechercher un mot" << endl;
        cout << "5. Rechercher et supprimer un mot par son nom" << endl;
        cout << "6. Supprimer plusieurs mots par leur nom" << endl;
        cout << "7. Afficher le nombre de mots" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        string nouveauMot;

        switch (choix) {

        // 1. Insertion au debut
        case 1: {
            cout << "Mot a inserer : ";
            cin >> nouveauMot;

            auto debut = high_resolution_clock::now();

            coll.push_front(nouveauMot);

            auto fin = high_resolution_clock::now();

            cout << "Temps d'insertion au debut : "
                 << duration_cast<microseconds>(fin - debut).count()
                 << " microsecondes" << endl;
            break;
        }

        // 2. Insertion a une position choisie
        case 2: {
            long long position;

            cout << "Position d'insertion (de 1 a "
                 << coll.size() + 1 << ") : ";
            cin >> position;

            if (position < 1 ||
                static_cast<unsigned long long>(position) > coll.size() + 1) {
                cout << "Position invalide." << endl;
                break;
            }

            cout << "Mot a inserer : ";
            cin >> nouveauMot;

            auto debut = high_resolution_clock::now();

            auto it = coll.begin();

            // Avancer jusqu'a la position choisie
            advance(it, position - 1);

            coll.insert(it, nouveauMot);

            auto fin = high_resolution_clock::now();

            cout << "Temps d'insertion : "
                 << duration_cast<microseconds>(fin - debut).count()
                 << " microsecondes" << endl;
            break;
        }

        // 3. Insertion a la fin
        case 3: {
            cout << "Mot a inserer : ";
            cin >> nouveauMot;

            auto debut = high_resolution_clock::now();

            coll.push_back(nouveauMot);

            auto fin = high_resolution_clock::now();

            cout << "Temps d'insertion a la fin : "
                 << duration_cast<microseconds>(fin - debut).count()
                 << " microsecondes" << endl;
            break;
        }

        // 4. Recherche d'un mot
        case 4: {
            cout << "Mot a rechercher : ";
            cin >> mot;

            auto debut = high_resolution_clock::now();

            auto pos = find(coll.begin(), coll.end(), mot);

            auto fin = high_resolution_clock::now();

            cout << "Temps de recherche : "
                 << duration_cast<microseconds>(fin - debut).count()
                 << " microsecondes" << endl;

            if (pos != coll.end()) {
                cout << "Mot trouve." << endl;
            } else {
                cout << "Mot introuvable." << endl;
            }

            break;
        }

        // 5. Recherche et suppression d'un seul mot
        case 5: {
            cout << "Quel mot veux-tu supprimer ? ";
            cin >> mot;

            auto debutRecherche = high_resolution_clock::now();

            auto pos = find(coll.begin(), coll.end(), mot);

            auto finRecherche = high_resolution_clock::now();

            cout << "Temps de recherche : "
                 << duration_cast<microseconds>(
                        finRecherche - debutRecherche
                    ).count()
                 << " microsecondes" << endl;

            if (pos != coll.end()) {
                auto debutSuppression = high_resolution_clock::now();

                coll.erase(pos);

                auto finSuppression = high_resolution_clock::now();

                cout << "Mot supprime : " << mot << endl;
                cout << "Temps de suppression : "
                     << duration_cast<microseconds>(
                            finSuppression - debutSuppression
                        ).count()
                     << " microsecondes" << endl;
            } else {
                cout << "Mot introuvable : aucune suppression." << endl;
            }

            break;
        }

        // 6. Suppression de plusieurs mots
        case 6: {
            size_t nombre;

            cout << "Combien de mots veux-tu supprimer ? ";
            cin >> nombre;

            // Saisir les mots avant le chronometrage
            vector<string> motsASupprimer;

            for (size_t i = 0; i < nombre; ++i) {
                string motASupprimer;

                cout << "Nom du mot numero " << i + 1 << " : ";
                cin >> motASupprimer;

                motsASupprimer.push_back(motASupprimer);
            }

            // Debut du chronometrage global
            auto debutSuppression = high_resolution_clock::now();

            for (const string& motASupprimer : motsASupprimer) {
                auto pos = find(
                    coll.begin(),
                    coll.end(),
                    motASupprimer
                );

                if (pos != coll.end()) {
                    coll.erase(pos);
                    cout << "Mot supprime : "
                         << motASupprimer << endl;
                } else {
                    cout << "Mot introuvable : "
                         << motASupprimer << endl;
                }
            }

            // Fin du chronometrage global
            auto finSuppression = high_resolution_clock::now();

            cout << "Temps total de suppression de tous les mots : "
                 << duration_cast<microseconds>(
                        finSuppression - debutSuppression
                    ).count()
                 << " microsecondes" << endl;

            cout << "Nombre de mots restants : "
                 << coll.size() << endl;

            break;
        }

        // 7. Nombre d'elements
        case 7: {
            cout << "Nombre de mots dans la liste : "
                 << coll.size() << endl;
            break;
        }

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide." << endl;
        }

    } while (choix != 0);

    return 0;
}