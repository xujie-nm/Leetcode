#include <iostream>
#include <string>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head){
    if(head == NULL)
        return ;
    deque<ListNode*> temp;
    ListNode* p = head;
    while(p != NULL){
        temp.push_back(p);
        p = p->next;
    }
    
    temp.pop_front();
    while(!temp.empty()){
        head->next = temp.back();
        head = head->next;
        if(temp.size() == 1)
            head->next = NULL;
        temp.pop_back();
        if(!temp.empty()){
            head->next = temp.front();
            head = head->next;
            if(temp.size() == 1)
                head->next = NULL;
            temp.pop_front();
        }
    }
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    n1.next = &n2;
    n2.next = &n3;
    reorderList(&n1);

    ListNode *p = &n1;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
