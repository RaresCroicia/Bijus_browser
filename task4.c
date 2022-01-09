#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task0.h"

void dec_to_bin(int n, char *s){
    char aux[8];
    for(int i = 0; i < 8; i++)
        aux[i] = '0';
    int cn = 0;
    while(n){
        aux[cn] = n%2 + (int)'0';
        n/=2;
        cn++;
    }
    for(int i = 0; i < 8; i++)
        s[7-i] = aux[i];
}

int bin_to_dec(char *s){
    int puteri[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    int rezultat = 0;
    for(int i = 0; i < 8; i ++)
        rezultat += (int)(s[i]-'0') * puteri[7-i];
    return rezultat;
}

void rotireDreapta(char *s){
    char m = s[7];
    for(int i = 7; i > 0; i--)
        s[i] = s[i-1];
    s[0] = m;
}

void rotireStanga(char *s){
    char m = s[0];
    for(int i = 0; i < 7; i++)
        s[i] = s[i+1];
    s[7] = m;
}

int rotr(char x, int k){
    char binar[8];
    int ascii = (int)x;
    dec_to_bin(ascii, binar);
    for(int i = 0; i < k; i++)
        rotireDreapta(binar);
    return bin_to_dec(binar);
}

int rotl(char x, int k){
    char binar[8];
    int ascii = (int)x;
    dec_to_bin(ascii, binar);
    for(int i = 0; i < k; i++)
        rotireStanga(binar);
    return bin_to_dec(binar);
}

int checksum(site a){
    int len = strlen(a.cod.codHtml);
    int rez = (int)a.cod.codHtml[0];
    for(int i = 1; i < len; i++){   
        if(i % 2 == 0) {
            rez ^= rotl(a.cod.codHtml[i], i%8);
        }
        else{
            rez ^= rotr(a.cod.codHtml[i], i%8);
        }
    }
    return rez;
}

int checkIndice(site *a, int n, char *cautat){
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].nume, cautat) == 0)
            return i;
    }
    return -1;
}