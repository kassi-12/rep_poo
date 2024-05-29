#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Employe {
	protected : 
	string nom;
	float salaire;
	public : 
	Employe(string n,float s):nom(n),salaire(s){}
	virtual void Afficher()=0;
};
class EmployeHoraire : public Employe {
	private : 
	int HeurT;
	public	: 
	EmployeHoraire(string n,float s,int h):Employe(n,s),HeurT(h){}
	void Afficher() override {
		cout<<"[NOM]=>"<<nom<<endl;
		cout<<"[SALAIRE]=>"<<salaire<<endl;
		cout<<"[HEURES DE TRAVAILES]=>"<<HeurT<<endl;
		}
	};
class EmployeSalaireFixe  : public Employe {
	private : 
		float prime;
		public : 
	EmployeSalaireFixe(string n,float s,float p):Employe(n,s),prime(p){}
	void Afficher() override {
		cout<<"[NOM]=>"<<nom<<endl;
		cout<<"[SALAIRE]=>"<<salaire<<endl;
		cout<<"[PRIME]=>"<<prime<<endl;
		}
	};
class EmployeCommission : public Employe{
	private : 
		float ventes;
	public : 
	EmployeCommission(string n,float s,float v):Employe(n,s),ventes(v){}
	void Afficher() override {
		cout<<"[NOM]=>"<<nom<<endl;
		cout<<"[SALAIRE]=>"<<salaire<<endl;
		cout<<"[VENTES]=>"<<ventes<<endl;
		}
	
	};
class Entreprise {
private:
    vector<Employe *> tabE;
    static const int cap = 5;
    int taille = 0;

public:
    Entreprise() {}


    void AjouterEmploye(Employe *e) {
        if (taille < cap) {
            tabE.push_back(e);
            taille++;
        }
        }
  

    void AfficherEmployes() {
        for (auto emp : tabE) {
            emp->Afficher();
            cout << endl;
        }
    }
};
int main() {
    Entreprise e;

    Employe *emp1 = new EmployeHoraire("A", 20.5, 40);
    Employe *emp2 = new EmployeSalaireFixe("B", 3000, 500);
    Employe *emp3 = new EmployeCommission("C", 2000, 1000);

    e.AjouterEmploye(emp1);
    e.AjouterEmploye(emp2);
    e.AjouterEmploye(emp3);

    e.AfficherEmployes();


    return 0;
}
