#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

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
            cuvinte[i] = malloc((strlen(p)+1) * sizeof(char));
            p[strlen(p)] = '\0';
            strcpy(cuvinte[i], p);
        }
        else{
            if(ok == 0){
                cuvinte[i] = malloc((strlen(p)+1) * sizeof(char));
                p[strlen(p)] = '\0';
                strcpy(cuvinte[i], p);
                i++;
                (*nC) ++;
            }
            else{
                p[strlen(p)] = '\0';
                cuvinte[i] = realloc(cuvinte[i], (strlen(cuvinte[i]) + strlen(p) + 2) * sizeof(char));
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
        char *cp_para;
        cp_para = malloc((strlen(st[i].cod.paragraf)+1) * sizeof(char));
        st[i].cod.paragraf[strlen(st[i].cod.paragraf)] = '\0';
        strcpy(cp_para, st[i].cod.paragraf);

        for(int i = 0; i < strlen(cp_para); i++)
            if(cp_para[i] == '\n')
                cp_para[i] = ' ';

        char **cuv_sep, *p;
        int cuv_sep_cap = 1, nr_cuv = 0;
        cuv_sep = malloc(cuv_sep_cap * sizeof(char*));
        p = strtok(cp_para, " ");
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

        int ok = 0;

        for(int j = 0; j < nC; j++){
            if(cuv[j][0] == '"')
                if(strstr(st[i].cod.paragraf, cuv[j]+1) != NULL){
                    ok = 1;
                    break;
                }   
        }

        for(int z = 0; z < nr_cuv; z++)
            for(int j = 0; j < nC; j++){
                if(strcmp(cuv[j], cuv_sep[z]) == 0){
                    ok = 1;
                    z = nr_cuv;
                    break;
                }
            }

        for(int z = 0; z < nr_cuv; z++)
            for(int j = 0; j < nC; j++){
                if(cuv[j][0] == '-')
                    if(strcmp(cuv[j]+1, cuv_sep[z]) == 0){
                        ok = 0;
                        z = nr_cuv;
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
        for(int j = 0; j < nr_cuv; j++)
            free(cuv_sep[j]);
        free(cuv_sep);
        free(cp_para);
    }
    return stf;
}

int cmp_3(site a, site b){
    return (a.numarAccesari < b.numarAccesari) ? 1 : -1;
}