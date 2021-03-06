#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n){
    if(head==NULL || m==n)
        return head;
    ListNode Head(0);
    Head.next = head;
    head = &Head;
    ListNode* preNode;
    stack<ListNode*> nodeStack;
    int i = 0;
    while(i <= n){
        if(i== m-1)
            preNode = head;
        if(i >= m){
            nodeStack.push(head);
        }
        i++;
        head = head->next;
    }
    
    while(!nodeStack.empty()){
        preNode->next = nodeStack.top();
        preNode = preNode->next;
        nodeStack.pop();
    }

    preNode->next = head;
    return Head.next;
}

ListNode* reverseBetween2(ListNode* head, int m, int n){
    if(head == NULL || m >= n)
        return head;
    ListNode* Head = new ListNode(0);
    Head->next = head;
    ListNode *pre, *cur, *post, *tail = Head;
    for (int i = 0; i < m-1; i++) {
        tail = tail->next;
    }
    pre = tail->next;
    cur = pre->next;
    for (int i = 0; i < n-m; i++) {
        post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    // 把后面连起来
    tail->next->next = cur;
    // 把前面连起来
    tail->next = pre;
    
    return Head->next;
}

int main(int argc, const char *argv[])
{
    ListNode l1(3);
    ListNode l2(5);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ListNode* res = reverseBetween2(&l1, 1, 2);

    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
