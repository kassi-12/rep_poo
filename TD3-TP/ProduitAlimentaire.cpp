//
// Created by KASSIMI on 3/9/2024.
//
#include <iostream>
#include "ProduitAlimentaire.h"
using namespace std;
void ProduitAlimentaire::aff(){
    cout<<"[nom]=>"<<_name<<endl;
    cout<<"[prix]=>"<<_prix<<endl;
    cout<<"[stock]=>"<<_stock<<endl;
    cout<<"[poid]=>"<<_poid<<endl;
}