#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task0.h"

void setareParametri(HTML *var){
    //Extragere titlu
    char *titleStart, *titleStop;
    titleStart = strstr(var->codHtml, "<title>");
    titleStop = strstr(var->codHtml, "</title>");
    int poz1 = titleStart - var->codHtml + 7;
    int poz2 = titleStop - var->codHtml;
    int dim = poz2-poz1+1, k = 0;
    var->titlu = malloc(dim * sizeof(char));
    for(int i = poz1; i < poz2; i++)
        var->titlu[k++] = var->codHtml[i];

    //Extragere paragraf
    if(strstr(var->codHtml, "<p>") != NULL){
        char *parStart, *parStop;
        parStart = strstr(var->codHtml, "<p>");
        parStop = strstr(var->codHtml, "</p>");
        int pozP1 = parStart - var->codHtml + 3;
        int pozP2 = parStop - var->codHtml;
        int dimP = pozP2-pozP1+1;
        var->paragraf = realloc(var->paragraf, dimP * sizeof(char));
        k = 0;
        for(int i = pozP1; i < pozP2; i++)
            var->paragraf[k++] = var->codHtml[i];
    }
    else{
        char *parStart, *parStop;
        parStart = strstr(var->codHtml, ";\">");
        parStop = strstr(var->codHtml, "</p>");
        int pozP1 = parStart - var->codHtml + 3;
        int pozP2 = parStop - var->codHtml;
        int dimP = pozP2-pozP1+1;
        var->paragraf = realloc(var->paragraf, dimP * sizeof(char));
        k = 0;
        for(int i = pozP1; i < pozP2; i++)
            var->paragraf[k++] = var->codHtml[i];
    }


}

site citire(char nume_fisier[35]){
    FILE *fisier;
    fisier = fopen(nume_fisier, "r");
    site aux;
    char *codHtml, useless;
    fscanf(fisier, "%s%d%d%d", aux.URL, &aux.sizeOcteti, &aux.numarAccesari, &aux.checksum);
    aux.cod.codHtml = malloc(aux.sizeOcteti * sizeof(char));
    strcpy(aux.nume, nume_fisier);
    fscanf(fisier, "%c%c", &useless, &useless);
    for(int i = 0; i < aux.sizeOcteti; i++){
        char charCitit;
        fscanf(fisier, "%c", &charCitit);
        if(charCitit == 13)
            i--;
        else 
            aux.cod.codHtml[i] = charCitit;
    }
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


