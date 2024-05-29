//
// Created by KASSIMI on 2/21/2024.
//

#include "Matchfoot.h"
string Matchfoot::getEquipeA(){
    return _equipeA;
}

string Matchfoot::getEquipeb(){
    return _equipeB;
}
int Matchfoot::getId(){
    return _id;
}
int Matchfoot::getButA(){
    return _nbrButA;
}

int Matchfoot::getButB(){
    return _nbrButB;
}

void Matchfoot::affichMatch(){
    cout<<"[ID Match]=>"<<_id<<endl;
    cout<<"[equipeA]=>"<<_equipeA<<endl;
    cout<<"[number of buts]=>"<<_nbrButA<<endl;
    cout<<"[equipeA]=>"<<_equipeB<<endl;
    cout<<"[number of buts]=>"<<_nbrButB<<endl;
}

void Matchfoot::marqueBut(string eq){
    if(eq == "A"){
        _nbrButA += 1;
        cout<<"-----le resultat-------"<<endl;
        affichMatch();
    }else {
        _nbrButB += 1;
        cout<<"-----le resultat-------"<<endl;
        affichMatch();
    }
}

int Matchfoot::compareResultat() {
    if (_nbrButA > _nbrButB) {
        return 1;

    } else if (_nbrButB > _nbrButA) {
        return -1;
    } else {
        return 0;
    }
}
void Matchfoot::setEquipeA( string x){
    _equipeA = x;
}

    void Matchfoot::setEquipeb(string y){
        _equipeB =y;

}

    void Matchfoot::setButA(int a){
    _nbrButA = a;
}
    void Matchfoot::setButB(int b){
    _nbrButB = b;
}