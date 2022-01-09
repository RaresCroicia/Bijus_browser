#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task0.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "sort.h"

int main(void){
    site *listaSiteuri, *listaFiltrate;
    char **cuvinte, **cuvinte_negate;
    int numar_elemente = 0, capacitate = 3;
    int numar_cuvinte_negate, numar_filtrate, numar_cuvinte;
    int task = 1;
    listaSiteuri = setareBazaDeDate(listaSiteuri, &numar_elemente, &capacitate);
    if(task == 1){
        showThings(listaSiteuri, numar_elemente);
    }
    else if(task == 2){
        cuvinte = getCuvinte(cuvinte, &numar_cuvinte);
        listaFiltrate = filtrare(listaSiteuri, listaFiltrate, cuvinte, numar_elemente, numar_cuvinte, &numar_filtrate);
        sortare(listaFiltrate, numar_filtrate, cmp_2);
        afisareURL(listaFiltrate, numar_filtrate);
        free(cuvinte);
        free(listaFiltrate);
    }
    else if(task == 3){
        cuvinte = getCuvinteAvans(cuvinte, &numar_cuvinte);
        listaFiltrate = filtrareAvans(listaSiteuri, listaFiltrate, cuvinte, numar_elemente, numar_cuvinte, &numar_filtrate);
        sortare(listaFiltrate, numar_filtrate, cmp_3);
        afisareURL(listaFiltrate, numar_filtrate);
        free(cuvinte);
        free(listaFiltrate);
    }
    else if(task == 4){
        char **siteuriDeVerificat;
        int nrSiteuriDeVerificat;
        siteuriDeVerificat = getCuvinte(siteuriDeVerificat, &nrSiteuriDeVerificat);
        for(int i = 0; i < nrSiteuriDeVerificat; i++){
            int nrSite = checkIndice(listaSiteuri, numar_elemente, siteuriDeVerificat[i]);
            if(nrSite == -1){
                printf("Website not found!\n");
                continue;
            }
            int checksumCalc = checksum(listaSiteuri[nrSite]);
            if(checksumCalc == listaSiteuri[nrSite].checksum){
                printf("Website safe!\n");
            }
            else{
                printf("Malicious website! Official key: %d. Found key: %d\n", listaSiteuri[nrSite].checksum, checksumCalc);
            }
        }
    }
    else if(task == 5){
        //printf("%d\n", strlen(listaSiteuri[0].cod.codHtml));
        printf("%s", listaSiteuri[0].cod.codHtml);
    }
    free(listaSiteuri);
}