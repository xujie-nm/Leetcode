#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex){
   vector<int> res;
   res.push_back(1);
   if(rowIndex == 0)
       return res;
   res.push_back(1);
   if(rowIndex == 1)
       return res;

   for (int i = 1; i <= rowIndex ; i++) {
       vector<int> temp(i+1, 1);
       for (int j = 1; j < i; j++) {
           temp[j] = res[j] + res[j-1];
       }
       res = temp;
   }
   return res;
}

int main(int argc, const char *argv[])
{
    vector<int > res;
    res = getRow(5);

    for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
    }
   cout << endl; 
    
    return 0;
}
