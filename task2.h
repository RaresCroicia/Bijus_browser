#ifndef __task2_h__
#define __task2_h__

#include <stdio.h>
#include <stdlib.h>
#include "task0.h"

char** getCuvinte(char **cuvinte, int *nC);
site* filtrare(site *st, site *stf, char **cuv, int nS, int nC, int *nS_F);
int cmp_2(site a, site b);

#endif