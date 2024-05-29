#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int r = 10;
int *tab;

void remp() {
    int i;
    tab = malloc(r * sizeof(int));
    for (i = 0; i < r; i++) {
        tab[i] = i;
    }
}

void aff() {
    int i;
    int cp = 0;
    for (i = 0; i < r; i++) {
        cp += tab[i];
    }
    printf("la somme :", cp);
}

void ins() {
    int a = 10;
    tab[r] = a;
}

int main() {

}

