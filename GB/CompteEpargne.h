//
// Created by KASSIMI on 3/9/2024.
//

#ifndef GB_COMPTEEPARGNE_H
#define GB_COMPTEEPARGNE_H
#include <iostream>
#include "Compte.h"

class CompteEpargne : public Compte {
private  :
    static int const  _ti = 6 ;
public :
    CompteEpargne(){
    _solde = 0;
}
    CompteEpargne(double solde){

        _solde = 0;
}
    void Afficher() override;
    void CalculInteret();
    void Deposer(int unsigned x) override;
    void Retirer(int unsigned y) override;
};


#endif //GB_COMPTEEPARGNE_H
