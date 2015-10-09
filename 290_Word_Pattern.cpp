#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string str){
   if(pattern == "" || str == "") 
       return false;

   vector<string> words;
   int first = 0;
   int second = 0;
   while(first <= str.size() && second <= str.size()){
        if(str[second] == ' ' || second == str.size()){
            string temp = str.substr(first, second - first);
            int i = 0, j = temp.size()-1;
            while(temp[i] == ' ' || temp[j] == ' '){
                if(temp[i] == ' ')
                    i++;
                if(temp[j] == ' ')
                    j--;
            }
            words.push_back(temp.substr(i, j-i+1));
            first = second;
            second++;
        }else
            second++;
   }

   if(words.size() != pattern.size())
       return false;
   unordered_map<char, string> hash;
   for (int i = 0; i < pattern.size(); i++) {
       if(hash.count(pattern[i]) == 0){
            hash[pattern[i]] = words[i];
       }else{
            if(hash[pattern[i]] != words[i]){
                return false;
            }
       }
   }


   for(unordered_map<char, string>::iterator it = hash.begin(); it != hash.end(); ++it){
       for(unordered_map<char, string>::iterator it1 = it; it1 != hash.end(); ++it1){
           if(it->second == it1->second && it->first != it1->first){
               return false;
           }
       }
   }

   return true;
}

int main(int argc, const char *argv[])
{
    cout <<wordPattern("abba", "dog cat cat dog") << endl;;
    return 0;
}
