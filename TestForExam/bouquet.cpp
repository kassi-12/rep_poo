#include <iostream>
#include <vector>
#include "flowers.cpp"
using namespace std;
class bouquet{
	private :
	vector<flowers *>tabf;
	public :
	bouquet(){}
	~bouquet(){}
	void affchierb(){
		for(size_t i = 0; i < tabf.size();i++){
			cout<< *tabf[i];
			}
		}
	bool test_par(){
		for(size_t i = 0; i < tabf.size();i++){
			if(tabf[i]->getP()==true){
				return true;
			}
		}
		return false;
		}
	void operator+(flowers &f){

	tabf.push_back(&f);
	}

	};
