#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

class Personne {
private:
    static int totalPersonnes;
    int id;
    string nom;
    string prenom;
    int age;

public:
    Personne(const string& nom_, const string& prenom_, int age_) : nom(nom_), prenom(prenom_), age(age_) {
        id = ++totalPersonnes;
    }

    void sePresenter() {
        cout << "[ID]=> " << id << endl;
        cout << "[Nom]=> " << nom << endl;
        cout << "[Prenom]=> " << prenom << endl;
        cout << "[Age]=> " << age << endl;
    }
    
    int getAge() const {
        return age;
    }
    int getID() const {
        return id;
    }

    friend istream& operator>>(istream& in, Personne& personne) {
        cout << "[Entrez le nom]=< ";
        cin.ignore();
        getline(in, personne.nom);
        cout << "[Entrez le prenom]=< ";
        getline(in, personne.prenom); 
        cout << "[Entrez l'age]=< ";
        in >> personne.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Personne& personne) {
        out << "[ID]=> " << personne.id << endl;
        out << "[Nom]=> " << personne.nom << endl;
        out << "[Prenom]=> " << personne.prenom << endl;
        out << "[Age]=> " << personne.age << endl;
        return out;
    }

    string getNom() const { return nom; }
    string getPrenom() const { return prenom; }

    void modifier() {
        int choix;

        do {
            system("cls");
            cout << "----------------------------------" << endl;
            cout << "|1) - pour le Nom                |" << endl;
            cout << "|2) - pour le Prenom             |" << endl;
            cout << "|3) - pour l'Age                 |" << endl;
            cout << "----------------------------------" << endl;
            cout << "[Entrez votre choix de modification]=< ";
            cin >> choix;

        } while (choix != 1 && choix != 2 && choix != 3);
        system("cls");
        cout << "[Entrez la nouvelle information]" << endl;

        if (choix == 1) {
            string nouveauNom;
            cout << "[Le Nom actuel est]=> " << nom << endl;
            cout << "[Entrez le nouveau Nom]=< ";
            cin.ignore();
            getline(cin, nouveauNom); 
            nom = nouveauNom;
            cout << "Modification reussie !" << endl;
        }
        else if (choix == 2) {
            string nouveauPrenom;
            cout << "[Le Prenom actuel est]=> " << prenom << endl;
            cout << "[Entrez le nouveau Prenom]=< ";
            cin.ignore();
            getline(cin, nouveauPrenom); 
            prenom = nouveauPrenom;
            cout << "Modification reussie !" << endl;
        }
        else if (choix == 3) {
            int nouvelAge;
            cout << "[L'age actuel est]=> " << age << endl;
            cout << "[Entrez le nouvel age]=< ";
            cin >> nouvelAge;
            age = nouvelAge;
            cout << "Modification reussie !" << endl;
        }
    }

};

int Personne::totalPersonnes = 0;

class Jeu {
protected:
    static int totalJeux;
    int id;
    string nom;
    int age;

public:
    Jeu(const string& nom_, int age_) : nom(nom_), age(age_) {
        id = ++totalJeux;
    }
    
    virtual void afficher() {
        cout << "[ID]=> " << id << endl;
        cout << "[Nom]=> " << nom << endl;
        cout << "[Age]=> " << age << endl;
    }
    virtual ~Jeu() {}

    virtual bool autorise(const vector<Personne>& per) const = 0;

    friend istream& operator>>(istream& in, Jeu& jeu) {
        cout << "[Entrez le nom du jeu]=< ";
        cin.ignore();
        getline(in, jeu.nom); 
        cout << "[Entrez l'age requis pour le jeu]=< ";
        in >> jeu.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Jeu& jeu) {
        out << "[ID]=> " << jeu.id << endl;
        out << "[Nom]=> " << jeu.nom << endl;
        out << "[Age]=> " << jeu.age << endl;
        return out;
    }

    string getNom() const { return nom; }
    int getAge() const { return age; }
};

int Jeu::totalJeux = 0;

class JeuExterieur : public Jeu {
private:
    double surface;

public:
    JeuExterieur(const string& nom_, int age_, double surface_) : Jeu(nom_, age_), surface(surface_) {}

    void afficher() override {
        Jeu::afficher();
        cout << "[Surface]=> " << surface << endl;
    }

    bool autorise(const vector<Personne>& per) const override {
        return (surface / per.size() > 0);
    }

    friend istream& operator>>(istream& in, JeuExterieur& jeu) {
        in >> static_cast<Jeu&>(jeu);
        cout << "[Entrez la surface du jeu exterieur]=< ";
        in >> jeu.surface;
        return in;
    }
};

class JeuInterieur : public Jeu {
private:
    double capaciteMax;

public:
    JeuInterieur(const string& nom_, int age_, double capaciteMax_) : Jeu(nom_, age_), capaciteMax(capaciteMax_) {}

    void afficher() override {
        Jeu::afficher();
        cout << "[Capacite Max]=> " << capaciteMax << endl;
    }

    bool autorise(const vector<Personne>& per) const override {
        return (per.size() <= capaciteMax);
    }

    friend istream& operator>>(istream& in, JeuInterieur& jeu) {
        in >> static_cast<Jeu&>(jeu);
        cout << "[Entrez la capacite maximale du jeu interieur]=< ";
        in >> jeu.capaciteMax;
        return in;
    }
};

template <typename T>
T verifieAutorisation(const T* jeu, const vector<Personne>& per, const Personne& perso) {
    return (jeu->autorise(per) && perso.getAge() >= jeu->getAge());
}

