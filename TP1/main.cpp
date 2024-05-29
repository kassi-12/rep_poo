#include "Matchfoot.h"
#include <istream>
using namespace std;
int main (){
    Matchfoot M1;
    Matchfoot M2("france","bresil",0,0);
    Matchfoot M3("Maroc","Niger",4,3);
    Matchfoot M4(M3);
    M4.affichMatch();
    cout<<"-------------"<<endl;
    M2.marqueBut("A");
    M2.marqueBut("B");
    cout<<"-------------"<<endl;
    M2.compareResultat();
    M3.compareResultat();
    return 0;
}