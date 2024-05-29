#include <iostream>
#include <string>
using namespace std;
class Ville {
	private :
	string name;
	int code;
	int Nbrj;
	public:
	Ville (string a="";int c=0;int n=0){
		name = a;
		code =c;
		Nbrj =n;
		 }
	void affv();
	void saiv();
	int compv();
};
int Ville::compv(Ville v1,Ville v2){
	int r;
	if( v1 == v2 ){p
		r = 1;
	}else {
		r = 0;
	}
	return r;
}
void Ville::saiv(string na,int co,int nb){
	name = na;
	code = co;
	Nbrj = nb;
}
void Ville::affv(){
	cout << "nom de ville : "<<name<<" code de ville :"<<code<<" nomber de visite : "<<endl;}

 
