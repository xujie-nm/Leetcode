#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head){
    RandomListNode preHead(-1);
    RandomListNode* pH = &preHead;
    
    map<RandomListNode*, RandomListNode*> HeadandRandom;
    while(head != NULL){
        RandomListNode* cur = NULL;
        RandomListNode* random = NULL;
        if(HeadandRandom.count(head) == 0){
            cur = new RandomListNode(head->label);
            HeadandRandom[head] = cur;
        }
        if(head->random != NULL && HeadandRandom.count(head->random) == 0){
            random = new RandomListNode(head->random->label);
            HeadandRandom[head->random] = random;
        }

        if(cur == NULL)
            cur = HeadandRandom[head];
        if(random == NULL)
            random = HeadandRandom[head->random];
        pH->next = cur;
        pH->next->random = random;

        head = head->next;
        pH = pH->next;
    }
    return preHead.next;
}

int main(int argc, const char *argv[]){
    
    return 0;
}
