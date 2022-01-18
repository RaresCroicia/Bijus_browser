#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "help_task4.h"

int main(void){
    site *listaSiteuri, *listaFiltrate;
    char **cuvinte;
    int numar_elemente = 0, capacitate = 3;
    int numar_cuvinte_negate, numar_filtrate, numar_cuvinte;
    listaSiteuri = setareBazaDeDate(listaSiteuri, &numar_elemente, &capacitate);
        char **siteuriDeVerificat;
        int nrSiteuriDeVerificat;
        siteuriDeVerificat = readCuvinte(siteuriDeVerificat, &nrSiteuriDeVerificat);
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
    for(int i = 0; i < nrSiteuriDeVerificat; i++)
        free(siteuriDeVerificat[i]);
    free(siteuriDeVerificat);
    free_site(listaSiteuri, numar_elemente);
}