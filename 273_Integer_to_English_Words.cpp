#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


vector<string> label({"","Throusand", "Million", "Billion"});
unordered_map<int, string> table = {
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"},
    {20, "Twenty"},
    {30, "Thirty"},
    {40, "Forty"},
    {50, "Fifty"},
    {60, "Sixty"},
    {70, "Seventy"},
    {80, "Eighty"},
    {90, "Ninety"},
};

string helper(int num){
    if(num == 0)
        return "";
    string res;
    if(num >= 100){
        int hundred = num/100;
        res += table[hundred] + " " + "Hundred" + " ";
        num = num % 100;
    }
    if(num >= 20){
        int ten = num/10 *10;
        res += table[ten] + " ";
        num = num % 10;
    }
    if(num < 20 && num >= 10){
        res += table[num] + " ";
        num = 0;
    }
    if(num > 0 && num < 10){
        res += table[num] + " ";
    }
    return res;
}

string numberToWords(int num){
    if(num == 0)
        return "Zero";
    string res;
    string temp ="";
    vector<int> three;
    while(num != 0){
        three.push_back(num % 1000);
        num /= 1000;
    }

    for (int i = 0; i < three.size(); i++) {
        if(three[i] != 0){
            res = label[i] + " " + res;
            res = helper(three[i])  + res;
        }
    }
    
    int i = res.size()-1;
    while(res[i] == ' ')
        i--;
    
    res = res.substr(0, i+1);
    return res;
}

int main(int argc, const char *argv[])
{
    cout << helper(3) << endl;
    cout << helper(13) << endl;
    cout << helper(23) << endl;
    cout << helper(103) << endl;
    cout << helper(113) << endl;
    cout << helper(123) << endl;
    string res;
    res = numberToWords(999999);
    //res = numberToWords(1);
    cout << res.size() << " " << res << endl;
    return 0;
}
