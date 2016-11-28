#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 *  * Definition for singly-linked list.
 *  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    ListNode* head;

    public:
        // head is linked list head
        // Note that the head is guaranteed to be not null, so
        // it contains at least one node.
        Solution(ListNode* Head)
        {
            head = Head;
        }

        // Returns a random node's value
        int getRandom()
        {
            int res = 0;
            int count = 0;
            ListNode* temp = head;

            while(temp)
            {
                if(temp == head)
                {
                    count++;
                    res = temp->val;
                }
                else
                {
                    count++;
                    if(rand()%count == 0)
                    {
                        res = temp->val;
                    }
                }
                temp = temp->next;
            }
            return res;
        }
};

int main(int argc, char const* argv[])
{

    return 0;
}
