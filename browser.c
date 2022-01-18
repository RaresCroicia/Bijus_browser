#include <stdio.h>
#include <stdlib.h>
#include "site.h"
#include "help_task2.h"
#include "help_task3.h"
#include "sort.h"
#include <string.h>
#include <ncurses.h>

#define HEIGHTC 3
#define WIDTHC 130
#define HEIGHTR 30
#define WIDTHR 130
#define PAGINASTART 1
#define CAUTARE 2
#define REZULTATE 3
#define WEB 4
#define K_U 3
#define K_D 2


site *listaSiteuri, *listaFiltrate;
int numar_siteuri = 0, capacitate = 3, numar_cuvinte = 0, numar_filtrate = 0, selected = 0;
char **cuvinte;
char lista[500];

void web(int a);
void rezultate();
void cautare();
void browser();

void printLegenda(int caz){
    switch(caz){
        case PAGINASTART:{
            WINDOW *wdr = newwin(4, 47, 20, 0);
            refresh();
            box(wdr, 0, 0);
            mvwprintw(wdr, 1, 1, "-Apasati butonul C pentru cautare\n -Apasati butonul Q pentru a inchide browserul\n");
            box(wdr, 0, 0);
            wrefresh(wdr);
            break;
        }
        case CAUTARE:{
            WINDOW *wdr = newwin(7, 60, 20, 0);
            refresh();
            box(wdr, 0, 0);
            mvwprintw(wdr, 1, 1, "-Introduceti textul in bara de cautare, apoi apasati enter\n -Pentru filtrare simpla, apasati butonul S\n -Pentru filtrare avansata, apasati butonul A\n -Pentru a va intoarce cu un pas, apasati butonul B\n -Pentru a inchide browserul apasati butonul Q\n");
            box(wdr, 0, 0);
            wrefresh(wdr);
            break;
        }
        case REZULTATE:{
            WINDOW *wdr = newwin(5, 100, 50, 0);
            refresh();
            box(wdr, 0, 0);
            mvwprintw(wdr, 1, 1, "-Selectati site-ul folosind sagetile sus si jos, iar apoi apasati enter pentru a accesa site-ul\n -Pentru a va duce inapoi apasati butonul B\n -Pentru a inchide browserul apasati butonul Q\n");
            box(wdr, 0, 0);
            wrefresh(wdr);
            break;
        }
        case WEB:{
            WINDOW *wdr = newwin(4, 68, 50, 0);
            refresh();
            box(wdr, 0, 0);
            mvwprintw(wdr, 1, 1, "-Pentru a va intoarce la lista de rezultate, apasati butonul B\n -Pentru a inchide browserul, apasati butonul Q\n");
            box(wdr, 0, 0);
            wrefresh(wdr);
            break;
        }
    }
}


int main(){
    listaSiteuri = setareBazaDeDate(listaSiteuri, &numar_siteuri, &capacitate);
    initscr(); /* Incepe modul curses */
    start_color();
    keypad(stdscr, TRUE);
    browser();
    endwin(); /* Sfarsitul modului curses */
    return 0;
}

void web(int a){
    curs_set(0);
    start_color();
    noecho();
    clear();
    WINDOW *wdr = newwin(HEIGHTR, WIDTHR, 0, 0);
    refresh();
    printLegenda(WEB);
    //box(wdr, 0, 0);
    wattron(wdr, A_BOLD);
    mvwprintw(wdr, 1, 5, "%s\n\n", listaFiltrate[a].cod.titlu);
    wrefresh(wdr);
    refresh();
    wattroff(wdr, A_BOLD);
    init_pair(1, listaFiltrate[a].cod.textColor, listaFiltrate[a].cod.backgroundColor);
    wattron(wdr, COLOR_PAIR(1));
    mvwprintw(wdr, 4, 0, "%s\n", listaFiltrate[a].cod.paragraf);
    //box(wdr, 0, 0);
    wrefresh(wdr);
    wattroff(wdr, COLOR_PAIR(1));
    char c = getch();
    while(c != 'b' && c != 'q'){
        c = getch();
    }
    if(c == 'b') rezultate();
    else if(c == 'q') {
        endwin();
        exit(EXIT_SUCCESS);
    }
}

