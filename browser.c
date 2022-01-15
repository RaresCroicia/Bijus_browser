#include <stdio.h>
#include <stdlib.h>
#include "site.h"
#include "help_task1.h"
#include "help_task2.h"
#include "help_task3.h"
#include "help_task4.h"
#include "sort.h"
#include <string.h>
#include <ncurses.h>

void reset(){
    clear();
    mvaddstr(10, 30, "Browserul lui Biju!");
    refresh(); /* Actulaizeaza-l pe ecranul real */
}

int main(){
    site *listaSiteuri, *siteuriCautate;
    int numar_siteuri = 0, capacitate = 3, numar_cautate, numar_cuvinte;
    char ch;
    char *cautare;
    char **listaCuvinte;
    listaSiteuri = setareBazaDeDate(listaSiteuri, &numar_siteuri, &capacitate);
    
    
    initscr(); /* Incepe modul curses */
    mvaddstr(10, 30, "Browserul lui Biju!");
    refresh(); /* Actulaizeaza-l pe ecranul real */
    ch = getch();
    while(ch != 'q'){
        if(ch == 'c'){
            clear();
            getstr(cautare);
            ch = getch();
            if(ch == 'q'){
                endwin(); 
            }
            if(ch == 's'){
                getCuvinte(listaCuvinte, &numar_cuvinte);
                siteuriCautate = filtrare(listaSiteuri, siteuriCautate, listaCuvinte, numar_siteuri, numar_cuvinte, &numar_cautate);
                clear();
                for(int i = 0; i < numar_cautate; i++){
                    printw("%s %s\n", siteuriCautate[i].URL, siteuriCautate[i].cod.titlu);
                }
                refresh();
                ch = getch();
            }
        }
        //NU MERGE


        ch = getch();
    }
    endwin(); /* Sfarsitul modului curses */
    return 0;
}