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

// use less space
// 先把节点复制一份
// 放到每个节点的后面
void cloneNodes(RandomListNode* head){
    RandomListNode* node = head;
    while(node != NULL){
       RandomListNode* cloned = new RandomListNode(node->label);
        cloned->next = node->next;
        cloned->random = NULL;

        node->next = cloned;

        node = cloned->next;
    }
}

// 把复制出来的random连接起来
void connectRandomNodes(RandomListNode* head){
    RandomListNode* node = head;
    while(node != NULL){
        RandomListNode* cloned = node->next;
        if(node->random != NULL){
            cloned->random = node->random->next;
        }
        node = cloned->next;
    }
}

// 把原来的节点和复制出来的节点拆分开来
RandomListNode* detachList(RandomListNode* head){
    RandomListNode* node = head; 
    RandomListNode* clonedHead = NULL;
    RandomListNode* clonedNode = NULL;

    if(node != NULL){
        clonedHead = clonedNode = node->next;
        node->next = clonedNode->next;
        node = node->next;
    }

    while(node != NULL){
        clonedNode->next = node->next;
        clonedNode = clonedNode->next;
        node->next = clonedNode->next;
        node = node->next;
    }

    return clonedHead;
}

// 新的方法不使用map来存储原来node与randomNode之间的关系
// 所以少使用O(randomNodes)个空间
RandomListNode *copyRandomList2(RandomListNode *head){
    // 复制节点
    cloneNodes(head);
    // 连接random
    connectRandomNodes(head);
    // 拆分
    return detachList(head);
}

int main(int argc, const char *argv[]){
    
    return 0;
}
