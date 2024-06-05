#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Cours {
	protected : 
		string titre;
		string code;
		int nbrcre;
		string prof;
	public :
		Cours(string t,string c,int n,string p):titre(t),code(c),nbrcre(n),prof(p){}
		virtual void afficher(){
			cout<<"[titre]=>"<<titre<<endl;
			cout<<"[code]=>"<<code<<endl;
			cout<<"[nbr credits]=>"<<nbrcre<<endl;
			cout<<"[professeur]=>"<<prof<<endl;
			}
		virtual ~Cours(){}
};
class CoursEnLigne : public Cours{
	private : 
		string plateforme;
		string lien;
	public :
	CoursEnLigne(string t,string c,int n,string p,string pla,string li):Cours(t,c,n,p),plateforme(pla),lien(li){}
	void afficher() override{
		Cours::afficher();
		cout<<"[plateforme]=>"<<plateforme<<endl;
		cout<<"[lien]=>"<<lien<<endl;
		}
};
template<typename T>class Conteneur{
	private : 
		vector<Cours *>tabcours;
	public :
		void afficher(){
			for(auto c : tabcours){
				cout<<endl;
				c->afficher();
			}
	}
	void supprimer(int i){
		if(tabcours.size() > 0 && i > 0 ){
			tabcours.erase(tabcours.begin()+i);
			
		}
	}
	void ajouter(T *c){
		tabcours.push_back(c);
		}
};
int main(){
Conteneur<Cours >tab;
Cours* C1 = new Cours ("c++","C1",1,"prof1");
Cours* C2= new Cours("php","C2",2,"prof2");
Cours* C3 = new CoursEnLigne("sql","C3",3,"prof3","doc.com","doc.com/sql");
Cours* C4 = new CoursEnLigne("js","C4",4,"prof4","pdf.com","pdf.com/js");
tab.ajouter(C1);
tab.ajouter(C2);
tab.ajouter(C3);
tab.ajouter(C4);
cout<<"--[afficher]--"<<endl;

tab.afficher();
cout<<endl;
cout<<"--[afficher apres supprision]--"<<endl;
tab.supprimer(2);
cout<<endl;
tab.afficher();


}
