//
// Created by KASSIMI on 3/9/2024.
//

#ifndef GB_COMPTE_H
#define GB_COMPTE_H


class Compte {
protected:
    static int _code;
    double _solde;
public :

    Compte(double solde){
        _solde = 0;
    }
    Compte() {
        _code++;
        _solde = 0;
    }
    virtual int getSold();
    virtual void Afficher();
    virtual void Deposer(int unsigned x);
    virtual void Retirer(int unsigned y);
};


#endif //GB_COMPTE_H
