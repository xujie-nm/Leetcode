#ifndef __SKIPLIST_H
#define __SKIPLIST_H

#define SKIPLIST_MAXLEVEL 8

typedef struct skiplistNode{
    double score;
    struct skiplistNode* backward;
    struct skiplistLevel{
        struct skiplistNode* forward;
    }level[];
} skiplistNode;

typedef struct skiplist{
    skiplistNode *header, *tail;
    unsigned long length;
    int level;
}skiplist;

skiplistNode* slCreateNode(int level, double score);

skiplist* slCreate();

void slFreeNode(skiplistNode* sn);

void slFree(skiplist *sl);

int slRandomLevel();

skiplistNode* slInsert(skiplist* sl, double score);

void slDeleteNode(skiplist* sl, skiplistNode* x, skiplistNode** update);

int slDelete(skiplist* sl, double score);

int slSearch(skiplist* sl, double score);

void slPrint(skiplist* sl);

#endif
