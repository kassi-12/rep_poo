//
// Created by KASSIMI on 2/28/2024.
//

#include "Championnat.h"
void Championnat::ajouterMatch(Matchfoot ml){
    if (_tabMatchs.size() > Max_MATCHS){
        cout<<"[le nomber des Match est depasse la limite !!!]"<<endl;
    }else{
        _tabMatchs.push_back(ml);
    }
}
void Championnat::listeEquipes(){
    int l=0;
    int c=0;
    for(auto ml : _tabMatchs){
        for(int i = 0;i < sizeof(_tabEqPts);i++)
            if (_tabEqPts[i][1]==ml.getEquipeA())
        if (ml.compareResultat() == 1){
            _tabEqPts[l][c] = ml.getEquipeA();
            c=1;
            _tabEqPts[l][c] = 3;
            c=0;
            l++;
        }else if (ml.compareResultat() == -1){
            _tabEqPts[l][c] = ml.getEquipeb();
            c=1;
            _tabEqPts[l][c] = 3;
            c=0;
            l++;
        }else{
            _tabEqPts[l][c] = ml.getEquipeb();
            c=1;
            _tabEqPts[l][c] = 0;
            c=0;
            l++
        }
    }

}
