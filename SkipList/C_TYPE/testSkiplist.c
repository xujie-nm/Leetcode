#include "skiplist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, const char *argv[])
{
    srand((unsigned)time(0));
    int count = 20, i;

    printf("### Function Test ###\n");

    printf("=== Init Skip List === \n");
    skiplist* sl = slCreate();
    for(i = 0; i < count; i++){
        slInsert(sl, i);
    }
    printf("=== Print Skip List ===\n");
    slPrint(sl);

    printf("=== Search Skip List ===\n");
    for(i = 0; i < count; i++){
        int value = rand()%(count+10);
        slSearch(sl, value);
    }
    printf("=== Delete Skip List ===\n");
    for(i = 0; i < count+10; i+=2){
        printf("Delete[%d]: %s\n", i, slDelete(sl, i) ? "SUCCESS":"NOT FOUND");
    }
    slPrint(sl);
    sl = NULL;
    return 0;
}

