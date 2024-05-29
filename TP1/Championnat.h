//
// Created by KASSIMI on 2/28/2024.
//

#ifndef TP1_CHAMPIONNAT_H
#define TP1_CHAMPIONNAT_H

#include <vector>
#include "Matchfoot.h"
#include <string>
using namespace std;

class Championnat {
private:
    static  const int Max_MATCHS =40;
    static  const int Max_equipe =10;
    vector<Matchfoot>_tabMatchs;
    int _nbrMatchs;
    string  _tabEqPts[10][2];
public:
    Championnat(){}
   void ajouterMatch(Matchfoot ml);
   void listeEquipes();

};


#endif //TP1_CHAMPIONNAT_H
