#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode{
    public:                                                         
        //Initialize your data structure here
        TrieNode(){
            for (int i = 0; i < 26; i++) {
                word[i] = "";
                next_letter[i] = 0;
            }   
    
        }   
    
        TrieNode* next_letter[26];
        string word[26];
};

class Trie{
    public:
        Trie(){
            root = new TrieNode();
        }

        ~Trie(){
            delete root;
        }

        // Insert a word into the trie
        void insert(string word){
            TrieNode* cur = root;

            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if(i+1 == word.size()){
                    cur->word[index] = word;
                }else{
                    if(cur->next_letter[index] == 0){
                        cur->next_letter[index] = new TrieNode();
                    }
                    cur = cur->next_letter[index];
                }
            }
        }

        TrieNode *root;
};

void searchWord(vector<vector<char> > &board, vector<string> &res, int n, int m, int i, int j, TrieNode *root){
    if(board[i][j] == '\0')
        return;
    int index = board[i][j] - 'a';
    if((root->word[index].size()) > 0){
        //如果找到，加入结果集
        res.push_back(root->word[index]);
        root->word[index] = "";
    }
    if(root->next_letter[index] != 0){
        //如果当前这个字符存在，向四个方向查找
        char temp = board[i][j];
        root = root->next_letter[index];
        //把走过的路置为空
        board[i][j] = '\0'; 
        if(i-1 >= 0){
            searchWord(board, res, n, m, i-1, j, root);
        }
        if(i+1 < n){
            searchWord(board, res, n, m, i+1, j, root);
        }
        if(j-1 >= 0){
            searchWord(board, res, n, m, i, j-1, root);
        }
        if(j+1 < m){
            searchWord(board, res, n, m, i, j+1, root);
        }
        //恢复走过的路
        board[i][j] = temp;
    }
}

vector<string> findWords(vector<vector<char> > &board, vector<string> &words){
    vector<string> res;
    int n = board.size();
    if(n == 0)
        return res;
    int m = board[0].size();
    if(m == 0)
        return res;
    Trie trie;
    for (int i = 0; i < words.size(); i++)
        trie.insert(words[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            searchWord(board, res, n, m, i, j, trie.root);
        }
    }
    return res;    
}

int main(int argc, const char *argv[])
{
    vector<char> line1{'a', 'b'};
    vector<char> line2{'a', 'a'};
    vector<char> line3{'a', 'a', 'a', 'a'};
    vector<char> line4{'i', 'f', 'l', 'v'};
    vector<vector<char> > board{line1, line2};
    vector<string> words{"aba", "baa", "bab", "aaab", "aaa", "aaaa", "aaba"};

    vector<string> res;
    res = findWords(board, words);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
   
    return 0;
}
