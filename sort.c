#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "task0.h"

void swap(site *a, site *b){
    site aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void sortare(site *siteAct, int n, int (*cmp)(site text1, site text2)){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++){
            if(cmp(siteAct[i], siteAct[j]) == 1){
                swap(&siteAct[i], &siteAct[j]);
            } 
        }
}

void afisareURL(site *a, int n){
    for(int i = 0; i < n; i++)
    printf("%s\n", a[i].URL);
}