#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 由先序和中序得出一个结果
// 这个方法是有问题的，如果有相同的元素就不行
class Codec{
    public:

        void NLR(TreeNode* root, string &res){
            if(root == NULL)
                return;
            res += to_string(root->val);
            res += ',';
            NLR(root->left, res);
            NLR(root->right, res);
        }

        void LNR(TreeNode* root, string &res){
            if(root == NULL)
                return;
            LNR(root->left, res);
            res += to_string(root->val);
            res += ',';
            LNR(root->right, res);
        }

        // Encodes a tree to a single string
        string serialize(TreeNode* root){
            string res;
            NLR(root, res);
            res += ".";
            LNR(root, res);
            return res;
        }

        void helper(TreeNode *root, string nlr, string lnr){
            string::size_type firstPos = nlr.find(",");
            root->val = atoi(nlr.substr(0, firstPos).c_str());
          
            string data = nlr.substr(0, firstPos);
            if(firstPos != nlr.size()-1)
                data = ","+data;
            else 
                return;
            int dataLength = nlr.substr(0, firstPos).size();
            string::size_type lnrPos = lnr.find(data);
            
            string leftLnr = lnr.substr(0, lnrPos+1);
            string rightLnr = lnr.substr(lnrPos + dataLength + 2);
            string leftNlr = nlr.substr(dataLength+1, leftLnr.size());
            string rightNlr = nlr.substr(1+ dataLength +leftLnr.size());
                
            if(leftNlr.size() > 0 && leftLnr.size() > 0){
                root->left = new TreeNode(-1);
                helper(root->left, leftNlr, leftLnr);
            }
            if(rightNlr.size() > 0 && rightLnr.size() > 0){
                root->right = new TreeNode(-1);
                helper(root->right, rightNlr, rightLnr);
            }
        }

        // Decodes your encoded data to tree
        TreeNode* deserialize(string data){
            string::size_type pos = data.find(".");
            string nlr = data.substr(0, pos);
            string lnr = data.substr(pos+1);
            TreeNode *root = new TreeNode(-1);
            helper(root, nlr, lnr);
            return root;
        }
};

// level order
class Codec1{
    public:
        string serialize(TreeNode* root){
            string res = "";
            if(root == NULL)
                return res;

            queue<TreeNode*> treeNodeQueue;
            treeNodeQueue.push(root);
            while(!treeNodeQueue.empty()){
                TreeNode* temp = treeNodeQueue.front();
                treeNodeQueue.pop();
                if(temp != NULL){
                    res += to_string(temp->val) + ",";
                    treeNodeQueue.push(temp->left);
                    treeNodeQueue.push(temp->right);
                }else
                    res += "#,";
            }
            return res;
        }

        TreeNode* deserialize(string data){
            if(data.size() == 0)
                return NULL;
            queue<TreeNode*> treeQueue;
            string val = data.substr(0, data.find(","));
            data = data.substr(data.find(",")+1);
            TreeNode* temp = new TreeNode(atoi(val.c_str()));
            TreeNode* root = temp;
            treeQueue.push(temp);

            while(!treeQueue.empty()){
                TreeNode* p = treeQueue.front();
                treeQueue.pop();

                int pos;
                pos = data.find(",");
                if(pos == string::npos)
                    break;
                val = data.substr(0, pos);
                data = data.substr(pos+1);
                
                if(val != "#"){
                    TreeNode* tempLeft = new TreeNode(atoi(val.c_str()));
                    p->left = tempLeft;
                    treeQueue.push(tempLeft);
                }
                
                pos = data.find(",");
                if(pos == string::npos)
                    break;
                val = data.substr(0, pos);
                data = data.substr(pos+1);

                if(val != "#"){
                    TreeNode* tempRight = new TreeNode(atoi(val.c_str()));
                    p->right = tempRight;
                    treeQueue.push(tempRight);
                }
            }
            return root;
        }
};


int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(-1);
    TreeNode n3(2);
    TreeNode n4(3);
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;

    Codec1 codec;
    TreeNode* res;
    cout << codec.serialize(&n1) << endl;
    res = codec.deserialize(codec.serialize(&n1));
    cout << codec.serialize(res) << endl;
    return 0;
}
