#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cstdlib>
using namespace std;

class Produit {
private:
	int idp;
    string nomp;
    string desc;
    double prixu;
    int qt;

public:
    Produit(int ip = 0, string np = "", string dp = "", double pp = 0.0, int qp = 1) {
        idp = ip;
        nomp = np;
        desc = dp;
        prixu = pp;
        qt = qp;
    }
    ~Produit() {
        cout << "Produit avec ID " << idp << " destroyed" << std::endl;
    }
    

    int getIdp();
    string getNomp();
    string getDesc();
    double getPrixu();
    int getQt();

    void setIdp(int i);
    void setNomp(string n);
    void setDesc(string d);
    void setPrixu(double p);
    void setQt(int q);

    void affp();
    void saip();

};

int Produit::getIdp() {
    return idp;
}

string Produit::getNomp() {
    return nomp;
}

string Produit::getDesc() {
    return desc;
}

double Produit::getPrixu() {
    return prixu;
}

int Produit::getQt() {
    return qt;
}

void Produit::setIdp(int i) {
    idp = i;
}

void Produit::setNomp(string n) {
    nomp = n;
}

void Produit::setDesc(string d) {
    desc = d;
}

void Produit::setPrixu(double p) {
    prixu = p;
}

void Produit::setQt(int q) {
    qt = q;
}

void Produit::affp() {
    cout << "Identifiant du produit : " << idp << endl;
    cout << "Nom du produit : " << nomp << endl;
    cout << "Description du produit : " << desc << endl;
    cout << "Prix unitaire du produit : " << prixu << endl;
    cout << "Quantite du produit : " << qt << endl;
}

void Produit::saip() {
    int a, q;
    string n, d;
    double p;
    cout << "Identifiant du produit : " << endl;
    cin >> a;
    setIdp(a);
    cout << "Nom du produit : " << endl;
    cin >> n;
    setNomp(n);
    cout << "Description du produit : " << endl;
    cin.ignore();
	getline(cin, d);
    setDesc(d);
    cout << "Prix unitaire du produit : " << endl;
    cin >> p;
    setPrixu(p);
    cout << "Quantite du produit : " << endl;
    cin >> q;
    setQt(q);
}


class Client {
private:
    int idc;
    string nomc, pren, addr;

public:
    Client(int i = 0, string n = "", string p = "", string ad = "") {
        idc = i;
        nomc = n;
        pren = p;
        addr = ad;
    }
    
    ~Client() {
        
        cout << "Client avec ID " << idc << " destroyed" <<endl;
    }
    int getIdc();
    string getNomc();
    string getPren();
    string getAddr();
    void setIdc(int i);
    void setNomc(string n);
    void setPren(string p);
    void setAddr(string ad);
    void affc();
    void affcf();
    void saic();
};

int Client::getIdc() {
    return idc;
}

string Client::getNomc() {
    return nomc;
}

string Client::getPren() {
    return pren;
}


string Client::getAddr() {
    return addr;
}

void Client::setIdc(int i) {
    idc = i;
}


void Client::setNomc(string n) {
    nomc = n;
}

void Client::setPren(string p) {
    pren = p;
}

void Client::setAddr(string ad) {
    addr = ad;
}





void Client::affc() {
    cout << "Identifiant du client : " << idc << endl;
    cout << "Nom du client : " << nomc << endl;
    cout << "Prenom du client : " << pren << endl;
    cout << "Adresse du client : " << addr << endl;
}










void Client::saic() {
    int a;
    string n, p, ad;
    cout << "Identifiant du client : " << endl;
    cin >> a;
    setIdc(a);
    cout << "Nom du client : " << endl;
    cin.ignore();
	getline(cin, n);
    setNomc(n);
    cout << "Prenom du client : " << endl;
    cin.ignore();
	getline(cin, p);
    setPren(p);
    cout << "Adresse du client : " << endl;
    cin.ignore();
	getline(cin, ad);
    setAddr(ad);
}





