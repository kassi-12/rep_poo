//
// Created by KASSIMI on 3/9/2024.
//

#include "CompteEpargne.h"
//
// Created by KASSIMI on 3/9/2024.
//
#include <iostream>
using namespace std;
void CompteEpargne::Afficher() {
    cout<<"----[CONSULTATION]----"<<endl;
    cout<<"[ID]=>"<<_code<<endl;
    cout<<"[SOLD]=>"<<_solde<<endl;
}
void CompteEpargne::Deposer(unsigned int x) {
    cout<<"----[DEPOSER]----"<<endl;
    cout<<"[OLD SOLD]=>"<<getSold()<<endl;
    _solde=_solde+x;
    cout<<"[NEW SOLD]=>"<<getSold()<<endl;
}
void CompteEpargne::Retirer(unsigned int y) {
    cout<<"----[RETRAIT]----"<<endl;
    cout<<"[OLD SOLD]=>"<<getSold()<<endl;
    _solde=_solde-y;
    cout<<"[NEW SOLD]=>"<<getSold()<<endl;
}
void CompteEpargne::CalculInteret() {
    cout << "----[CALC INTERET]----" << endl;
    cout << "[OLD SOLD] => " << getSold() << endl;
    cout << "[INTERET] => " << _ti / 100.0 << endl;
    _solde = _solde - (_solde * (_ti / 100.0));
    cout << "[NEW SOLD] => " << getSold() << endl;
}

