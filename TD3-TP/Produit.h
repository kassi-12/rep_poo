//
// Created by KASSIMI on 3/9/2024.
//

#ifndef TD3_TP_PRODUIT_H
#define TD3_TP_PRODUIT_H

#include <iostream>
#include <string>
class Produit {
protected:
    std::string _name;
    double _prix;
    int _stock;
public:
    Produit(){}
    Produit(std::string name,double prix,int stock):_name(name),_prix(prix),_stock(stock){}

    virtual void aff();
};


#endif //TD3_TP_PRODUIT_H
