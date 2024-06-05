#include <iostream>


using namespace std;

class CompteBancaire {
private:
    int numeroCompte;
    double solde;

public:
    CompteBancaire(int numeroCompte, double soldeInitial)
        : numeroCompte(numeroCompte), solde(soldeInitial) {}

    void deposer(double montant) {
        if (montant < 0) {
            throw invalid_argument("Le montant � d�poser doit �tre positif.");
        }
        solde += montant;
    }

    void retirer(double montant) {
        if (montant < 0) {
            throw invalid_argument("Le montant � retirer doit �tre positif.");
        }
        if (montant > solde) {
            throw runtime_error("Solde insuffisant pour le retrait demand�.");
        }
        solde -= montant;
    }

    double obtenirSolde() const {
        return solde;
    }
};

int main() {
    CompteBancaire compte(12345, 5000.0);

    try {
        cout << "Tentative de d�p�t d'un montant n�gatif..." << endl;
        compte.deposer(-100.0);
    } catch (const invalid_argument& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    try {
        cout << "Tentative de retrait d'un montant sup�rieur au solde..." << endl;
        compte.retirer(6000.0);
    } catch (const runtime_error& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    try {
        cout << "Tentative de retrait d'un montant n�gatif..." << endl;
        compte.retirer(-50.0);
    } catch (const invalid_argument& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    cout << "Solde actuel : " << compte.obtenirSolde() << endl;

    return 0;
}
