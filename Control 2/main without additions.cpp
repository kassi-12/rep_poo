#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Jeu {
protected:
    string _nom;
    int _age;

public:
    Jeu(string nom, int age) : _nom(nom), _age(age) {}
    virtual void afficher() {
        cout << "[Nom]=> " << _nom << endl;
        cout << "[Age]=> " << _age << endl;
    }
    virtual ~Jeu() {} 
};

class JeuExterieur : public Jeu {
private:
    double _surface;

public:
    JeuExterieur(string nom, int age, double surface) : Jeu(nom, age), _surface(surface) {}
    void afficher() override {
        Jeu::afficher();
        cout << "[Surface]=> " << _surface << endl;
    }
};

class JeuInterieur : public Jeu {
private:
    double _CapaciteMax;

public:
    JeuInterieur(string nom, int age, double CapaciteMax) : Jeu(nom, age), _CapaciteMax(CapaciteMax) {}
    void afficher() override {
        Jeu::afficher();
        cout << "[Capacite Max]=> " << _CapaciteMax << endl;
    }
};

class ParcJeux {
private:
    vector<Jeu *> jeux;
    static const int capacite = 6;
    int taille;

public:
    ParcJeux() : taille(0) {} 
    void ajouterJeu(Jeu *jeu) {
        if (taille < ParcJeux::capacite) { 
            jeux.push_back(jeu);
            taille++; 
        }
    }
    void afficherjeux() {
        cout<<"----{list de jeux}----"<<endl;
        for (auto &jeu : jeux) {
        
            jeu->afficher();
            cout<<endl;
        }
    }
    ~ParcJeux() {
        for (auto &jeu : jeux) {
            delete jeu; 
        }
    }
};

int main() {
    ParcJeux P1;
    
    Jeu* J1 = new JeuExterieur("E-Boy", 18, 12.5);
    Jeu* J2 = new JeuExterieur("Outdoor Game", 20, 15.0);
    Jeu* J3 = new JeuExterieur("Garden Fun", 15, 10.0);
    
    Jeu* J4 = new JeuInterieur("Indoor Game", 10, 30.0);
    Jeu* J5 = new JeuInterieur("Table Tennis", 12, 20.0);
    Jeu* J6 = new JeuInterieur("Board Game", 8, 15.0);
    
    P1.ajouterJeu(J1);
    P1.ajouterJeu(J2);
    P1.ajouterJeu(J3);
    P1.ajouterJeu(J4);
    P1.ajouterJeu(J5);
    P1.ajouterJeu(J6);
    
    P1.afficherjeux();
    
    return 0;
}
