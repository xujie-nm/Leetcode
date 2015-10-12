#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
        //Initialize your data structure here
        Node(){
            for (int i = 0; i < 26; i++) {
                has_word[i] = false;
                next_letter[i] = 0;
            }
            
        }
        
        Node* next_letter[26];
        bool has_word[26];
};

class WordDictionary{
    public:
        WordDictionary(){
            root = new Node();
        }

        ~WordDictionary(){
            delete root;
        }
        // add a word into the data structure
        void addWord(string word){
            Node* cur = root;

            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if(i+1 == word.size()){
                    cur->has_word[index] = true;
                }else{
                    if(cur->next_letter[index] == 0){
                        cur->next_letter[index] = new Node();
                    }
                    cur = cur->next_letter[index];
                }
            }
        }

        // Return if the word is in the data structure
        // contain the dot character '.' to represent any one letter
        bool search(string word){
            return search(word, root, 0);
        }

    private:
        bool search(const string& word, Node* root, int count){
            int index = word[count] - 'a';
            if(count+1 > word.size()){
                return false;
            }else if(count+1 == word.size()){
                if(word[count] == '.'){
                    for (int i = 0; i < 26; i++) {
                        if(root->has_word[i])
                            return true;
                    }
                }else
                    return root->has_word[index];
            }else{
                if(word[count] == '.'){
                    for (int i = 0; i < 26; i++) {
                        if(root->next_letter[i] && search(word, root->next_letter[i], count+1))
                            return true;
                    }
                }
                else{
                    if(root->next_letter[index] == 0){
                        return false;
                    }
                    return search(word, root->next_letter[index], count+1);
                }
            }
        }

        Node *root;
};


int main(int argc, const char *argv[])
{
    WordDictionary wd;
    wd.addWord("something");
    wd.addWord("key");
    cout << wd.search("key") << endl;
    cout << wd.search(".ey") << endl;
    cout << wd.search("...") << endl;
    cout << wd.search("..y") << endl;
    cout << wd.search("k..") << endl;
    cout << wd.search("....") << endl;
    cout << wd.search("keye") << endl;
    cout << wd.search("some") << endl; 
    return 0;
}
