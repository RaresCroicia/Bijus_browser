#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

site* filtrare(site *st, site *stf, char **cuv, int nS, int nC, int *nS_F){
    (*nS_F) = 0;
    int k = 0, cap_stf = 1, cap_cuv = 1, ok;
    stf = malloc(cap_stf * sizeof(site));
    for(int i = 0; i < nS; i++){
        char *cp_par;
        cp_par = malloc((strlen(st[i].cod.paragraf)+1) * sizeof(char));
        st[i].cod.paragraf[strlen(st[i].cod.paragraf)] = '\0';
        strcpy(cp_par, st[i].cod.paragraf);
        for(int i = 0; i < strlen(cp_par); i++)
            cp_par[i] = (cp_par[i] == '\n') ? ' ' : cp_par[i];
        
        char **cuv_sep, *p;
        int cuv_sep_cap = 1, nr_cuv = 0;
        cuv_sep = malloc(cuv_sep_cap * sizeof(char*));
        p = strtok(cp_par, " ");
        while(p != NULL){
            if(nr_cuv == cuv_sep_cap){
                cuv_sep_cap *= 2;
                cuv_sep = realloc(cuv_sep, cuv_sep_cap * sizeof(char*));
            }
            cuv_sep[nr_cuv] = malloc((strlen(p)+1) * sizeof(char));
            p[strlen(p)] = '\0';
            strcpy(cuv_sep[nr_cuv++], p);
            p = strtok(NULL, " ");
        }
        ok = 0;
        for(int i = 0; i < nr_cuv; i++)
            for(int j = 0; j < nC; j++){
                if(strcmp(cuv_sep[i], cuv[j]) == 0){
                    ok = 1;
                    i = nr_cuv;
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
        for(int i = 0; i < nr_cuv; i++)
            free(cuv_sep[i]);
        free(cuv_sep);
        free(cp_par);
    }
    return stf;
}

int cmp_2(site a, site b){
    if(strcmp(a.cod.paragraf, b.cod.paragraf) == 0)
        return a.numarAccesari < b.numarAccesari ? 1 : -1;
    return (strcmp(a.cod.paragraf, b.cod.paragraf) > 0) ? 1 : -1;
}