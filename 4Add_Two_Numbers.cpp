#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int num1, num2, sum;
    int flag = 0;
    ListNode* l3 = new ListNode(-1);
    ListNode* p = l3;
    while(l1 || l2)
    {
        if(l1)
        {
            num1 = l1->val;
            l1 = l1->next;
        }
        else
            num1 = 0;
        if(l2)
        {
            num2 = l2->val;
            l2 = l2->next;
        }
        else
            num2 = 0;
        sum = num1 + num2 + flag;
        if(p->val == -1)
        {
            p->val = sum % 10;
        }
        else
        {
            ListNode* pp = new ListNode(sum % 10);        
            p->next = pp;
            p = pp;
        }
        flag = sum / 10;
    }
    if(flag > 0)
    {
        ListNode* pp = new ListNode(flag);         
        p->next = pp;
    }
    return l3;
}

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2){
   int overTen = 0;
   ListNode *res = l1, *pre = l1;
   while(l1 != NULL || l2 != NULL){
        if(l1 != NULL && l2 != NULL){
            int curVal = l1->val + l2->val + overTen;
            l1->val = curVal%10;
            overTen = curVal/10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }else if(l1 != NULL){
            int curVal = l1->val + overTen;
            l1->val = curVal%10;
            overTen = curVal/10;
            pre = l1;
            l1 = l1->next;
        }else if(l2 != NULL){
            int curVal = l2->val + overTen;
            l2->val = curVal%10;
            overTen = curVal/10;
            pre->next = l2;
            pre = l2;
            l2 = l2->next;
        }
   }
   if(overTen > 0){
        ListNode* node = new ListNode(overTen);
        pre->next = node;
   }
   return res;
}


int main(int argc, const char *argv[])
{
    ListNode l11(2);
    ListNode l12(4);
    ListNode l13(5);
    l11.next = &l12;
    l12.next = &l13;
    ListNode l21(5);
    ListNode l22(6);
    ListNode l23(4);
    l21.next = &l22;
    l22.next = &l23;

    ListNode *res;
    res = addTwoNumbers2(&l11, &l21);
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}
