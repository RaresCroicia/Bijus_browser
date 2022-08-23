#ifndef __task2H_h__
#define __task2H_h__
#include "site.h"

site* filtrare(site *st, site *stf, char **cuv, int nS, int nC, int *nS_F);
int cmp_2(site a, site b);
char** getCuvinteParagraf(char** cuvinte, site a, int *nrC);
#endif