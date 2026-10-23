#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;
int main(){
    vector<int> coll={1,2,3,4,5,6,7,8,9};
    cout<< "vector avant reverse :";
    for(int n : coll){
        cout<< n<<" ";

    }
    vector<int> coll_rev(coll.rbegin(),coll.rend());
    
    reverse(coll.begin(),coll.end());
    cout<<"\n vector apres reverse :";
    for(int n : coll){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}

// reverser une partie du vector 
/*#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coll = {1,2,3,4,5,6,7,8,9};

    cout << "Vector avant reverse : ";
    for (int n : coll)
        cout << n << " ";

    int debut, fin;

    cout << "\nEntrez la position de debut (1 a 9) : ";
    cin >> debut;

    cout << "Entrez la position de fin (1 a 9) : ";
    cin >> fin;

    if (debut >= 1 && fin <= coll.size() && debut <= fin) {
        reverse(coll.begin() + (debut - 1),
                coll.begin() + fin);

        cout << "Vector apres reverse : ";
        for (int n : coll)
            cout << n << " ";
    } else {
        cout << "Positions invalides !";
    }

    cout << endl;
    return 0;
}*/
//avec reverse_iterator
/*#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coll = {1,2,3,4,5,6,7,8,9};

    cout << "Vector avant reverse : ";
    for (int n : coll)
        cout << n << " ";

    int debut, fin;

    cout << "\nEntrez la position de debut (1 a 9) : ";
    cin >> debut;

    cout << "Entrez la position de fin (1 a 9) : ";
    cin >> fin;

    if (debut >= 1 && fin >= debut && fin <= (int)coll.size()) {
        // Convertir les positions choisies en positions inverses
        auto rdebut = coll.rbegin() + (coll.size() - fin);
        auto rfin = coll.rbegin() + (coll.size() - debut + 1);

        reverse(rdebut, rfin);

        cout << "Vector apres reverse : ";
        for (int n : coll)
            cout << n << " ";
    } else {
        cout << "Positions invalides !";
    }

    cout << endl;
    return 0;
}*/