//
// Created by KASSIMI on 3/9/2024.
//

#ifndef TD3_TP_PRODUITALIMENTAIRE_H
#define TD3_TP_PRODUITALIMENTAIRE_H
#include "Produit.h"
#include <iostream>
#include <string>
class ProduitAlimentaire : virtual public Produit {
private :
    int _poid;
public :
    ProduitAlimentaire(){}
    ProduitAlimentaire(std::string name,double prix,int stock,int poid):Produit(name,prix,stock),_poid(poid){}
    void aff() override;
};


#endif //TD3_TP_PRODUITALIMENTAIRE_H
