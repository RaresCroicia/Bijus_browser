#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "help_task1.h"

int main(void){
    site *listaSiteuri;
    int numar_elemente = 0, capacitate = 3;
    listaSiteuri = setareBazaDeDate(listaSiteuri, &numar_elemente, &capacitate);
        showThings(listaSiteuri, numar_elemente);
    free_site(listaSiteuri, numar_elemente);
}
