#include <iostream>
#include "bouquet.cpp"

int main(){
	bouquet b1;
	flowers f1("rouge",12.1,true);
	flowers f2;
	cin>>f2;
	b1 + f1;
	b1 + f2;
	b1.affchierb();
	cout<<"[test p]=>"<<boolalpha<<b1.test_par()<<endl;
	cout<<"[test ==]=>"<<boolalpha<<(f1 ==f2 )<<endl;
	return 0;
	
	
}
