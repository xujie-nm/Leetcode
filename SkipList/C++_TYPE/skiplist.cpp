#include "skiplist.h"

#include <stdlib.h>
#include <stdio.h>

SkiplistNode::SkiplistNode(int level, double score):score_(score){
    levels_.reserve(level);
}

Skiplist::Skiplist(){
    level_ = 1;
    length_ = 0;
    header_ = new SkiplistNode(SKIPLIST_MAXLEVEL, 0);
    for (int i = 0; i < SKIPLIST_MAXLEVEL; i++) {
        header_->levels_[i] = NULL;
    }
    header_->backward_ = NULL;
    tail_ = NULL;
}

Skiplist::~Skiplist(){
    SkiplistNode* node = header_->levels_[0];
    SkiplistNode* next;

    delete header_;
    while(node){
        next = node->levels_[0];
        delete node;
        node = next;
    }
}

SkiplistNode* Skiplist::insert(double score){
    SkiplistNode* update[SKIPLIST_MAXLEVEL];
    SkiplistNode* node;

    node = header_;
    for (int i = level_-1; i >= 0; i--) {
        while(node->levels_[i] &&
              node->levels_[i]->score_ < score)
            node = node->levels_[i];

        update[i] = node;
    }

    int randomLevel = generateRandomLevel();
    if(randomLevel > level_){
        for (int i = level_; i < randomLevel; i++) {
            update[i] = header_;
        }
        level_ = randomLevel;
    }

    node = new SkiplistNode(randomLevel, score);
    for (int i = 0; i < randomLevel; i++) {
        node->levels_[i] = update[i]->levels_[i];
        update[i]->levels_[i] = node;
    }

    node->backward_ = (update[0] == header_ ? NULL : update[0]);
    if(node->levels_[0])
        node->levels_[0]->backward_ = node;
    else
        tail_ = node;
    length_++;
    return node;
}

int Skiplist::deleteItem(double score){
    SkiplistNode* update[SKIPLIST_MAXLEVEL];
    SkiplistNode* node;

    node = header_;
    for (int i = level_-1; i >= 0; i--) {
        while(node->levels_[i]
           && node->levels_[i]->score_ < score){
            node = node->levels_[i];
        }
        update[i] = node;
    }

    node = node->levels_[0];
    if(node && score == node->score_){
        deleteNode(node, update);
        delete node;
        return 1;
    }
    return 0;
}

int Skiplist::search(double score){
    SkiplistNode* node;

    node = header_;
    for (int i = level_-1; i >= 0; i--) {
        while(node->levels_[i]
           && node->levels_[i]->score_ < score){
            node = node->levels_[i];
        }
    }

    node = node->levels_[0];
    if(node && score == node->score_){
        printf("Found %d\n", (int)(node->score_));
        return 1;
    }else{
        printf("Not Found %d\n", (int)score);
        return 0;
    }
}

void Skiplist::print(){
    SkiplistNode* node;

    for (int i = 0; i < SKIPLIST_MAXLEVEL; i++) {
        printf("LEVEL[%d]: ", i);
        node = header_->levels_[i];
        while(node){
            printf("%d -> ", (int)(node->score_));
            node = node->levels_[i];
        }
        printf("NULL\n");
    }
}

int Skiplist::generateRandomLevel(){
    int randomLevel = 1;
    while((rand()&0xFFFF) < (0.5 * 0xFFFF))
        randomLevel += 1;

    return (randomLevel < SKIPLIST_MAXLEVEL) ?
            randomLevel : SKIPLIST_MAXLEVEL;
}

void Skiplist::deleteNode(SkiplistNode* x, SkiplistNode** update){
    for (int i = 0; i < level_; i++) {
        if(update[i]->levels_[i] == x){
            update[i]->levels_[i] = x->levels_[i];
        }
    }

    if(x->levels_[0]){
        x->levels_[0]->backward_ = x->backward_;
    }else{
        tail_ = x->backward_;
    }

    while(level_ > 1 && header_->levels_[level_-1] == NULL)
        level_--;
    length_--;
}
