#include <iostream>
#include <vector>
#include <any>
using namespace std;
template <typename T> T moyenne(vector<T>Tab){
    T m = Tab[0];
    for (int i = 1; i < Tab.size(); ++i) {
        m += Tab[i];
        m = static_cast<T>(m);
    }

    return m / ;
}

int main () {
    vector<any>t = {10,20,30,40,11.33,10.22,30.40,5.40};
    cout<<"[Moyenne int]=>"<<moyenne(t)<<endl;

    return 0;
}