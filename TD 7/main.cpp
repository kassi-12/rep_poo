#include <iostream>
#include <string>
#define p  3.14
using namespace std;

class Forme {
public:
    virtual double superficie() const = 0;
};

class Carre : public Forme {
private:
    double _cote;
public:
    Carre(const double &cote) : _cote(cote) {}
    double superficie() const override {
        return _cote * _cote;
    }
};

class Cercle : public Forme {
private:
    double _rayon;
public:
    Cercle(const double &rayon) : _rayon(rayon) {}
    double superficie() const override {
        return p * _rayon * _rayon;
    }
};

class Rectangle : public Forme {
private:
    double _longueur;
    double _largeur;
public:
    Rectangle(const double &longueur, const double &largeur) : _longueur(longueur), _largeur(largeur) {}
    double superficie() const override {
        return _longueur * _largeur;
    }
};

template <typename T>
double CalculerSuperficie(const T& forme) {
    return forme.superficie();
}

int main() {
    Carre C1(1);
    Cercle Ce1(1);
    Rectangle Re1(2, 2);
    cout << "[Superficie de Carre]=> " << CalculerSuperficie(C1) << endl;
    cout << "[Superficie de Cercle]=> " << CalculerSuperficie(Ce1) << endl;
    cout << "[Superficie de Rectangle]=> " << CalculerSuperficie(Re1) << endl;
    return 0;
}
