#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "help_task3.h"
#include "sort.h"

int main(void){
    site *listaSiteuri, *listaFiltrate;
    char **cuvinte;
    int numar_elemente = 0, capacitate = 3;
    int numar_cuvinte_negate, numar_filtrate, numar_cuvinte;
    int task = 3;
    listaSiteuri = setareBazaDeDate(listaSiteuri, &numar_elemente, &capacitate);
    cuvinte = getCuvinteAvans(cuvinte, &numar_cuvinte);
    listaFiltrate = filtrareAvans(listaSiteuri, listaFiltrate, cuvinte, numar_elemente, numar_cuvinte, &numar_filtrate);
    sortare(listaFiltrate, numar_filtrate, cmp_3);
    afisareURL(listaFiltrate, numar_filtrate);
    for(int i = 0; i < numar_cuvinte; i++)
        free(cuvinte[i]);
    free(cuvinte);
    free_site(listaSiteuri, numar_elemente);
    free(listaFiltrate);
}
