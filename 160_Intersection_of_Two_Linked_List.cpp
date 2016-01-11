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

int getLength(ListNode *head){
    int size = 0;
    while(head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

// 先找到两个链表的长度，
// 然后让两个链表从相同长处的位置出发，
// 当节点地址相同时，就是交集的起点
ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
    int lengthA = getLength(headA);
    int lengthB = getLength(headB);
    
    if(lengthA > lengthB){
        while(lengthA != lengthB){
            headA = headA->next;
            lengthA--;
        }
    }else if(lengthB > lengthA){
        while(lengthB != lengthA){
            headB = headB->next;
            lengthB--;
        }
    }

    while(headB != headA && headA != NULL && headB != NULL){
        headB = headB->next;
        headA = headA->next;
    }
    return headA;
}

// 借用两个辅助栈，
// 把元素全部压入栈，
// 一次出栈，最后一个相同的节点就是第一个公共节点
ListNode* getIntersectionNode2(ListNode *headA, ListNode *headB){
    stack<ListNode*> stackA;
    stack<ListNode*> stackB;

    while(headA != NULL){
        stackA.push(headA);
        headA = headA->next;
    }
    while(headB != NULL){
        stackB.push(headB);
        headB = headB->next;
    }

    ListNode* res = NULL;
    while(!stackA.empty() 
       && !stackB.empty()
       && stackA.top() == stackB.top()){
        res = stackA.top();
        stackA.pop();
        stackB.pop();
    }
    return res;
}

int main(int argc, const char *argv[])
{
    ListNode a1(0);
    ListNode a2(0);
    ListNode b1(0);
    ListNode b2(0);
    ListNode b3(0);
    ListNode c1(54);
    ListNode c2(0);
    ListNode c3(0);
    a1.next = &a2;
    a2.next = &c1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    
    cout << &c1 << endl;

    ListNode *res = getIntersectionNode(&a1, &b1);
    ListNode *res2 = getIntersectionNode2(&a1, &b1);

    cout << res << "   " << res->val << endl;
    cout << res2 << "   " << res2->val << endl;
    return 0;
}
