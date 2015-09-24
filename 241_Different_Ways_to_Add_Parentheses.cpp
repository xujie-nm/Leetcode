#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//recursive
vector<int> diffWaysToCompute(string input){
    vector<int> res;
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        if(c == '+' || c== '-' || c=='*'){
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1));
            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    res.push_back(c=='+' ? left[i] + right[j]: 
                    c=='-' ? left[i]-right[i] : left[i]*right[j]);
                }
            }
        }
    }

    if(res.empty()){
        res.push_back(stoi(input));
    }

    return res;
}

//DP
vector<int> diffWaysToCompute2(string input){
    vector<int> data;
    vector<char> ops;
    int num = 0;
    char op = ' ';
    istringstream ss(input + "+");
    while(ss >> num && ss >> op){
        data.push_back(num);
        ops.push_back(op);
    }

    int size_d = data.size();
    vector<vector<vector<int> > > dp(size_d, vector<vector<int> >(size_d, vector<int>()));
    for (int i = 0; i < size_d; i++) {
        for (int j = i; j >= 0 ; j--) {
            if(i == j){
                dp[j][i].push_back(data[i]);
                continue;
            }
            for (int k = j; k < i; k++) {
                for(auto left: dp[j][k]){
                        for(auto right: dp[k+1][i]){
                            int val = 0;
                            switch(ops[k]){
                                case '+': val = left + right; break;
                                case '-': val = left - right; break;
                                case '*': val = left * right; break;
                            }
                            dp[j][i].push_back(val);
                        }
                }
            }
            
        }
    }
    return dp[0][size_d - 1];
}

int main(int argc, const char *argv[])
{
    vector<int> res;
    res = diffWaysToCompute2("2*3-4*5");
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
