#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        Root = root;
        while(Root != NULL){
            s.push(Root);
            Root = Root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!s.empty() || Root)
            return true;
        else 
            return false;
    }

    /** @return the next smallest number */
    int next() {
        Root = s.top();
        int val = Root->val;
        s.pop();

        Root = Root->right;
        while(Root){
            s.push(Root);
            Root = Root->left;
        }

        return val;
    }

private:
    TreeNode *Root;
    stack<TreeNode *> s;
};

int main(int argc, const char *argv[])
{
    TreeNode n1(5); 
    TreeNode n2(3); 
    TreeNode n3(6); 
    TreeNode n4(2); 
    TreeNode n5(4);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    BSTIterator i = BSTIterator(&n1);
    while(i.hasNext())
        cout << i.next() << " ";
    return 0;
}
