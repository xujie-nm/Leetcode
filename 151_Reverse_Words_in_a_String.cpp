#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverseWords(string &s){
    int i = 0;
    int j = s.size()-1;
    
    while(s[i] == ' ')
        i++;
    while(s[j] == ' ')
        j--;
    if(s == " " || i > j){
        s = "";
        return;
    }else
        s = s.substr(i, j-i+1);

    int count = 1;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] != ' '){
            temp += s[i];
            count = 1;
        }
        else{
            if(count > 1)
                continue;
            else{
                temp += s[i];
                count++;
            }
        }
    }
    s = temp;
    

    i = 0;
    j = s.size()-1;
    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    i = 0;
    j = 0;
    s += " ";
    for (int a = 0; a < s.size(); a++) {
        if(s[a] == ' '){
            j = a-1;
            while(i < j){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            i = a+1;
            j = i;
        }        
    }
    s = s.substr(0, s.size()-1);
}

int main(int argc, const char *argv[])
{
    string s = "  the   sky    is  blue ";
    reverseWords(s);
    cout << s << endl;
    return 0;
}
