#include <iostream>
using namespace std;

class monom {
private:
    int coef;
    int dogre;

public:
    monom(int coef = 0, int dogre = 0) {
        this->coef = coef;
        this->dogre = dogre;
    }

    void getCoef() {
        cout << "Coefficient: " << coef << endl;
    }

    void getDogre() {
        cout << "Degree: " << dogre << endl;
    }

    friend istream &operator>>(istream &i, monom &m) {
        cout << "Enter the coefficient: ";
        i >> m.coef;
        cout << "Enter the degree: ";
        i >> m.dogre;
        return i;
    }

    friend ostream &operator<<(ostream &out, const monom &m) {
        out << m.coef << "x^" << m.dogre;
        return out;
    }

    monom operator+ (const monom &m) const {
        if (dogre == m.dogre) {
            return monom(coef + m.coef, dogre);
        }
	}
    monom operator* (const monom &m) const {
        return monom(coef * m.coef, dogre + m.dogre);
    }

    bool operator== (const monom &m) const {
        return (coef == m.coef && dogre == m.dogre);
    }

    bool operator< (const monom &m) const {
        return (dogre < m.dogre);
    }

    bool operator! () const {
        return (coef == 0);
    }

    monom operator~ () const {
        return monom(coef * dogre,dogre - 1);
	}

};

int main() {

    monom m1,m2;
    cin >> m1;
    cin >> m2;
    cout << m1<<endl;
    cout <<m2<<endl;
    cout << "la sum : "<<endl;
    cout <<m1.operator +(m2)<<endl;
    cout << "la produit : "<<endl;
    cout <<m1.operator +(m2)<<endl;
    m1==m2;   
    
    cout << ~m1 << ~m2<<endl;
    


    return 0;
}
