//
// Created by KASSIMI on 3/9/2024.
//
#include <iostream>
#include "ComptePayant.h"
using namespace std;
void ComptePayant::Afficher() {
    cout<<"----[CONSULTATION]----"<<endl;
    cout<<"[ID]=>"<<_code<<endl;
    cout<<"[SOLD]=>"<<_solde<<endl;
}
void ComptePayant::Deposer(unsigned int x) {
    cout<<"----[DEPOSER]----"<<endl;
    cout<<"[OLD SOLD]=>"<<getSold()<<endl;
    _solde=_solde+x;
    cout<<"[NEW SOLD]=>"<<getSold()<<endl;
}
void ComptePayant::Retirer(unsigned int y) {
    cout<<"----[RETRAIT]----"<<endl;
    cout<<"[OLD SOLD]=>"<<getSold()<<endl;
    _solde=_solde-y;
    cout<<"[ -5 DH DE VAUT]"<<endl;
    _solde=_solde-_vaut;
    cout<<"[NEW SOLD]=>"<<getSold()<<endl;
}