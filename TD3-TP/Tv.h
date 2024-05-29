//
// Created by KASSIMI on 3/10/2024.
//

#ifndef TD3_TP_TV_H
#define TD3_TP_TV_H

#include "ProduitAlimentaire.h"
#include "AppareilElectronique.h"
class Tv : public ProduitAlimentaire, public AppareilElectronique {
private:
    int _pouce;

public:
    Tv() {}
    Tv(int pouce, const ProduitAlimentaire& p, const AppareilElectronique& a)
            : _pouce(pouce), Produit(p), ProduitAlimentaire(p), AppareilElectronique(a) {}
    void aff()  ;

};


#endif //TD3_TP_TV_H
