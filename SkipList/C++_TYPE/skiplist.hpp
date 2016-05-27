#ifndef __SKIPLIST_H
#define __SKIPLIST_H

#include <vector>
#include <stdlib.h>
#include <stdio.h>

const int SKIPLIST_MAXLEVEL  = 8;

//跳表节点
struct SkiplistNode{

    SkiplistNode(int level_, double score_):score(score_){
        levels.reserve(level_);
    }

    double score;
    SkiplistNode* backward;
    std::vector<SkiplistNode*> levels;
};

class Skiplist{
    private:
        SkiplistNode *header, *tail;
        unsigned long length;
        int level;

    public:
        Skiplist(){
            level = 1;
            length = 0;
            header = new SkiplistNode(SKIPLIST_MAXLEVEL, 0);
            for (int i = 0; i < SKIPLIST_MAXLEVEL; i++) {
                header->levels[i] = NULL;
            }
            header->backward = NULL;
            tail = NULL;
        }

        ~Skiplist(){
            SkiplistNode* node = header->levels[0];
            SkiplistNode* next;

            delete header;
            while(node){
                next = node->levels[0];
                delete node;
                node = next;
            }
        }

        SkiplistNode* insert(double score){
            SkiplistNode* update[SKIPLIST_MAXLEVEL];
            SkiplistNode* node;

            node = header;
            for (int i = level-1; i >= 0; i--) {
                while(node->levels[i] &&
                      node->levels[i]->score < score)
                    node = node->levels[i];

                update[i] = node;
            }

            int randomLevel = generateRandomLevel();
            if(randomLevel > level){
                for (int i = level; i < randomLevel; i++) {
                    update[i] = header;
                }
                level = randomLevel;
            }

            node = new SkiplistNode(randomLevel, score);
            for (int i = 0; i < randomLevel; i++) {
                node->levels[i] = update[i]->levels[i];
                update[i]->levels[i] = node;
            }

            node->backward = (update[0] == header ? NULL : update[0]);
            if(node->levels[0])
                node->levels[0]->backward = node;
            else
                tail = node;
            length++;
            return node;
        }

        int deleteItem(double score){
            SkiplistNode* update[SKIPLIST_MAXLEVEL];
            SkiplistNode* node;

            node = header;
            for (int i = level-1; i >= 0; i--) {
                while(node->levels[i]
                   && node->levels[i]->score < score){
                    node = node->levels[i];
                }
                update[i] = node;
            }

            node = node->levels[0];
            if(node && score == node->score){
                deleteNode(node, update);
                delete node;
                return 1;
            }
            return 0;
        }

        int search(double score){
            SkiplistNode* node;

            node = header;
            for (int i = level-1; i >= 0; i--) {
                while(node->levels[i]
                   && node->levels[i]->score < score){
                    node = node->levels[i];
                }
            }

            node = node->levels[0];
            if(node && score == node->score){
                printf("Found %d\n", (int)(node->score));
                return 1;
            }else{
                printf("Not Found %d\n", (int)score);
                return 0;
            }
        }

        void print(){
            SkiplistNode* node;

            for (int i = 0; i < SKIPLIST_MAXLEVEL; i++) {
                printf("LEVEL[%d]: ", i);
                node = header->levels[i];
                while(node){
                    printf("%d -> ", (int)(node->score));
                    node = node->levels[i];
                }
                printf("NULL\n");
            }
        }

    private:
        int generateRandomLevel(){
            int randomLevel = 1;
            while((rand()&0xFFFF) < (0.5 * 0xFFFF))
                randomLevel += 1;

            return (randomLevel < SKIPLIST_MAXLEVEL) ?
                    randomLevel : SKIPLIST_MAXLEVEL;
        }

        void deleteNode(SkiplistNode* x, SkiplistNode** update){
            for (int i = 0; i < level; i++) {
                if(update[i]->levels[i] == x){
                    update[i]->levels[i] = x->levels[i];
                }
            }

            if(x->levels[0]){
                x->levels[0]->backward = x->backward;
            }else{
                tail = x->backward;
            }

            while(level > 1 && header->levels[level-1] == NULL)
                level--;
            length--;
        }
};

#endif
