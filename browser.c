#include <stdio.h>
#include <stdlib.h>
#include "task0.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "sort.h"
#include <string.h>
#include <ncurses.h>

int main(){
    initscr(); /* Incepe modul curses */
    printw("Hello World !!!"); /* Afiseaza Hello World */
    refresh(); /* Actulaizeaza-l pe ecranul real */
    endwin(); /* Sfarsitul modului curses */
    return 0;
}