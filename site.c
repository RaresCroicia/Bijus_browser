#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

void free_site(site *siteuri, int n){
    for(int i = 0; i < n; i++){
        free(siteuri[i].cod.titlu);
        free(siteuri[i].cod.paragraf);
        free(siteuri[i].cod.codHtml);
    }
    free(siteuri);
}

int getColor(char *culoare){
    if(strcmp(culoare, "white") == 0)
        return white;
    if(strcmp(culoare, "black") == 0)
        return black;
    if(strcmp(culoare, "red") == 0)
        return red;
    if(strcmp(culoare, "green") == 0)
        return green;
    if(strcmp(culoare, "blue") == 0)
        return blue;
    if(strcmp(culoare, "yellow") == 0)
        return yellow;
    return -1;
}

void setareParametri(HTML *var){
    //Extragere titlu
    char *titleStart, *titleStop;
    titleStart = strstr(var->codHtml, "<title>");
    titleStop = strstr(var->codHtml, "</title>");
    int poz1 = titleStart - var->codHtml + 7;
    int poz2 = titleStop - var->codHtml;
    int dim = poz2-poz1+5, k = 0;
    var->titlu = malloc(dim * sizeof(char));
    for(int i = poz1; i < poz2; i++)
        var->titlu[k++] = var->codHtml[i];
    var->titlu[k] = '\0';
    int dimP;
    //Extragere paragraf
    if(strstr(var->codHtml, "<p>") != NULL){
        char *parStart, *parStop;
        parStart = strstr(var->codHtml, "<p>");
        parStop = strstr(var->codHtml, "</p>");
        int pozP1 = parStart - var->codHtml + 3;
        int pozP2 = parStop - var->codHtml;
        dimP = pozP2-pozP1+1;
        var->paragraf = malloc(dimP * sizeof(char));
        k = 0;
        for(int i = pozP1; i < pozP2; i++)
            var->paragraf[k++] = var->codHtml[i];
        var->paragraf[k] = '\0';
        var->textColor = black;
        var->backgroundColor = white;
    }
    else{
        char *parStart, *parStop;
        parStart = strstr(var->codHtml, ";\">");
        parStop = strstr(var->codHtml, "</p>");
        int pozP1 = parStart - var->codHtml + 3;
        int pozP2 = parStop - var->codHtml;
        dimP = pozP2-pozP1+1;
        var->paragraf = malloc(dimP * sizeof(char));
        k = 0;
        for(int i = pozP1; i < pozP2; i++)
            var->paragraf[k++] = var->codHtml[i];
        var->paragraf[k] = '\0';
        
        char *culStart, *culStop, *culStart1, *culStop1;
        char *colorAct;
        
        var -> backgroundColor = 152;

        if(strstr(var->codHtml, "background-color:") != NULL){
            culStart1 = strstr(var->codHtml, "background-color:");
            culStop1 = strstr(culStart1+17, ";");
            int pozC1 = culStart1 - var->codHtml + 17;
            int pozC2 = culStop1 - var->codHtml;
            int dimP = pozC2 - pozC1+1; 
            int cnt = 0;
            colorAct = malloc(dimP * sizeof(char));
            for(int i = pozC1; i < pozC2; i++){
                colorAct[cnt++] = var->codHtml[i]; 
            }
            colorAct[cnt] = '\0';
            var->backgroundColor = getColor(colorAct);
            free(colorAct);
        }
        else{
            var->backgroundColor = white;
        }
        if(strstr(var->codHtml, "color:") != NULL ){
            culStart = strstr(var->codHtml, "color:");
            culStop = strstr(culStart+6, ";");
            int pozC1 = culStart - var->codHtml + 6;
            int pozC2 = culStop - var->codHtml;
            int dimC = pozC2 - pozC1+1; 
            int cnt = 0;
            colorAct = malloc(dimC * sizeof(char));
            for(int i = pozC1; i < pozC2; i++){
                colorAct[cnt++] = var->codHtml[i]; 
            }
            colorAct[cnt] = '\0';
            if(getColor(colorAct) != var->backgroundColor)
                var->textColor = getColor(colorAct);
            else
                var->textColor = black;
            free(colorAct);
        }
        else{
            var->textColor = black;
        }
        
    }
}

char** getCuvinte(char **cuvinte, int *nC){
    char aux[500];
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

        cuvinte[i] = malloc((strlen(p)+1) * sizeof(char));
        p[strlen(p)] = '\0';
        strcpy(cuvinte[i], p);
        i++;
        (*nC) ++;
    }
    return cuvinte;
}

char** getCuvinteLista(char **cuvinte, int *nC, char *lista){
    char aux[500];
    char *ll = aux;
    char *p;
    (*nC) = 0;
    int i = 0, cap = 1;
    strcpy(aux, lista);
    cuvinte = malloc(cap * sizeof(char*));
    while ((p = strtok_r(ll, " ", &ll))){
        
        if(i == cap){
            cap *= 2;
            cuvinte = realloc(cuvinte, cap*sizeof(char*));
        }

        cuvinte[i] = malloc((strlen(p)+1) * sizeof(char));
        p[strlen(p)] = '\0';
        strcpy(cuvinte[i], p);
        i++;
        (*nC) ++;
    }
    return cuvinte;
}

char** getCuvinteAvansLista(char **cuvinte, int *nC, char *lista){
    char aux[500];
    const char space[1] = " ";
    char *ll = aux;
    char *p;
    (*nC) = 0;
    int i = 0, cap = 1;
    int ok = 0;
    strcpy(aux, lista);
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

site citire(char nume_fisier[35]){
    FILE *fisier;
    fisier = fopen(nume_fisier, "r");
    site aux;
    char useless;
    fscanf(fisier, "%s%d%d%d", aux.URL, &aux.sizeOcteti, &aux.numarAccesari, &aux.checksum);
    aux.cod.codHtml = malloc((aux.sizeOcteti+1) * sizeof(char));
    strcpy(aux.nume, nume_fisier);
    fscanf(fisier, "%c", &useless);
    for(int i = 0; i < aux.sizeOcteti; i++){
        char charCitit;
        fscanf(fisier, "%c", &charCitit);
        if(charCitit == 13)
            i--;
        else 
            aux.cod.codHtml[i] = charCitit;
    }
    aux.cod.codHtml[aux.sizeOcteti] = '\0';
    setareParametri(&aux.cod);
    fclose(fisier);
    return aux;
}

site* setareBazaDeDate(site *LS, int *numar_elemente, int *capacitate) {
    FILE *master, *fisier;
    char nume_fisier[35];
    LS = malloc((*capacitate)*sizeof(site));
    master = fopen("master.txt", "r");
    while(fgets(nume_fisier, 35, master) != NULL){
        if((*numar_elemente) == (*capacitate)){
            (*capacitate) += 3;
            LS = realloc(LS, (*capacitate)*sizeof(site));
        }

        if(nume_fisier[strlen(nume_fisier)-1] == '\n') 
            nume_fisier[strlen(nume_fisier)-1] = '\0';

        fisier = fopen(nume_fisier, "r");
        if(fisier){
        fclose(fisier);
        LS[(*numar_elemente)] = citire(nume_fisier);
        (*numar_elemente)++;
        }
    }
    fclose(master);
    return LS;
}


