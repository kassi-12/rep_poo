//
// Created by KASSIMI on 3/9/2024.
//

#ifndef TD3_TP_VETEMENT_H
#define TD3_TP_VETEMENT_H
#include "Produit.h"
#include <string>
class Vetement : virtual public Produit {
public :
    std::string _color;
    int _taille;
public:
    Vetement(){}
    Vetement(std::string name,double prix,int stock,std::string color,int taille):Produit(name,prix,stock),_color(color),_taille(taille){}
    void aff() ;
};


#endif //TD3_TP_VETEMENT_H
