#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//Breadth-first Search
void helper(int &res, int n, int count, int Root){
   if(count >= res)
       return;
   int root = sqrt(n);
   int left = n - root*root;
   if(left == 0){
       res = min(count + 1, res);
       return;
   }
   root = min(Root, root);
   while(root >= 1){
       left = n - root*root;
       helper(res, left, count+1, root);
       root--;
   }
}

int numSquares(int n){
    int res = n;
    helper(res, n, 0, n);
    return res;
}

//Mathematically
//The Lagrange's Four Square theorem
//https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
int isSquare(int n){
    int root = sqrt(n);
    return root*root == n;
}

int numSquares2(int n){
    while((n & 3) == 0)
        n >>= 2;
    if((n & 7) == 7)
        return 4;
    if(isSquare(n))
        return 1;
    int root = sqrt(n);
    for (int i = 0; i <= root; i++) {
        if(isSquare(n -i*i))
            return 2;
    }
    return 3;
}

//dp
int numSquares3(int n){
    vector<int> dp(n+1, INT_MAX);
    int temp;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; (temp = i + j*j) <= n; j++) {
            //计算出此次循环可能得到的所有的数
            //与它的前一个比较得到新值
            if(dp[temp] > dp[i]+1)
                dp[temp] = dp[i] + 1;
        }
    }

    return dp[n];
}

int main(int argc, const char *argv[])
{
    //cout << numSquares(12) << endl;
    cout << numSquares3(13) << endl;
    //cout << numSquares(10) << endl;
    //cout << numSquares(11) << endl;
    //cout << numSquares(0) << endl;
    //cout << numSquares(5000) << endl;
    return 0;
}

