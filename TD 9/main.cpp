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
        cout << "[anne de pub] => " << annepub << endl;
    }
    virtual ~Livre() {}
};

class LivreNumerique : public Livre {
private: 
    float taille_f;
    string format_f;
public: 
    LivreNumerique(string t, string a, string e, int an, float tf, string ff) : Livre(t, a, e, an), taille_f(tf), format_f(ff) {}
    void afficher() override {
        Livre::afficher();
        cout << "[taille ficher] => " << taille_f << endl;
        cout << "[format ficher] => " << format_f << endl;
    }
};

template <typename T>
class Conteneur {
private: 
    vector<T> tabLivre;
public: 
    void afficher() {
        for (auto l : tabLivre) {
            l->afficher();
        }
    }
    void ajouter(T liv) {
        tabLivre.push_back(liv);
    }
    void supprimer(int i) {
      
        tabLivre.erase(tabLivre.begin() + i);
    }
};

int main() {
    Conteneur<Livre*> conteneur;
    Livre* L1 = new Livre("kassimi", "abderrahmane", "none", 2024);
    Livre* L2 = new Livre("ismail", "heyoukan", "none", 2024);
    Livre* L3 = new LivreNumerique("hamza", "nejte", "none", 2022, 3.4f, "PDF");
    Livre* L4 = new LivreNumerique("houssame", "sabi", "none", 2023, 2.5f, "EPUB");
    
    conteneur.ajouter(L1);
    conteneur.ajouter(L2);
    conteneur.ajouter(L3);
    conteneur.ajouter(L4);

    cout << "-------[afficher]------" << endl;
    conteneur.afficher();
    cout << "-------[afficher apres suppression]------" << endl;
    conteneur.supprimer(3); 
    conteneur.afficher();

    
    delete L1;
    delete L2;
    delete L3;
  

    return 0;
}
