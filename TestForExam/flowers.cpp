#include <iostream>
#include <string>
using namespace std;
class flowers{
	private :
	string espese;
	float prix;
	bool p;
	public :
	flowers(string a="",float b=1,bool c = true){
		 espese = a;
		 prix = b;
		 p = c;
		}
	void affichierf(){
		cout<<"[espese]=>"<<espese<<endl;
		cout<<"[prix]=>"<<prix<<endl;
		cout<<"[parfeum]"<<boolalpha<<p<<endl;
		}
	friend istream &operator>> (istream &i,flowers &f){
		cout<<"[espese]=>";
		i>>f.espese;
		cout<<"[prix]=>";
		i>>f.prix;
		cout<<"[parfeum]=>";
		i>>f.p;;
		return i;
		}
	friend ostream &operator << (ostream &o,const flowers &f){
		o<<"[espese]=>"<<f.espese<<endl;
		o<<"[prix]=>"<<f.prix<<endl;
		o<<"[parfeum]=>"<<boolalpha<<f.p<<endl;
		return o;
		}
	bool operator== (flowers &f){
		return ( espese == f.espese && prix == f.prix && p ==f.prix);
		}
	bool getP(){
		return p;
		}
	};
