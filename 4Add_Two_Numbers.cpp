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

class Solution {
    public:
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
};


int main(int argc, const char *argv[])
{
    return 0;
}
