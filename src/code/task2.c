#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/site.h"
#include "../Headers/help_task2.h"
#include "../Headers/sort.h"
#include "../Headers/task2.h"


int main(void){
    site *listaSiteuri, *listaFiltrate;
    char **cuvinte;
    int numar_elemente = 0, capacitate = 3;
    int numar_filtrate, numar_cuvinte;
    listaSiteuri = setareBazaDeDate(listaSiteuri, &numar_elemente, &capacitate);
    cuvinte = getCuvinte(cuvinte, &numar_cuvinte);
    listaFiltrate = filtrare(listaSiteuri, listaFiltrate, cuvinte, numar_elemente, numar_cuvinte, &numar_filtrate);
    sortare(listaFiltrate, numar_filtrate, cmp_2);
    afisareURL(listaFiltrate, numar_filtrate);
    for(int i = 0; i < numar_cuvinte; i++)
        free(cuvinte[i]);
    free(cuvinte);
    free_site(listaSiteuri, numar_elemente);
    free(listaFiltrate);
}
