#include <iostream>
#include <vector>

using namespace std;
int co=1;
class Billet {
    protected:
        int identifiant;
        double prix;
        string compagnie;
        string destination;
    public:
        Billet(){}
        Billet(double b,string c,string d):identifiant(co),prix(b),compagnie(c),destination(d){co++;}
        virtual void afficher()=0;
        string getDestination(){return destination;}
                virtual ~Billet(){}
  
};

class BilletAvion : public Billet {
    public:
        BilletAvion(){}
        BilletAvion(double b,string c,string d):Billet(b,c,d){identifiant=co;}
        void afficher() override{
            cout << "\nid :" << identifiant
            <<"\nprix: " << prix
            <<"\ncompanie: "<< compagnie
            <<"\ndestination: "<<destination<<endl;}
};
class BilletTrain : public Billet {
    public:
        BilletTrain(){}
        BilletTrain(double b,string c,string d):Billet(b,c,d){identifiant=co;}
        void afficher() override{
            cout << "\nid :" << identifiant
            <<"\nprix: " << prix
            <<"\ncompanie: "<< compagnie
            <<"\ndestination: "<<destination<<endl;
        }
};
class SystemeReservation {
    protected:
        vector <Billet*> billets;
        static const int capacite=5;
        int taille=0;
    public:
        SystemeReservation(){}
        ~SystemeReservation() {
            for (auto& b : billets) {
                delete b;
        }
    }
        void ajouterBillet(Billet* b){
            if (taille < capacite){
            billets.push_back(b);
            taille++;}
            else cout << "la capacite maximale est depassee"<< endl;
        }
        void afficherBillets() {
            for (auto& b : billets) {
                b->afficher();
            }
            }
        void chercherBilletsParDestination(string dest) {
            cout<<"\n\nLe resultat de la recherche: "<< endl;
            for (auto& b : billets) {
                if (b->getDestination()==dest)
                b->afficher();
    }
}

};

int main()
{
    SystemeReservation avion;
    SystemeReservation train;

    Billet* ba1 = new BilletAvion(2000, "RAM", "Paris");
    Billet* ba2 = new BilletAvion(1600, "TRANSAVIA", "Berlin");
    Billet* ba3 = new BilletTrain(1200, "SNCF", "Lyon");
    Billet* ba4 = new BilletTrain(600.2, "Eurostar", "London");
    Billet* ba5 = new BilletAvion(1800, "Air France", "Paris");

    Billet* bt1= new BilletTrain(150,"ONCF","AGADIR");
    Billet* bt2= new BilletTrain(100,"ONCF","MARRAKECH");
    Billet* bt3= new BilletTrain(50,"ONCF","Rabat");

    ba1->afficher();
    bt1->afficher();

    avion.ajouterBillet(ba1);
    avion.ajouterBillet(ba2);
    avion.ajouterBillet(ba3);
    avion.ajouterBillet(ba4);
    avion.ajouterBillet(ba5);

    train.ajouterBillet(bt1);
    train.ajouterBillet(bt2);
    train.ajouterBillet(bt3);

    avion.chercherBilletsParDestination("Paris");
    train.chercherBilletsParDestination("Rabat");

    return 0;
}
