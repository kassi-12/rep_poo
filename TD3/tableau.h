
void saiserpro(){
	int i;
	float prix; 
	int taille;

	cout << "entrer le nom de produit : "<<"endl";
	cin << namepro;
	cout << "la taille tableu : "<<"endl";
	cin << taille;
	for (i=0;i<=taille;i++){
		cout << "entrer le prix : "<<"endl";
		cin << prixpro;
		prixpro.push_back(prix);
	}
}
void affpro(){
	int i;
	int taille_1 = sizeof(prixpro);
	cout << "nom produit : " << namepro <<"endl";
	cout << "les prix de produit : " << prixpro <<"endl";
	for (i=0;i<=taille_1;i){
		cout <<"le prix numero : "<<i<<" : "<< prixpro[i];
		
	}
}
void moy(){
	float cp = 0;
	float mo;
	int i;
	int taille_2 = sizeof(prixpro);
	for (i=0;i<=taille_2;i++){
		cp = cp + prixpro[i];
		
	}
	mo = cp/taille_2 
	cout << "la somme des prix :"<< mo<<"endl";
}
