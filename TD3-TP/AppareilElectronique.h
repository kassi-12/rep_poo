 //
// Created by KASSIMI on 3/9/2024.
//

#ifndef TD3_TP_APPAREILELECTRONIQUE_H
#define TD3_TP_APPAREILELECTRONIQUE_H
#include "Produit.h"
#include <iostream>
#include <string>
class AppareilElectronique : virtual public Produit {
private :
    std::string _puis;
    std::string _mrq;
public :
    AppareilElectronique(){}

    AppareilElectronique(std::string name,double prix,int stock,std::string puis,std::string mrq):Produit(name,prix,stock),_puis(puis),_mrq(mrq){}
    void aff() override;
};


#endif //TD3_TP_APPAREILELECTRONIQUE_H
