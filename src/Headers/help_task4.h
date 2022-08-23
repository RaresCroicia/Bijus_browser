#ifndef __task4H_h__
#define __task4H_h__
#include "site.h"

int rotr(char x, int k);
int rotl(char x, int k);
void dec_to_bin(int n, char *s);
int bin_to_dec(char *s);
void rotireStanga(char *s);
void rotireDreapta(char *s);
int checksum(site a);
int checkIndice(site *a, int n, char *cautat);
char** readCuvinte(char **cuvinte, int *nrCuv);
#endif