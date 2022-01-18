#ifndef __task0_h__
#define __task0_h__

enum culori {white = 7, black = 0, red = 1, green = 2, blue = 4, yellow = 3};

typedef struct{
    char *titlu;
    int textColor, backgroundColor;
    char *paragraf;
    char *codHtml;
}HTML;

typedef struct{
    char URL[55], nume[35];
    int sizeOcteti, numarAccesari, checksum;
    HTML cod;
} site;

site citire(char nume_fisier[35]);
site* setareBazaDeDate(site *LS, int *numar_elemente, int *capacitate);
void setareParametri(HTML *var);
void free_site(site *siteuri, int n);    
char** getCuvinte(char **cuvinte, int *nC);
char** getCuvinteLista(char **cuvinte, int *nC, char *lista);
char** getCuvinteAvansLista(char **cuvinte, int *nC, char *lista);
#endif