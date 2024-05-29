//
// Created by KASSIMI on 2/21/2024.
//

#ifndef TP1_MATCHFOOT_H
#define TP1_MATCHFOOT_H
#include <iostream>
#include <string>
using namespace  std;

class Matchfoot {


private :
    int  _id;
    string _equipeA;
    string _equipeB;
    int _nbrButA;
    int _nbrButB;
public :
Matchfoot(){};
    Matchfoot(int id,string equipeA , string equipeB, int nbrButA, int nbrButB ,int EqPts) :_id(id),_equipeA(equipeA), _equipeB(equipeB),
                                                                          _nbrButA(nbrButA), _nbrButB(nbrButB),{}
    Matchfoot( const Matchfoot &m) {
        this->_equipeA = m._equipeA;
        this->_equipeB = m._equipeB;
        this->_nbrButA = m._nbrButA;
        this->_nbrButB = m._nbrButB;
}
    string getEquipeA();

    string getEquipeb();

    int getButA();
    int getId();

    int getButB();

    void setEquipeA( string x);

    void setEquipeb(string y);

    void setButA(int a);

    void setButB(int b);

    void affichMatch();

    void marqueBut(string eq);

    int compareResultat();

};

#endif //TP1_MATCHFOOT_H
