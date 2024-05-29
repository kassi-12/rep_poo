#include <iostream>
#define p  3.14

using namespace std;
class Shape {
protected :
    string _name;
bool _draw;
public:
    Shape(string name,bool draw):_name(name),_draw(draw){}
    void affiche(){
        cout<<"[nom Shape]=>"<<_name<<endl;
        cout<<"[Draw]=>"<<boolalpha<<_draw<<endl;
    }
    virtual void Draw(){
        if(_draw == true){
            cout<<"[Draw]=> complite"<<endl;
        }else{
            cout<<"[Draw]=>incomplite "<<endl;
        }
    }
};
class Circle : public Shape{
private :
    float  _r;
public :
    Circle(string name,bool draw,float r): Shape(name,draw),_r(r){}
    void affiche() {
        cout<<"[nom Circle]=>"<<_name<<endl;

    }
    float clac_aire(){
        float aire=(2 * p) * _r;
        return  aire;
    }
    float clac_pre(){
        float pre=p * _r * _r;
        return  pre;

    }
    virtual void Draw() override{
        if(_draw == true){
            cout<<"[Draw Circle]=> complite"<<endl;
        }else{
            cout<<"[Draw Circle]=>incomplite "<<endl;
        }
    }


};
class Rectangle : public Shape{
private :
    float  _L;
    float  _l;
public :
    Rectangle(string name,bool draw,float L,float l): Shape(name,draw),_L(L),_l(l){}
    void affiche() {
        cout<<"[nom Rectangle]=>"<<_name<<endl;
        cout<<"[longueur]=>"<<_L<<endl;
        cout<<"[largeur]=>"<<_l<<endl;
    }
    float clac_aire(){
        float aire=_L*_l;
        return  aire;
    }
    float clac_pre(){
        float pre=(_l+_L) * 2;
        return  pre;

    }
    virtual void Draw() override{
        if(_draw == true){
            cout<<"[Draw Rectangle]=> complite"<<endl;
        }else{
            cout<<"[Draw Rectangle]=>incomplite "<<endl;
        }
    }


};
int main() {
    cout<<"-----------[Circle]-------"<<endl;
    Circle c1("C1", true,10);
    c1.affiche();
    c1.Draw();
    cout<<"[aire]=>"<<c1.clac_aire()<<endl;
    cout<<"[perimetre]=>"<<c1.clac_pre()<<endl;
    cout<<"-----------[Rectangle]-------"<<endl;
    Rectangle R1("R1", false,10,5);
    R1.affiche();
    R1.Draw();
    cout<<"[aire]=>"<<R1.clac_aire()<<endl;
    cout<<"[perimetre]=>"<<R1.clac_pre()<<endl;
    return 0;
}
