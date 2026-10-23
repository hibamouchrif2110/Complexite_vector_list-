
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    ifstream fichier("million.txt");

    if (!fichier.is_open()) {
        cout << "Erreur : impossible d'ouvrir million.txt" << endl;
        return 1;
    }

    vector<string> mots;
    string mot;
    while (fichier >> mot) {
        mots.push_back(mot);
    }
    fichier.close();
    list<string> coll;
    auto debut = high_resolution_clock::now();

    for (const string& m : mots) {
        coll.push_back(m);
    }
    auto fin = high_resolution_clock::now();

    auto duree = duration_cast<microseconds>(fin - debut);

    cout << "Nombre de mots inseres : "
         << coll.size() << endl;

    cout << "Temps d'insertion dans la list : "
         << duree.count() << " microsecondes" << endl;

    return 0;
}