class Facture {
private:
    int codef;
    Client cl;
    vector<Produit> tab;
    string datec;
    double mtotal;
    bool etat;


public:
    Facture(int cf = 0, string dc = "", bool e = false, double m = 0.0) {
        codef = cf;
        datec = dc;
        etat = e;
        mtotal = m;
    }
   ~Facture()  { 
    cout << "Facture with ID " << codef << " destroyed" << std::endl;
}
    int getCodef();
    string getDatec();
    bool getEtat();
    double getMtotal();
    void setCodef(int cf);
    void setDatec(string dc);
    void setEtat(bool e);
    void setMtotal(double m);
    void afff();
    void saif();
    void veriff();
    void modp();
    void modc();
    void Total();
    void MinP();
    void Produit_inf(double a);
    void sav();
    void afffc();
    void savcsv();
    string getCurrentDate();
    void suppp();
};







int Facture::getCodef() {
    return codef;
}






string Facture::getDatec() {
    return datec;
}






bool Facture::getEtat() {
    return etat;
}






void Facture::setCodef(int cf) {
    codef = cf;
}





void Facture::setDatec(string dc) {
    datec = dc;
}






void Facture::setEtat(bool e) {
    etat = e;
}








void Facture::afff() {
    cout << "Code de la facture : " << codef << endl;
    cout << "Informations du client : " << endl;
    cl.affc();

    if (tab.empty()) {
        cout << "Aucun produit." << endl;
    } else {
        cout << "Produits dans la facture : " << endl;
        cout << "----------------------------------------------" << endl;
        for (size_t i = 0; i < tab.size(); i++) {
            cout << "Informations du produit " << i + 1 << " : " << endl;
            tab[i].affp();
            cout << "----------------------------------------------" << endl;
        }
    }

    cout << "Date de creation : " << datec << endl;
    if (etat == false) {
        cout << "Etat de la facture : Non payee !!" << endl;
    } else {
        cout << "Etat de la facture : payee." << endl;
    }
}









void Facture::afffc(){
	cout << "les informations du client : " << endl;
    cl.affc();
}








void Facture::saif() {
    string ch, ch1;
    cout << "Entrez le code de la facture : " << endl;
    cin >> codef;
    cout << "Entrez les informations du client : " << endl;
    cl.saic();

    do {
        Produit p;
        p.saip();
        tab.push_back(p);
        cout << "Entrez 'ADD' pour ajouter un produit 'EXIT' pour quitter : " << endl;
        cin >> ch;
        for (char &c : ch) {
        c = tolower(c);
		}
    } while (ch!= "exit");
    if (tab.size() == 0) {
        cout << "Il n'y a pas de produits dans la facture !!" << endl;
    } else {
        int i = tab.size();
        cout << "Il y a " << i << " produits dans la facture." << endl;
    }

    cout << "Entrez la date de la facture (tapez 'NOW' pour la date d'aujourd'hui) : " << endl;
    cin >> datec;
    for (char &c : datec) {
        c = tolower(c);
		}

    if (datec == "now") {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        tm localTime = *localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &localTime);
        datec = buffer;
    }

    cout << "Entrez l'etat de la facture, si payee taper 'oui', sinon taper 'non' : " << endl;
    cin >> ch1;
    if (ch1 == "non") {
        etat = false;
    } else {
        etat = true;
    }
}







void Facture::veriff() {
        int p;
        cout << "entrez l'identifiant du produit : " << endl;
        cin >> p;

        bool pt = false;

        for (size_t i = 0; i < tab.size(); i++) {
            if (tab[i].getIdp() == p) {
                pt = true;
                break;
            }
        }

        if (pt == true) {
            cout << "Le produit existe dans la facture." << endl;
        } else {
            cout << "Le produit n'existe pas dans la facture." << endl;
        }
}






