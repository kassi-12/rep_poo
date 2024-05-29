#include <iostream>
#include <string>
#include <vector>
using namespace std;
class livre {
	private :
	string titre;
	string auteur;
	long int isbn;
	bool statut;
	public :
	string GetTitre();
	string GetAuteur();
	long int GetIsbn();
	bool GetStatut();
	void GetVer();
	void SetEmp();
	void SetRet();
	void SetStatut();
	livre(string titre="", string auteur="", long int isbn=0, bool statut=false) {
    this->titre = titre;
    this->auteur = auteur;
    this->isbn = isbn;
    this->statut = statut;
}

	
};
string livre::GetTitre(){
	return titre;
}
string livre::GetAuteur(){
	return auteur;
}
long int livre::GetIsbn(){
	return isbn;
}
bool livre::GetStatut(){
	return statut;
}
void livre::GetVer() {
    bool ver;
    ver = GetStatut();

    if (ver == true) {
        cout << "Le livre est emprunte." << endl;
    } else {
        cout << "Le livre n'est pas emprunte." << endl;
    }
}

void livre::SetEmp( ){
	statut = true;
}
void livre::SetRet( ){
	statut = false;
}

void livre::SetStatut(){
	string ch;
	do {
            do {
                cout << "Bonjour, votre commande emprunte ou retourne ? " << endl;
                cin >> ch;
				ch = tolower(ch);
				} while (ch != "emprunte" && ch != "retourne");
				if (ch == "emprunte") {
				SetEmp();
				} else {
				SetRet();
				}
				} while (ch != "exit");
}

class user{
	private :
		string nom;
		string prenom;
		long int id_user;
		vector<string>list_livem;
		vector<string>list_livre;
	public :
	string GetNom();
	string GetPre();
	long int GetId();
	vector<string> GetLivem();
	vector<string> GetLivre();
	void SetLiv();
	void SetRliv();
	void info();
	user(string nom="",string prenom="",long int id_user=0,vector<string>list_livem,vector<string>list_livre){
			this->nom = nom;
			this->prenom = prenom;
			this->id_user =id_user;
			this->list_livem =list_livem;
		}
	};
string user::GetNom(){
	return nom;
}
string user::GetPre(){
	return prenom;
}
long int user::GetId(){
	return id_user;
}
vector<string> user::GetLiv(){
	int i;
	for (i = 0 ; i <list_livem.size ; i++ ){
		cout << list_livem[i];}
}
vector<string> user::GetLiv(){
	int i;
	for (i = 0 ; i <list_livre.size ; i++ ){
		cout << list_livre[i];}
}
void user::info(string nom,long int iban){
	 string a;
	 long int b;
           cout << "nom de liver : " << endl;
           cin >> a;
           cout << "et IBAN : " << endl;
           cin >>  B;
          return(a,b)
}
void user::SetLiv() {
    string i;
    do {
        list_livre.push_back(put());  
        cout << "si exsit other liver emprunte oui ou no ? " << endl;
        i = tolower(i);
    } while (i != "no");
}

void user::GetLivre() {
    string i;
    int f;
    do {
        list_livre.push_back(put());  
        for (f = 0; i < list_livem.size(); f++) {  
            if (i == list_livem[f]) {  
                list_livem.erase(list_livem[f]);
            } else {
                cout << "le livre not exsit ?? <endl;";
            }
        }
        cout << "si exsit other liver emprunte oui ou no ? " << endl;
        i = tolower(i);
    } while (i != "no");
}



class biblio {
	private :
	vector<string>list_live;
	vector<string>list_userins;
	
	public:
	vector<string> GetListD();
	vector<string> GetListU();
	void SetAddU();
	void SetAddL();
	biblio(vector<string>list_live,vector<string>list_userins){
			this->list_live = list_live;
			this->list_userins = list_userins;
		}
};
vector<string> biblio::GetListD() {
  int i;
  for (i = 0; i <= list_live.size(); i++) {
    if (live.size[i] == true) {
      return live.size[i];
    }
  }
}

vector<string> biblio::GetListU() {
  int i;
  for (i = 0; i <= list_userins.size(); i++) {
    return list_userins[i];
  }
}

void biblio::SetAddL() {
  list_live.push_back(livre);
}

void biblio::SetAddU() {
  list_userins.push_back(user);
}

int main() {


    return 0;
}
