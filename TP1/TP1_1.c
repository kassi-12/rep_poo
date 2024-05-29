#include <stdio.h>
#include <stdlib.h>
int main (){
	int cp = 0;
	int r = 10;
	int i;
	int *tab = malloc(r*sizeof(int));
	for (i=0;i<=r;i++){
		tab[i] = i;
		};
	for (i=0;i<=r;i++){
			cp += tab[i];
		};
	printf('le somme : %d', cp);
	}