void Facture::modp() {
    string ch, n, na;
    int a;
    Produit seletp;
      if (etat == false){
    do {
        cout << "Entrez la methode de recherche ID or Name 'N' :" << endl;
        cin >> ch;
        for (char &c : ch) {
        c = tolower(c);
		}
    } while (ch != "id" && ch != "n");

    if (ch == "id") {
        do {
            cout << "Entrez l'ID de produit : " << endl;
            cin >> a;
        } while (a < 0);

        for (size_t i = 0; i < tab.size(); i++) {
            if (tab[i].getIdp() == a) {
                seletp = tab[i];
                tab.erase(tab.begin() + i);
                break;
            }
        }
    } else {
        do {
            cout << "Entrez le nom du produit : " << endl;
            cin >> n;
        } while (n.empty());

        for (size_t i = 0; i < tab.size(); i++) {
            if (tab[i].getNomp() == n) {
                seletp = tab[i];
                tab.erase(tab.begin() + i);
                break;
            }
        }
    }

    do {
        cout << "Enter votre choix de modification :" << endl;
        cout << "-----------------------------------" << endl;
        cout << "pour l'ID taper I" << endl;
        cout << "pour le nom taper N" << endl;
        cout << "pour le prix taper P" << endl;
        cout << "pour la quantite taper Q" << endl;
        cout << "-----------------------------------" << endl;
        cin >> na;
        for (char &c : na) {
        c = tolower(c);
		}
    } while (na != "i" && na != "n" && na != "p" && na != "q");

    cout << "Enter les nouvelles informations : " << endl;

    if (na == "i") {
        int i;
        cout << "l'ID courant est :" << seletp.getIdp() << endl;
        cout << "Enter votre nouvelle ID de produit " << endl;
        cin >> i;
        seletp.setIdp(i);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    } else if (na == "n") {
        string newName;
        cout << "Le nom courant est :" << seletp.getNomp() << endl;
        cout << "Enter votre nouveau NOM de produit " << endl;
        cin >> newName;
        seletp.setNomp(newName);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    } else if (na == "p") {
        double newPrice;
        cout << "Le prix unitaire courant est :" << seletp.getPrixu() << endl;
        cout << "Enter votre nouveau PRIX UNITAIRE de produit " << endl;
        cin >> newPrice;
        seletp.setPrixu(newPrice);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    } else if (na == "q") {
        int newQuantity;
        cout << "La quantite courante est :" << seletp.getQt() << endl;
        cout << "Enter votre nouvelle QUANTITe de produit " << endl;
        cin >> newQuantity;
        seletp.setQt(newQuantity);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    }

    tab.push_back(seletp);}
  else cout << "La facture a dejà ete reglee, vous ne pouvez pas apporter de modifications."<< endl;
}






void Facture::modc() {
    string na;

    do {
        cout << "Enter votre choix de modification :" << endl;
        cout << "-----------------------------------" << endl;
        cout << "pour l'ID taper I" << endl;
        cout << "pour le Nom taper N" << endl;
        cout << "pour le Prenom taper P" << endl;
        cout << "pour la Adresse taper A" << endl;
        cout << "-----------------------------------" << endl;
        cin >> na;
        for (char &c : na) {
        c = tolower(c);
		}
    } while (na != "i" && na != "n" && na != "p" && na != "a");

    cout << "Enter les nouvelles informations : " << endl;

    if (na == "i") {
        int i;
        cout << "l'ID courant est :" << cl.getIdc() << endl;
        cout << "Enter votre nouvelle ID de client :" << endl;
        cin >> i;
        cl.setIdc(i);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    } else if (na == "n") {
        string newName;
        cout << "Le nom courant est :" << cl.getNomc() << endl;
        cout << "Enter votre nouveau NOM de client :" << endl;
        cin >> newName;
        cl.setNomc(newName);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    } else if (na == "p") {
        string newPre;
        cout << "Le prix unitaire courant est :" << cl.getPren() << endl;
        cout << "Enter votre nouveau PRENOM de client :" << endl;
        cin >> newPre;
        cl.setPren(newPre);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    } else if (na == "a") {
        string newadd;
        cout << "La quantite courante est :" << cl.getAddr() << endl;
        cout << "Enter votre nouvelle ADDRESS de produit " << endl;
        cin >> newadd;
        cl.setAddr(newadd);
        cout << "Votre modification a ete effectuee avec succès !!" << endl;
    }

}





