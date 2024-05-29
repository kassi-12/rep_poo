#include <iostream>
#include <string>

using namespace std;

class Vehicule {
protected:
    float _vits;
    float _cx;
    int _nbrRoue;

public:
    Vehicule(float const &vits, float const &cx, int const &nbrRoue) : _vits(vits), _cx(cx), _nbrRoue(nbrRoue) {}
    virtual ~Vehicule() {}
    virtual void Afficher() = 0;
    virtual float CalcVits()=0;
};

class Voiture : public Vehicule {
public:
    Voiture(float const &vits, float const &cx, int const nbrRoue = 4) : Vehicule(vits, cx, nbrRoue) {}
    void Afficher() override {
        cout << "[Vitesse Limit]=> " << _vits << endl;
        cout << "[Coef Aerodynamic]=> " << _cx << endl;
        cout << "[Nombre des roues]=> " << _nbrRoue << endl;
    }
    float CalcVits() override {
        return (1 - _cx) * _vits / _nbrRoue;
    }
};

class Camion : public Vehicule {
private:
    float _carg;

public:
    Camion(float const &vits, float const &cx, float const &carg, int const nbrRoue = 12) : Vehicule(vits, cx, nbrRoue), _carg(carg) {}

    void Afficher() override {
        cout << "[Vitesse Limit]=> " << _vits << endl;
        cout << "[Coef Aerodynamic]=> " << _cx << endl;
        cout << "[Nombre des roues]=> " << _nbrRoue << endl;
        cout << "[Type de cargo]=> " << _carg << endl;
    }
      float CalcVits() override {
        return 2*(1 - _cx) * _vits / _nbrRoue*_carg;
    }


};

int main() {
 
    Voiture v(120.0, 0.25);
    cout << "vooiture : " << endl;
    v.Afficher(); 
    cout << "calc speed: " << v.CalcVits() << endl;

    Camion c(80.0, 0.35, 12.6);
    cout << "camion :" << endl;
    c.Afficher(); 
    cout << "clac speed: " << c.CalcVits() << endl;

    return 0;
}

