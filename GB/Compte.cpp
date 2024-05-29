//
// Created by KASSIMI on 3/9/2024.
//
#include <iostream>
#include "Compte.h"
int Compte::_code = 0;
using namespace std;
int Compte::getSold() {
    return _solde;
}
void Compte::Afficher() {
    cout<<"----[CONSULTATION]----"<<endl;
    cout<<"[ID]=>"<<_code<<endl;
    cout<<"[SOLD]=>"<<_solde<<endl;
}
void Compte::Deposer(unsigned int x) {
    cout<<"----[DEPOSER]----"<<endl;
    cout<<"[OLD SOLD]=>"<<getSold()<<endl;
    _solde=_solde+x;
    cout<<"[NEW SOLD]=>"<<getSold()<<endl;
}
void Compte::Retirer(unsigned int y) {
    cout<<"----[RETRAIT]----"<<endl;
    cout<<"[OLD SOLD]=>"<<getSold()<<endl;
    _solde=_solde-y;
    cout<<"[NEW SOLD]=>"<<getSold()<<endl;
}