class ParcJeux {
private:
    vector<Jeu*> jeux;
    vector<Personne> per;
    static const int capacite = 6;
    int taille;

public:
    ParcJeux() : taille(0) {}

    void ajouterJeu(Jeu* jeu) {
        if (taille < ParcJeux::capacite) {
            jeux.push_back(jeu);
            taille++;
        }
    }

    void ajouterPersonne() {
        Personne p("", "", 0);
        cin >> p;

        per.push_back(p);
    }
    void afficherPersonnes() const {
        cout << "----{Liste des personnes}----" << endl;
        for (const auto& personne : per) {
            cout << personne << endl;
            cout << "[Jeux autorises pour cette personne]" << endl;
            for (const auto& jeu : jeux) {
                if (verifieAutorisation(jeu, per, personne)) {
                    cout << "   >- " << jeu->getNom() << endl;
                }
            }
            cout<<"\n--------------------"<<endl;
            cout << endl;
        }
    }
    void modifierPersonne() {
        int id;
        cout << "[Entrez l'ID de la personne a modifier]=< ";
        cin >> id;

        for (auto& personne : per) {
            if (personne.getID() == id) {
                personne.modifier();
                return;
            }
        }

        cout << "Personne avec l'ID specifie non trouvee." << endl;
    }

    void afficherJeux() const {
        cout << "----{Liste de jeux}----" << endl;
        for (const auto& jeu : jeux) {
            jeu->afficher();
            cout << "[Personnes autorisees pour ce jeu]" << endl;
            for (const auto& personne : per) {
                if (verifieAutorisation(jeu, per, personne)) {
                    cout << "   >- " << personne.getNom() << " " << personne.getPrenom() << " (ID: " << personne.getID() << ")" << endl;
                }
            }
			cout<<"\n--------------------"<<endl;
            cout << endl;
        }
    }
    void rechercherJeuParNom(const string& nom) {
        cout << "----{Resultat de la recherche}----" << endl;
        bool found = false;
        for (auto& jeu : jeux) {
            if (jeu->getNom() == nom) {
                jeu->afficher();
                found = true;
            }
        }
        if (!found) {
            cout << "Le jeu avec le nom '" << nom << "' n'existe pas." << endl;
        }
    }

    void exporterDonneesCSV(const string& fichier) {
        ofstream csvFile(fichier);
        if (!csvFile.is_open()) {
            cerr << "Erreur lors de l'ouverture du fichier : " << fichier << endl;
            return;
        }

        csvFile << "ID Personne, Nom, Prenom, Age, IDs des Jeux" << endl;
        for (size_t i = 0; i < per.size(); ++i) {
            csvFile << i + 1 << "," << per[i].getNom() << "," << per[i].getPrenom() << "," << per[i].getAge();

            vector<int> indicesJeux;
            for (size_t j = 0; j < jeux.size(); ++j) {
                if (verifieAutorisation(jeux[j], per, per[i])) {
                    indicesJeux.push_back(j + 1);
                }
            }

            for (size_t k = 0; k < indicesJeux.size(); ++k) {
                csvFile << "," << indicesJeux[k];
            }
            csvFile << endl;
        }

        csvFile << endl << "ID Jeu, Nom, Age requis, IDs des Personnes" << endl;
        for (size_t i = 0; i < jeux.size(); ++i) {
            csvFile << i + 1 << "," << jeux[i]->getNom() << "," << jeux[i]->getAge();

            vector<int> indicesPersonnes;
            for (size_t j = 0; j < per.size(); ++j) {
                if (verifieAutorisation(jeux[i], per, per[j])) {
                    indicesPersonnes.push_back(j + 1); 
                }
            }

            for (size_t k = 0; k < indicesPersonnes.size(); ++k) {
                csvFile << "," << indicesPersonnes[k];
            }
            csvFile << endl;
        }

        csvFile.close();
    }

    ~ParcJeux() {
        for (auto& jeu : jeux) {
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

    while (true) {
        cout << "---------------------{Menu}-----------------------\n";
        cout << "|1) - Ajouter une personne\t\t\t |\n";
        cout << "|2) - Afficher les jeux\t\t\t\t |\n";
        cout << "|3) - Afficher les personnes\t\t\t |\n";
        cout << "|4) - Rechercher un jeu par nom\t\t\t |\n";
        cout << "|5) - Modifier une personne\t\t\t |\n"; 
        cout << "|6) - Exporter les donnees dans un fichier Excel |\n";
        cout << "|7) - Quitter\t\t\t\t\t |\n"; 
        cout << "--------------------------------------------------\n";
        int choix;
        cout << "[Entrez votre choix]=< ";
        cin >> choix;
        system("cls");
        switch (choix) {
            case 1:
                P1.ajouterPersonne();
                system("cls");
                break;
            case 2:
                system("cls");
                P1.afficherJeux();
                break;
            case 3:
                system("cls");
                P1.afficherPersonnes();
                break;
            case 4:
                {
                    string nomJeu;
                    cout << "[Entrez le nom du jeu a rechercher]=< ";
                    cin.ignore();
                    getline(cin, nomJeu); 
                    P1.rechercherJeuParNom(nomJeu);
                    break;
                }
            case 5:
                P1.modifierPersonne();
                system("cls");
                break;
            case 6:
                P1.exporterDonneesCSV("donnees.csv");
                cout << "Donnees exportees dans 'donnees.csv'. Appuyez sur une touche pour continuer.";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 7:
                return 0;
            default:
                cout << "Choix incorrect." << endl;
                break;
        }
    }
}
