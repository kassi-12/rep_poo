#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Client {
protected:
    string nom;
    int cin;
    float mo_total;

public:
    Client(string n, int c, float m) : nom(n), cin(c), mo_total(m) {}
    virtual float getMontant() const = 0;
};

class ClientComptant : public Client {
private:
    int num_ch;
    int code_bank;

public:
    ClientComptant(string n, int c, float m, int num, int code) : Client(n, c, m), num_ch(num), code_bank(code) {}
    float getMontant() const override {
        return mo_total;
    }
};

class ClientCredit : public Client {
private:
    float mo_mensul;
    float der_mo;
    int nbr_mensul;

public:
    ClientCredit(string n, int c, float m, float mm, float dm, int nm)
        : Client(n, c, m), mo_mensul(mm), der_mo(dm), nbr_mensul(nm) {}
    float getMontant() const override {
        if (nbr_mensul == 0) {
            return der_mo;
        } else {
            return mo_mensul;
        }
    }
};

class Societe {
private:
    string nom;
    vector<Client *> listCl;

public:
    Societe(string no) : nom(no) {}
    void operator+=(Client &cl) {
        listCl.push_back(&cl);
    }
      void operator[](ClientComptant &c) {
        for (auto cl : listCl) {
            if (cl->num_ch == c.num_ch) {
                cout << "[nom]=> " << cl->nom << endl;
            }
        }
    }
    float calculateTotalAmount() const {
        float totalAmount = 0.0;
        for (Client *cl : listCl) {
            totalAmount += cl->getMontant();
        }
        return totalAmount;
    }
};

int main() {
    ClientComptant cl1("J", 12345, 1000.0, 9876, 123);
    ClientCredit cl2("A", 54321, 2000.0, 500.0, 100.0, 12);

    Societe societe("MyCo");
    societe += cl1;
    societe += cl2;

    cout << "[totla]" << societe.calculateTotalAmount() << endl;

    ClientComptant searchClient("John", 12345, 0.0, 9876, 123);
    societe[searchClient];

    return 0;
}
