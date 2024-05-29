#include <iostream>
#include <math.h>
using namespace std;

class number {
private:
    float *re = new float;
    float *im = new float;

public:
    number(float a = 0, float b = 0) {
        *re = a;
        *im = b;
        delete re;
        delete im;
   
    }

    void sai();
    void RemplirTC(number tab[], int taille);
    void afficherTC(number tab[], int taille);
    void afficher();
    void afficherReel();
    void Getmin();
    float module();
};

void number::sai() {
    cout << "Enter real: ";
    cin >> *re;
    cout << "Enter img: ";
    cin >> *im;
}

void number::RemplirTC(number tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        tab[i].sai();
    }
}

void number::afficher() {
    cout << "Real: " << *re << " Imagin: " << *im << endl;
}

void number::afficherReel() {
    cout << "eal: " << re << endl;
}

float number::module() {
    return sqrt(pow(*re, 2) + pow(*im, 2));
}
void  number::afficherTC(number tab[], int taille){
 for (int i = 0; i < taille; i++) {
		cout << "les number complexe : "<<endl;
        tab[i].afficher();
    }
}
void  number::Getmin(number tab[], int taille){
	float temp = tab[0].module();
	for (int i = 1; i < taille; i++) {
        temp = tab[i].module();
        if (tab[i].module() < temp){
			temp = tab[i].module();
			
			}
    }
    cout << "les number complexe plus petit : "<<endl; 
        tab[i].afficher();
}

int main() {
    int taille;
    cout << "Enter la taille : ";
    cin >> taille;
    number *tab;
    tab = new number[taille]; 

    tab[0].RemplirTC(tab, taille);
    tab[0].afficherTC();
    tab[0].afficherReel();
    cout << "Module: " << tab[0].module() << endl;

    delete[] tab;

    return 0;
}