void rezultate(){
    curs_set(0);
    noecho();
    clear();
    refresh();
    WINDOW *wdr = newwin(HEIGHTR, WIDTHC, 5, 0);
    WINDOW *searchBar = newwin(HEIGHTC, WIDTHC, 0, 0);
    box(searchBar, 0, 0);
    mvwprintw(searchBar, 1, 1, "%s", lista);
    box(searchBar, 0, 0);
    wrefresh(searchBar);
    printLegenda(REZULTATE);
    refresh();
    box(wdr, 0, 0);
    for(int i = 0; i < numar_filtrate; i++){
        if(i == selected){
            wattron(wdr, A_STANDOUT);
            mvwprintw(wdr, 1+4*i, 3, "*********************************************\n");
            mvwprintw(wdr, 2+4*i, 3, "%s\n", listaFiltrate[i].URL);
            mvwprintw(wdr, 3+4*i, 3, "%s\n", listaFiltrate[i].cod.titlu);
            mvwprintw(wdr, 4+4*i, 3, "*********************************************\n");
            wattroff(wdr, A_STANDOUT);
        }
        else{
            mvwprintw(wdr, 1+4*i, 3, "---------------------------------------------\n");
            mvwprintw(wdr, 2+4*i, 3, "%s\n", listaFiltrate[i].URL);
            mvwprintw(wdr, 3+4*i, 3, "%s\n", listaFiltrate[i].cod.titlu);
            mvwprintw(wdr, 4+4*i, 3, "---------------------------------------------\n");
        }
    }
    box(wdr, 0, 0);
    wrefresh(wdr);
    char c;
    c = getch();
    while(c != 10){
        //printw("%d", c);
        if(c == K_U || c == K_D){
            if(c == K_D && selected < numar_filtrate-1)
                selected++;
            else if(c == K_U && selected > 0)
                selected --;
            clear();
            refresh();
            box(searchBar, 0, 0);
            mvwprintw(searchBar, 1, 1, "%s", lista);
            box(searchBar, 0, 0);
            wrefresh(searchBar);
            printLegenda(REZULTATE);
            refresh();
            box(wdr, 0, 0);
            for(int i = 0; i < numar_filtrate; i++){
                if(i == selected){
                    wattron(wdr, A_STANDOUT);
                    mvwprintw(wdr, 1+4*i, 3, "*********************************************\n");
                    mvwprintw(wdr, 2+4*i, 3, "%s\n", listaFiltrate[i].URL);
                    mvwprintw(wdr, 3+4*i, 3, "%s\n", listaFiltrate[i].cod.titlu);
                    mvwprintw(wdr, 4+4*i, 3, "*********************************************\n");
                    wattroff(wdr, A_STANDOUT);
                }
                else{
                    mvwprintw(wdr, 1+4*i, 3, "---------------------------------------------\n");
                    mvwprintw(wdr, 2+4*i, 3, "%s\n", listaFiltrate[i].URL);
                    mvwprintw(wdr, 3+4*i, 3, "%s\n", listaFiltrate[i].cod.titlu);
                    mvwprintw(wdr, 4+4*i, 3, "---------------------------------------------\n");
                }
            }
            box(wdr, 0, 0);
            wrefresh(wdr);
        }
        
        if(c == 'q'){
            endwin();
            exit(EXIT_SUCCESS);
        }
        if(c == 'b')
            cautare();
        c = getch();
    }

    clear();
    refresh();
    box(wdr, 0, 0);
    wrefresh(wdr);
    web(selected);
    
}

void cautare(){
    echo();
    WINDOW *wdw = newwin(HEIGHTC, WIDTHC, 0, 0);
    clear();
    printLegenda(CAUTARE);
    refresh();
    box(wdw, 0, 0);
    wrefresh(wdw);
    wmove(wdw, 1, 1);
    wgetstr(wdw, lista);
    noecho();
    curs_set(0);
    int c;
    c = getch();
    while(c != 's' && c != 'a' && c != 'b' && c != 'q'){
        c = getch();
    }
    if(c == 's'){
        for(int i = 0; i < numar_cuvinte; i++)
            free(cuvinte[i]);
        free(cuvinte);
        cuvinte = getCuvinteLista(cuvinte, &numar_cuvinte, lista);
        listaFiltrate = filtrare(listaSiteuri, listaFiltrate, cuvinte, numar_siteuri, numar_cuvinte, &numar_filtrate);
        rezultate();
    }
    if(c == 'a'){
        for(int i = 0; i < numar_cuvinte; i++)
            free(cuvinte[i]);
        free(cuvinte);
        cuvinte = getCuvinteAvansLista(cuvinte, &numar_cuvinte, lista);
        listaFiltrate = filtrareAvans(listaSiteuri, listaFiltrate, cuvinte, numar_siteuri, numar_cuvinte, &numar_filtrate);
        rezultate();
    }
    if(c == 'b')
        browser();
    
    if(c == 'q'){
        endwin();
        exit(EXIT_SUCCESS);
    }

}

void browser(){
    int c;
    clear();
    noecho();
    WINDOW *wdr = newwin(5, 47, 0, 0);
    refresh();
    box(wdr, 0, 0);
    mvwprintw(wdr, 2, 13, "BROWSERUL LUI BIJU\n");
    box(wdr, 0, 0);
    wrefresh(wdr);
    curs_set(0);
    printLegenda(PAGINASTART);
    refresh();
    c = getch();
    if(c == 'q'){
        endwin();
        exit(EXIT_SUCCESS);
    }
    while(c != 'q'){
        if(c == 'c'){
            clear();
            curs_set(1);
            cautare();
        }
        c = getch();
    }
    
}