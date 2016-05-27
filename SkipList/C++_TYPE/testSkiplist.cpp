#include "skiplist.h"
// OR #include "skiplist.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, const char *argv[])
{
    srand((unsigned)time(0));
    int count = 20, i;

    printf("### Function Test ###\n");

    printf("=== Init Skip List === \n");
    Skiplist sl;
    for (int i = 0; i < count; i++) {
        sl.insert(i);
    }
    printf("=== Print Skip List ===\n");
    sl.print();

    printf("=== Search Skip List ===\n");
    for (int i = 0; i < count; i++) {
        int value = rand()%(count+10);
        sl.search(value);
    }

    printf("=== Delete Skip List ===\n");
    for (int i = 0; i < count+10; i+=2) {
        printf("Delete[%d]: %s\n", i, sl.deleteItem(i) ? 
               "SUCCESS" : "FAILED");
    }
    sl.print();
    return 0;
}
