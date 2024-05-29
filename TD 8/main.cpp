#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Livre {
protected:
    string titre;
    string auteur;
    string editeur;
    int annepub;
public:
    Livre(string t, string a, string e, int an) : titre(t), auteur(a), editeur(e), annepub(an) {}
    
    virtual void afficher() {
        cout << "[titre] => " << titre << endl;
        cout << "[auteur] => " << auteur << endl;
        cout << "[editeur] => " << editeur << endl;
        cout << "[annee de publication] => " << annepub << endl;
    }
    virtual	~Livre(){}
};

class LivreNumerique : public Livre {
private:
    double taille_fich;
    string format_fich;
public:
    LivreNumerique(string t, string a, string e, int an, double tf, string f) 
        : Livre(t, a, e, an), taille_fich(tf), format_fich(f) {}
		 void afficher() override {
        cout << "[titre] => " << titre << endl;
        cout << "[auteur] => " << auteur << endl;
        cout << "[editeur] => " << editeur << endl;
        cout << "[annee de publication] => " << annepub << endl;
        cout << "[format Fichier ] => " << format_fich << endl;
        cout << "[Taille fichier ] => " << taille_fich <<" Mb" <<endl;
        
    }
};

template <class T>
class Conteneur {
private:
    vector<T*> tabconteneur;
public:
    void ajouter(T* item) {
        tabconteneur.push_back(item);
    }
    
    void afficher() {
        for (auto item : tabconteneur) {
            item->afficher();
        }
    }
    
    void supprime(int index) {
        
            tabconteneur.erase(tabconteneur.begin() + index);
        
    }
};

int main() {
    Livre* livre1 = new Livre("C++ ", "kassimi", "Abde", 1997);
    Livre* livre2 = new LivreNumerique("sql", "sabi", "houssam", 1999, 5.5, "PDF");
    
    Conteneur<Livre> conteneur;
    conteneur.ajouter(livre1);
    conteneur.ajouter(livre2);
    
    cout << "conteneur:" << endl;
    
    conteneur.afficher();
    
    conteneur.supprime(0);
    cout<<"\n---------------\n";
    cout << " suppression:" << endl;
    conteneur.afficher();
    
   
    delete livre1;
    delete livre2;

    return 0;
}
