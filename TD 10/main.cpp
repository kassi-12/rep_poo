#include <iostream>
using namespace std;

template <typename T>
class Vector {
    private:
        T *tab;
        int taille;
    public:
        Vector(int t=0) : taille(t) {
            if (t > 0)
                tab = new T[t];
            else
                tab = nullptr;
        }

        T &operator[](int i) {
            if (i >= 0 && i < taille) {
                return tab[i];
            }
            throw out_of_range("Index out of range");
        }

        void push_back(T e) {
            T* new_tab = new T[taille + 1];
            for (int i = 0; i < taille; i++) {
                new_tab[i] = tab[i];
            }
            new_tab[taille] = e;
            delete[] tab;
            tab = new_tab;
            taille++;
        }

        void pop_back() {
            if (taille > 0) {
                T* new_tab = new T[taille - 1];
                for (int i = 0; i < taille - 1; i++) {
                    new_tab[i] = tab[i];
                }
                delete[] tab;
                tab = new_tab;
                taille--;
            }
        }

        void resize(int size) {
            T* new_tab = new T[size];
            for (int i = 0; i < (size < taille ? size : taille); i++) {
                new_tab[i] = tab[i];
            }
            delete[] tab;
            tab = new_tab;
            taille = size;
        }

        void print() {
            for (int i = 0; i < taille; i++) {
                cout << tab[i] << endl;
            }
        }

        Vector &operator=(const Vector &newtab) {
            if (this != &newtab) {
                delete[] tab;
                taille = newtab.taille;
                tab = new T[taille];
                for (int i = 0; i < taille; i++) {
                    tab[i] = newtab.tab[i];
                }
            }
            return *this;
        }

        ~Vector() {
            delete[] tab;
        }
};

int main() {
    Vector<int> v(5);
    for (int i = 0; i < 5; ++i) {
        v[i] = i * 10;
    }

    cout << "Initial vector:" << endl;
    v.print();

    cout << "After push_back(50):" << endl;
    v.push_back(50);
    v.print();

    cout << "After pop_back():" << endl;
    v.pop_back();
    v.print();

    cout << "After resize(3):" << endl;
    v.resize(3);
    v.print();

    cout << "After resize(6):" << endl;
    v.resize(6);
    v.print();

    return 0;
}
