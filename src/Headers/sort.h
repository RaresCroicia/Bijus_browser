#ifndef __sort_h__
#define __sort_h__
#include "site.h"

void swap(site *a, site *b);
void sortare(site *siteAct, int n, int (*cmp)(site text1, site text2));
void afisareURL(site *a, int n);

#endif 