#include <stdio.h>
#include <stdlib.h>
#include "site.h"

void showThings(site *site_afisat, int numar_elemente){
    for(int i = 0; i < numar_elemente; i++)
    printf("%s %d %s\n", site_afisat[i].URL, site_afisat[i].numarAccesari, site_afisat[i].cod.titlu);
}