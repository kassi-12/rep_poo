//
// Created by KASSIMI on 3/9/2024.
//

#ifndef GB_COMPTEPAYANT_H
#define GB_COMPTEPAYANT_H
#include <iostream>
#include "Compte.h"
class ComptePayant : public Compte {
private :
    static int const _vaut = 5;
public :

    ComptePayant(double solde){

        _solde = solde;
    }
    ComptePayant(){
    _solde = 0;
}

    void Afficher() override;
    void Deposer(int unsigned x) override;
    void Retirer(int unsigned y) override;


};


#endif //GB_COMPTEPAYANT_H
