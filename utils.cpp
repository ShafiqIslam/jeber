#include <cstdio>
#include <cstdlib>
#include "utils.h"

void *checked_malloc(int len) {
    void *p = malloc(len);
    if (!p) {
        cerr << "\nRan out of memory!\n";
        exit(1);
    }
    return p;
}
