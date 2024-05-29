#include <iostream>
using namespace std;
#include "ComptePayant.h"
#include "CompteEpargne.h"
int main() {
    cout<<"----[COMPTE 1]----"<<endl;
    Compte C1;
    C1.Afficher();
    C1.Deposer(100);
    C1.Retirer(200);
    cout<<"----[COMPTE EPARGNE]----"<<endl;
    CompteEpargne C2;
    C2.Afficher();
    C2.Deposer(1000);
    C2.Retirer(240);
    C2.CalculInteret();
    cout<<"----[COMPTE PAYANT]----"<<endl;
    ComptePayant C3(300);
    C3.Afficher();
    C3.Deposer(500);
    C3.Retirer(240);
    return 0;
}
