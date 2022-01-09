#ifndef __task0_h__
#define __task0_h__


enum culori {white, black, red, green, blue, yellow};

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
    
#endif