#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode *reverseKGroup(ListNode *head, int k){
    if(k == 1)
        return head;
    vector<vector<ListNode *> > temp_vec;
    ListNode *temp = head;
    ListNode *con = head;
    while(1){
        vector<ListNode *> temp_ls;
        int num = k;
        while(num){
            if(temp != NULL){
                temp_ls.push_back(temp);
                temp = temp->next;
                num--;
            }
            else
                break;
        }
        if(temp_ls.size() > 0)
        temp_vec.push_back(temp_ls);
        if(temp_ls.size() != k)
            break;
    }
    for(vector<vector<ListNode*> >::iterator it = temp_vec.begin(); 
            it != temp_vec.end(); ++it){
       if((*it).size() == k){
           if(con == head){
                head = *((*it).end() - 1);
                con = *((*it).begin());
                if(temp_vec.size()==1)
                    con->next = NULL;
           }
           else{
                con->next = *((*it).end() - 1);
                con = *((*it).begin());
                if(it == temp_vec.end() - 1)
                    con->next = NULL;
           }
           for(vector<ListNode *>::reverse_iterator it_1 = (*it).rbegin(); 
                    it_1 != (*it).rend(); ++it_1){
                if(it_1 + 1 != (*it).rend())
                    (*it_1)->next = *(it_1 + 1);
            }

       }
       else{
           if(con == head)
               break;
           else
               con->next = *((*it).begin());
       }
    }
    return head;
}

int main(int argc, const char *argv[])
{
    ListNode first(1);
    ListNode second(2);
    ListNode third(3);
    ListNode fourth(4);
    ListNode fifth(5);
    first.next = &second;
    second.next = &third;
    third.next = &fourth;
 //   fourth.next = &fifth;

    ListNode *res = reverseKGroup(&first, 2);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
