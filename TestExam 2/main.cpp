#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Personne {
protected:
    string nom;
    int age;

public:
    Personne(string n, int a) : nom(n), age(a) {
        if (age < 0)
            throw runtime_error("Invalid age");
    }

    string getNom() const {
        return nom;
    }

    int getAge() const {
        return age;
    }

    void setNom(const string &no) {
        nom = no;
    }

    void setAge(int ag) {
        if (ag < 0)
            throw runtime_error("Invalid age");
        age = ag;
    }

    virtual void afficher() const = 0;
    virtual ~Personne() {}
};

class Eleve : virtual public Personne {
protected:
    vector<double> notes;

public:
    Eleve(string n, int a, vector<double> no) : Personne(n, a), notes(no) {
        for (const auto &note : notes) {
            if (note < 0 || note > 20) {
                throw runtime_error("Invalid note in the initial list");
            }
        }
    }

    void ajouterNote(double no) {
        if (no > 20 || no < 0)
            throw runtime_error("Invalid note");
        notes.push_back(no);
    }

    bool supprimerNote(unsigned int i) {
        if (i < notes.size()) {
            notes.erase(notes.begin() + i);
            return true;
        }
        return false;
    }

    double getMoyenneNote() const {
        double sum = 0.0;
        if (!notes.empty()) {
            for (auto &no : notes) {
                sum += no;
            }
            return sum / notes.size();
        }
        return 0.0;
    }

    void afficher() const override {
        cout << "[nom] => " << nom << endl;
        cout << "[age] => " << age << endl;
        cout << "[moyenne] => " << getMoyenneNote() << endl;
    }

    void imprimerBulletin() const {
    cout << "Bulletin de " << nom << " :" << endl;
    cout << "Age : " << age << endl;
    cout << "Notes :" << endl;
    int i = 1;
    for (const auto &note : notes) {
        try {
            if (note < 0 || note > 20) {
                throw runtime_error("Invalid note found while printing the bulletin.");
            }
            cout << "Note " << i << " : " << note << endl;
            i++;
        } catch (const runtime_error &e) {
            cout << "[Error] => " << e.what() << endl;
        }
    }
}



};

class Professeur : virtual public Personne {
protected:
    string sujet;

public:
    Professeur(string n, int a, string s) : Personne(n, a), sujet(s) {}

    string getSujet() const {
        return sujet;
    }

    void setSujet(const string &s) {
        sujet = s;
    }

    void afficher() const override {
        cout << "[nom] => " << nom << endl;
        cout << "[age] => " << age << endl;
        cout << "[sujet] => " << sujet << endl;
    }
};

template <typename T>
class Ecole {
private:
    vector<T> tab;

public:
    void ajouter(T obj) {
        tab.push_back(obj);
    }

    bool supprimer(unsigned int i) {
        if (i < tab.size()) {
            tab.erase(tab.begin() + i);
            return true;
        }
        return false;
    }

    void afficherTout() const {
        for (const auto &obj : tab) {
            obj->afficher();
        }
    }

    ~Ecole() {
        for (auto &obj : tab) {
            delete obj;
        }
    }
};

int main() {
    try {
        Ecole<Personne*> ecole;

        vector<double> notes1 = {15.5, 18.0, 14.0};
        vector<double> notes2 = {16.5, 12.0, 13.0};
        vector<double> notes3 = {17.5, 19.0, 20.0};
        vector<double> notes4 = {10.5, 9.0, 8.0};
        vector<double> notes5 = {18.5, 17.0, 16.0};

        Eleve E1("zigga", 20, notes1);
        Eleve E2("tigga", 22, notes2);
        Eleve E3("nigga", 23, notes3);
        Eleve E4("migga", 20, notes4);
        Eleve E5("rigga", 24, notes5);

        ecole.ajouter(&E1);
        ecole.ajouter(&E2);
        ecole.ajouter(&E3);
        ecole.ajouter(&E4);
        ecole.ajouter(&E5);

        string sujet1 = "m";
        string sujet2 = "p";
        string sujet3 = "c";
        string sujet4 = "b";
        string sujet5 = "h";

        Professeur P1("A", 45, sujet1);
        Professeur P2("B", 50, sujet2);
        Professeur P3("C", 55, sujet3);
        Professeur P4("D", 40, sujet4);
        Professeur P5("E", 35, sujet5);

        ecole.ajouter(&P1);
        ecole.ajouter(&P2);
        ecole.ajouter(&P3);
        ecole.ajouter(&P4);
        ecole.ajouter(&P5);

        ecole.afficherTout();

        E1.ajouterNote(19.5);

        try {
            E2.ajouterNote(105);
        } catch (const runtime_error &e) {
            cout << "[Error] => " << e.what() << endl;
        }

        E1.afficher();
        P1.setSujet("AM");
        P1.afficher();

        if (ecole.supprimer(3)) {
            cout << "[Done]" << endl;
        } else {
            cout << "[Not Done]" << endl;
        }

        E1.imprimerBulletin();
        E5.imprimerBulletin();
	
    } catch (const exception &e) {
        cout << "[Error] => " << e.what() << endl;
    }

    return 0;
}
