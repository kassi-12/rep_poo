#include <iostream>
#include <vector>
#include <string>

using namespace std;

class produit {
private:
    string namepro;
    vector<float> prixpro;
    static int c;

public:
    void saiserpro();
    void affpro();
    void moy();
    void maxmin();
    void meme();

    produit() {
        namepro = "";
        produit::c++;
    }
};

int produit::c = 0;

void produit::saiserpro() {
    int i;
    float prix;
    int taille;
    cout << "Entrer le nom de produit : " << endl;
    cin >> namepro;
    cout << "La taille du tableau : " << endl;
    cin >> taille;
    for (i = 1; i <= taille; i++) {
        cout << "Entrer le prix de magasin " << i << " :" << endl;
        cin >> prix;
        prixpro.push_back(prix);
    }
}

void produit::affpro() {
    int i;
    int taille_1 = prixpro.size();
    cout << "Nom produit : " << namepro << endl;
    cout << "Les prix de produit : " << endl;
    for (i = 0; i < taille_1; i++) {
        cout << "Le prix de magasin " << i + 1 << " : " << prixpro[i] << endl;
    }
}


void produit::moy() {
    float cp = 0;
    float mo;
    int i;
    int taille_2 = prixpro.size();
    for (i = 0; i < taille_2; i++) {  
        cp = cp + prixpro[i];
    }
    mo = cp / taille_2;
    cout << "La moyenne des prix : " << mo << " DH " << endl;
}

void produit::maxmin() {
    float min = prixpro[0];
    float max = prixpro[0];
	int i;
	int taille_3 = prixpro.size();
    for (i = 0; i < taille_3 ; i++) {
		float tmp = prixpro[i];
        if (tmp < min) {
            min = tmp;
        }
        if (tmp > max) {
            max = tmp;
        }
    }
cout << "Le min : " << min <<" DH " << " Le max : "<< max<<" DH "<< endl;
}
void produit::meme() {
    int i, j;
    int taille_3 = prixpro.size();

    for (i = 0; i < taille_3; i++) {
        float me1 = prixpro[i];

        for (j = 0; j < taille_3; j++) {
            float me2 = prixpro[j];

            if (me1 == me2 && i != j && i < j) {
                cout << "Le prix du Magasin " << i + 1 << " est " << me1 << " DH. Le même prix que le magasin " << j + 1 << " est " << me2 << " DH." << endl;
            }
        }
    }
}


int main() {
    produit p;
    p.saiserpro();
    p.affpro();
    p.moy();
    p.maxmin();
    p.meme();
    return 0;
}

