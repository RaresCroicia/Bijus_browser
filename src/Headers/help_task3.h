#ifndef __task3H_h__
#define __task3H_h__
#include "site.h"

char** getCuvinteAvans(char **cuvinte, int *nC);
site* filtrareAvans(site *st, site *stf, char **cuv, int nS, int nC, int *nS_F);
int cmp_3(site a, site b);
#endif