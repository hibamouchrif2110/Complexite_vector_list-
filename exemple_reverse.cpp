#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <list>
using namespace std;
using namespace std::chrono;
// EN ITILISANT VECTOR 
int main(){
    //create list with elements from 1 to 9
    vector<int> coll={1,2,3,4,5,6,7,8,9};
    auto debut = high_resolution_clock::now();
    vector<int>::const_iterator pos;
    pos=find(coll.cbegin(),coll.cend(),5);
    auto fin = high_resolution_clock::now();
    auto duree = duration_cast<nanoseconds>(fin - debut);
    cout<< "pos: " << *pos<< endl;
     cout << "Temps de recherche : " << duree.count()
         << " nanosecondes" << endl;
    vector<int>::const_reverse_iterator rpos(pos);
    cout <<"rpos :"<< *rpos<< endl;

}


// EN UTILISANT LIST
/*int main() {
    // Créer une liste avec des éléments de 1 à 9
    list<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Mesurer le temps de recherche de 5
    auto debut = high_resolution_clock::now();
    list<int>::const_iterator pos;
    pos = find(coll.cbegin(), coll.cend(), 5);
    auto fin = high_resolution_clock::now();
    auto duree = duration_cast<nanoseconds>(fin - debut);
    cout << "pos : " << *pos << endl;
    cout << "Temps de recherche : " << duree.count()
         << " nanosecondes" << endl;
    // Créer un itérateur inverse à partir de pos
    list<int>::const_reverse_iterator rpos(pos);
    cout << "rpos : " << *rpos << endl;

    return 0;
}*/