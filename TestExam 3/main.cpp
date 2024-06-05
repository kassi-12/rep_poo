#include <iostream>

using namespace std; 

class CompteBancaire {
private:
    int numc;
    double sold;
public:
    CompteBancaire(int n, double s) : numc(n), sold(s) {}

    void deposer(double montant) {
        if (montant < 0) {
            throw invalid_argument("Montant negatif, impossible de deposer.");
        }
        sold += montant;
        cout << "Dépôt effectué." << endl;
    }

    void retrait(double montant) {
        if (montant < 0) {
            throw invalid_argument("Montant negatif, impossible de retirer.");
        }
        if (montant > sold) {
            throw runtime_error("Le montant à retirer dépasse le solde.");
        }
        sold -= montant;
        cout << "Retrait effectué." << endl;
    }

    double obtenirSold() const {
        return sold;
    }
};

int main() {
    CompteBancaire C1(1, 2000);

    try {
        C1.deposer(-1000);
        cout << "done" << endl;
    } catch (const exception &e) {
        cout << "[Erreur]=> " << e.what() << endl;
    }

    try {
        C1.retrait(3000);
        cout << "done" << endl;
    } catch (const exception &e) {
        cout << "[Erreur]=> " << e.what() << endl;
    }

    try {
        C1.retrait(-1000);
        cout << "done" << endl;
    } catch (const exception &e) {
        cout << "[Erreur]=> " << e.what() << endl;
    }

    cout << "[solde]=> " << C1.obtenirSold() << endl;

    return 0;
}
