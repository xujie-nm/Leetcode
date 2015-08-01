#include <iostream>
#include <string>
#include <map>
using namespace std;

class TrieNode{
    public:
        //Initialize your data structure here
        TrieNode(){
            for (int i = 0; i < 26; i++) {
                has_word[i] = false;
                next_letter[i] = 0;
            }
            
        }
        
        ~TrieNode(){
            delete[] next_letter;
            delete[] has_word;
        }

        TrieNode* next_letter[26];
        bool has_word[26];
};

class Trie{
    public:
        Trie(){
            root = new TrieNode();
        }
        
        // Insert a word into the trie
        void insert(string word){
            TrieNode* cur = root;

            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if(i+1 == word.size()){
                    cur->has_word[index] = true;
                }else{
                    if(cur->next_letter[index] == 0){
                        cur->next_letter[index] = new TrieNode();
                    }
                    cur = cur->next_letter[index];
                }
            }
        }

        // Return if the word is in the trie
        bool search(string word){
            TrieNode* cur = root;

            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if(i+1 == word.size()){
                    return cur->has_word[index];
                }else{
                    if(cur->next_letter[index] == 0)
                        return false;
                    cur = cur->next_letter[index];
                }
            }
        }

        // Return if there is any word in the trie
        // that starts with the given prefix
        bool startsWith(string prefix){
            TrieNode* cur = root;

            for (int i = 0; i < prefix.size(); i++) {
                int index = prefix[i] - 'a';
                if(i+1 == prefix.size()){
                    if(cur->has_word[index] || cur->next_letter[index])
                        return true;
                    else
                        return false;
                }else{
                    if(cur->next_letter[index] == 0)
                        return false;
                    cur = cur->next_letter[index];
                }
            }
        }

    private:
        TrieNode *root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("something");
// trie.search("key");
int main(int argc, const char *argv[])
{
    Trie trie;
    trie.insert("something");
    trie.insert("key");
    cout << trie.search("key") << endl;
    cout << trie.search("keye") << endl;
    cout << trie.search("some") << endl;
    cout << trie.startsWith("some") << endl;
    cout << trie.startsWith("soma") << endl;
    cout << trie.startsWith("somethingo") << endl;
    return 0;
}