void Facture::Total(){
	double total = 0;
	for (size_t i = 0; i < tab.size(); i++) {
            int Q = tab[i].getQt();
            double P = tab[i].getPrixu();
            total = total + (Q*P);
		}
	cout<<"le montant Total est : "<<total <<endl;

}
void Facture::Produit_inf(double a) {
    vector<Produit> tEMP;

for (size_t i = 0; i < tab.size(); i++) {

    if (tab[i].getPrixu() < a) {

        tEMP.push_back(tab[i]);
    }
}

if (tEMP.empty()) {
    cout << "Il n'y a pas de produits avec un prix inferieur à " << a << endl;
} else {

    for (size_t i = 0; i < tEMP.size(); i++) {
        cout << "Le produit est : "<< endl;
        tEMP[i].affp();
	}
}
}




string getCurrentDate() {
       auto now = std::chrono::system_clock::now();
      time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now_time), "%Y-%m-%d");
     return ss.str();
}






void Facture::suppp() {
     string ch, n, na;
    int a;
    Produit seletp;

    do {
        cout << "Enter la method de recherche ID or Name 'N' :" << endl;
        cin >> ch;
        for (char &c : ch) {
        c = tolower(c);
		}
    } while (ch != "id" && ch != "n");

    if (ch == "id") {
        do {
            cout << "Entrez l'ID du produit : " << endl;
            cin >> a;
        } while (a < 0);

        for (size_t i = 0; i < tab.size(); i++) {
            if (tab[i].getIdp() == a) {
                seletp = tab[i];
                tab.erase(tab.begin() + i);
                break;
            }
        }
    } else {
        do {
            cout << "Entrez le nom du produit : " << endl;
            cin >> n;
        } while (n.empty());

        for (size_t i = 0; i < tab.size(); i++) {
            if (tab[i].getNomp() == n) {
                seletp = tab[i];
                tab.erase(tab.begin() + i);
                break;
            }
        }
    }
    cout << "suppresion est bien reussie " << endl;

}
void Facture::sav() {
	
    string a;
    cout << "Enter le nom de fichier : " << endl;
    cin >> a;

    ofstream file(a);

    if (file.is_open()) {
        file << "Code de la facture : " << codef << endl;
        file << "-----------------------------------" << endl;
        file << "Informations du client : "<<endl;
        file << "Identifiant du client : " << cl.getIdc() << endl;
        file << "Nom du client : " << cl.getNomc() << endl;
        file << "Prenom du client : " << cl.getPren() << endl;
        file << "Adresse du client : " << cl.getAddr() << endl;
        file << "-----------------------------------" << endl;
        file << "Il y a " << tab.size() << " produits dans la facture." << endl;

        for (size_t i = 0; i < tab.size(); i++) {
            file << "-----------------------------------" << endl;
            file << "produit numero : " << i << endl;
            file << "Identifiant du produit : " << tab[i].getIdp() << endl;
            file << "Nom du produit : " << tab[i].getNomp() << endl;
            file << "Description du produit : " << tab[i].getDesc() << endl;
            file << "Prix unitaire du produit : " << tab[i].getPrixu() << endl;
            file << "Quantite du produit : " << tab[i].getQt() << endl;
            file << "-----------------------------------" << endl;
        }
		file << "date de creation : " << datec << endl;
        double total = 0;
		for (size_t i = 0; i < tab.size(); i++) {
            int Q = tab[i].getQt();
            double P = tab[i].getPrixu();
            total = total + (Q*P);
		}
		file<<"le montant Total est : "<<total <<endl;
        file << "-----------------------------------" << endl;
        if (!etat) {
            file << "Etat de la facture : Non payee !!" << endl;
        } else {
            file << "Etat de la facture : Payee." << endl;
        }

        file.close();
        cout << "Facture sauvegardee avec succes." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

int main() {
    vector<Facture> tabf;
    int choix;

    do {
        cout << "--------------{Gestion des Factures}-----------------" << endl;
        cout << "1 -  Pour Creer une facture(s)." << endl;
        cout << "2 -  Pour Afficher une facture(s)." << endl;
        cout << "3 -  Pour Verifier un produit dans la facture." << endl;
        cout << "4 -  Pour Modifier un produit." << endl;
        cout << "5 -  Pour Modifier un client." << endl;
        cout << "6 -  Pour Afficher un Total." << endl;
        cout << "7 -  Pour Afficher les  produits dont le prix est inferieur a une valeur specifique." << endl;
        cout << "8 -  Pour Sauvegarder la facture." << endl;
        cout << "9 -  Pour modifier l'Etat d'une facture." << endl;
        cout << "10 - Pour Afficher les clients qui n'ont pas payee." << endl;
        cout << "11 - Pour Afficher les factures d'aujourd'hui." << endl;
        cout << "12 - Pour supprimer un produit d'une facture." << endl;
        cout << "13 - Pour supprimer un facture." << endl;
        cout << "0 -  Pour Quitter." << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Choix : ";
        cin >> choix;
        system("cls");

        switch (choix) {
            case 1: {
                int f;
                cout << "Entrez le nombre de factures : " << endl;
                cin >> f;
                if (f <= 0) {
                    cout << "Nombre de factures invalide" << endl;
                } else {
                    int t = tabf.size();
                    int a = f;
                    f = f + t;
                    for (int i = t; i < f; i++) {
                        Facture fact;
                        fact.saif();
                        tabf.push_back(fact);
                    }
                    cout << "Creation de " << a << " factures reussie." << endl;
                    if (tabf.size()>0) {
                        cout << "Nombre total de factures : " << tabf.size() << " (avec les nouvelles factures)." << endl;
                    } else {
                        cout << "Nombre total de factures : " << tabf.size() << endl;
                    }
                }
                break;
            }
            case 2: {
				int ch;
				cout << "Nombre total de factures : " << tabf.size() << endl;
                cout << "-----------------------------------" << endl;
                cout << "1 - Pour une facture specifique" << endl;
                cout << "2 - Pour toutes les factures" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Choix : ";
                cin >> ch;
                switch (ch) {
                    case 1: {
                        int q;
                        cout << "Entrer le code de facture : " << endl;
                        cin >> q;
                        bool found = false;
                        for (size_t i = 0; i < tabf.size(); i++) {
                            if (tabf[i].getCodef() == q) {
                                tabf[i].afff();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "code de facture invalide" << endl;
                        }
                        
                        break;
                    }
                    case 2: {
                        cout << "-----------------------------------" << endl;
                        cout << "Les factures : " << endl;
                        for (size_t i = 0; i < tabf.size(); i++) {
                            tabf[i].afff();
                            cout << "-----------------------------------" << endl;
                        }
                        break;
                        cout << "Nombre total de factures : " << tabf.size() << endl;
                    }
                    default:
                        cout << "Choix invalide" << endl;
                        break;
                }
                break;
            }
            case 3: {
                int q;
                cout << "Entrer le code de facture : " << endl;
                cin >> q;
                bool found = false;
                for (size_t i = 0; i < tabf.size(); i++) {
                    if (tabf[i].getCodef() == q) {
                        tabf[i].veriff();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "code de facture invalide" << endl;
                }
                break;
            }
            case 4: {
                int q;
                cout << "Entrer le code de facture : " << endl;
                cin >> q;
                bool found = false;
                for (size_t i = 0; i < tabf.size(); i++) {
                    if (tabf[i].getCodef() == q) {
                        tabf[i].modp();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "code de facture invalide" << endl;
                }
                break;
            }
            case 5: {
                int q;
                cout << "Entrer le code de facture : " << endl;
                cin >> q;
                bool found = false;
                for (size_t i = 0; i < tabf.size(); i++) {
                    if (tabf[i].getCodef() == q) {
                        tabf[i].modc();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "code de facture invalide" << endl;
                }
                break;
            }
            case 6: {
                int q;
                cout << "Entrer le code de facture : " << endl;
                cin >> q;
                bool found = false;
                for (size_t i = 0; i < tabf.size(); i++) {
                    if (tabf[i].getCodef() == q) {
                        tabf[i].Total();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "code de facture invalide" << endl;
                }
                break;
            }
            case 7: {
                double a;
                cout << "Entrer le prix maximum : " << endl;
                cin >> a;
                if (a >= 0) {
                    int q;
                    cout << "Entrer le code de facture : " << endl;
                    cin >> q;
                    bool found = false;
                    for (size_t i = 0; i < tabf.size(); i++) {
                        if (tabf[i].getCodef() == q) {
                            tabf[i].Produit_inf(a);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "code de facture invalide" << endl;
                    }
                }
                break;
            }
            case 8: {
			int q;
				  cout << "Entrer le code de facture : " << endl;
				  cin >> q;
				  bool found = false;
				  for (size_t i = 0; i < tabf.size(); i++) {
					if (tabf[i].getCodef() == q) {
					  tabf[i].sav();
					  found = true;
					  break;
					}
				  }
				  if (!found) {
					cout << "code de facture invalide" << endl;
				  }
				  break;
				}
						case 9: {
							int q;
							cout << "Entrer le code de facture : " << endl;
							cin >> q;

							bool found = false;
							for (size_t i = 0; i < tabf.size(); i++) {
								if (tabf[i].getCodef() == q) {
									found = true;
									string e;
									int f = tabf[i].getEtat();

									if (f == 0) {
										cout << "Le courant etat est : non payee" << endl;
									} else {
										cout << "Le courant etat est : payee" << endl;
									}

                        do {
                            cout << "Entrer votre nouvelle etat de facture (p pour payee, n pour non payee) :" << endl;
                            cin >> e;
                        } while (e != "p" && e != "n");

                        if (e == "p") {
                            tabf[i].setEtat(true);
                        } else {
                            tabf[i].setEtat(false);
                        }

                        cout << "Votre modification est bien reussie !!" << endl;
                        break;
                    }
                }

                if (!found) {
                    cout << "Code de facture invalide" << endl;
                }
                break;
            }


            case 10: {
                int cp = 0;

                for (size_t i = 0; i < tabf.size(); i++) {
                    if (tabf[i].getEtat() == false) {
                        cout << "les client(s) n'ont pas payee leurs factures" << endl;
                        tabf[i].afffc();
                        cp++;
                    }
                }

                cout << "le nombre total des factures est : " << cp << endl;
                break;
            }
            case 11: {
					cout << "Factures d'aujourd'hui :" << endl;
					for (size_t i = 0; i < tabf.size(); i++) {
						if (tabf[i].getDatec() == getCurrentDate()) {
							tabf[i].afff();
							cout << "-----------------------------------" << endl;
						}
					}
					break;
				}
				case 12: {
						int q;
						cout << "Entrer le code de facture : " << endl;
						cin >> q;
						bool found = false;
						for (size_t i = 0; i < tabf.size(); i++) {
							if (tabf[i].getCodef() == q) {
								tabf[i].suppp();
								found = true;
								break;  
							}
						}
						if (!found) {
							cout << "Code de facture invalide" << endl;
						}
						
						break;
					} 

			  case 13: {
						int q;
						cout << "Entrer le code de la facture : " << endl;
						cin >> q;
						bool found = false;

						for (size_t i = 0; i < tabf.size(); i++) {
							if (tabf[i].getCodef() == q) {
								tabf.erase(tabf.begin() + i);
								found = true;
								cout << "Facture avec le code " << q << " supprimee avec succès." << endl;
								break;
							}
						}

						if (!found) {
							cout << "Code de facture invalide." << endl;
						}
						break;
					}
            case 0: {
                cout << "Au revoir!" << endl;
                break;
            }
            default: {
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 10." << endl;
                break;
            }
        }
    } while (choix != 0);

    return 0;
}
