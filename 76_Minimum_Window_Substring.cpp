#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool has(string str1, string str2){
    for (int i = 0; i < str2.size(); i++) {
        if(str1.find(str2[i]) == string::npos)
            return false;
    }
    return true;
}

string minWindow(string S, string T){
    if(T.size() > S.size())
        return "";
    else if(S.size() == T.size())
        return S == T ? T : "";

    map<int, char> index_letter;
    int Tlength = T.size();

    for (int i = 0; i < T.size(); i++) {
        int found = -1;
        found = S.find(T[i], found + 1);
        while(found != string::npos){
            if(index_letter.count(found) == 0)
                index_letter.insert(make_pair(found, T[i]));
            found = S.find(T[i], found + 1);
        }
    }
    
    if(index_letter.size() < Tlength)
        return "";

    map<int, string> length_str;
    for(map<int, char>::iterator it = index_letter.begin(); it != index_letter.end(); ++it){
        int temp_length = Tlength;
        string temp_str = S.substr(it->first, temp_length);
        while(it->first + temp_length - 1< S.size()){

            if(has(temp_str, T)){
                length_str.insert(make_pair(temp_str.size(), temp_str));
                break;
            }else{
                temp_length++;
                if(it->first + temp_length - 1 < S.size())
                    temp_str += S[it->first + temp_length - 1];
                else
                    break;
            }
        }
    }
    
    if(!length_str.empty())
        return length_str.begin()->second;
    else
        return "";
}

int main(int argc, const char *argv[])
{
    //cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindow("babbBba", "Abbb") << endl;
    return 0;
}
