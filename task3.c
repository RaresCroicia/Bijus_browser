#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task0.h"

char** getCuvinteAvans(char **cuvinte, int *nC){
    char aux[500];
    const char space[1] = " ";
    char *ll = aux;
    char *p;
    (*nC) = 0;
    int i = 0, cap = 1;
    int ok = 0;
    scanf("%[^\n]s", aux);
   
    cuvinte = malloc(cap * sizeof(char*));
    while ((p = strtok_r(ll, " ", &ll))){
        
        if(i == cap){
            cap *= 2;
            cuvinte = realloc(cuvinte, cap*sizeof(char*));
        }

        //cazul I - are " la inceput
        if(p[0] == '"'){
            ok = 1;
            cuvinte[i] = malloc(strlen(p) * sizeof(char));
            strcpy(cuvinte[i], p+1);
        }
        else{
            if(ok == 0){
                cuvinte[i] = malloc(strlen(p) * sizeof(char));
                strcpy(cuvinte[i], p);
                i++;
                (*nC) ++;
            }
            else{
                cuvinte[i] = realloc(cuvinte[i], (strlen(cuvinte[i]) + strlen(p) + 1) * sizeof(char));
                strcat(cuvinte[i], " ");
                strcat(cuvinte[i], p);
                if(p[strlen(p)-1] == '"'){
                    ok = 0;
                    cuvinte[i][strlen(cuvinte[i])-1] = '\0';
                    i++;
                    (*nC) ++;
                }
            }
        }
    }
    return cuvinte;
}

site* filtrareAvans(site *st, site *stf, char **cuv, int nS, int nC, int *nS_F){
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
        for(int j = 0; j < nC; j++){
            if(cuv[j][0] == '-')
            if(strstr(st[i].cod.paragraf, cuv[j]+1) != NULL){
                ok = 0;
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

int cmp_3(site a, site b){
    return (a.numarAccesari < b.numarAccesari) ? 1 : -1;
}