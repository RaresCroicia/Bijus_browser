#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task0.h"

char** getCuvinte(char **cuvinte, int *nC){
    char aux[500];
    const char space[1] = " ";
    char *ll = aux;
    char *p;
    (*nC) = 0;
    int i = 0, cap = 1;
    scanf("%[^\n]s", aux);
    cuvinte = malloc(cap * sizeof(char*));
    while ((p = strtok_r(ll, " ", &ll))){
        
        if(i == cap){
            cap *= 2;
            cuvinte = realloc(cuvinte, cap*sizeof(char*));
        }

        cuvinte[i] = malloc(strlen(p) * sizeof(char));
        strcpy(cuvinte[i], p);
        i++;
        (*nC) ++;
    }
    return cuvinte;
}



site* filtrare(site *st, site *stf, char **cuv, int nS, int nC, int *nS_F){
    (*nS_F) = 0;
    int k = 0, cap_stf = 1;
    stf = malloc(cap_stf * sizeof(site));
    for(int i = 0; i < nS; i++){
        int ok = 0;
        for(int j = 0; j < nC; j++){
            if(strstr(st[i].cod.paragraf, cuv[j]) != NULL){
                ok = 1;
                break;
            }
        }
        if(ok == 1){
            if(k == cap_stf){
                cap_stf*=2;
                stf = realloc(stf, cap_stf * sizeof(site));
            }
            stf[k++] = st[i];
            (*nS_F) ++;
        }
    }
    return stf;
}

int cmp_2(site a, site b){
    if(strcmp(a.cod.paragraf, b.cod.paragraf) == 0)
        return a.numarAccesari < b.numarAccesari ? 1 : -1;
    return (strcmp(a.cod.paragraf, b.cod.paragraf) > 0) ? 1 : -1;
}