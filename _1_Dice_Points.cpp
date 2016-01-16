#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 把n个骰子扔在地上，所有骰子朝上的一面的点数和为s。
// 给出n个骰子，计算所有加起来等于s的概率

/// 第一种方法，不够快，指数级
void helper(int number, int curDices, int curPoint, vector<double>& probailities){
    if(curDices == number){
        probailities[curPoint - number] += 1;
        return;
    }

    for (int i = 1; i <= 6; i++) {
        helper(number, curDices + 1, curPoint + i, probailities);
    }

}

vector<double> DicePointProbaility(int number){
    vector<double> probailities(number * 6 - number + 1, 0.0);

    if(probailities.size() == 0)
        return probailities;
    
    helper(number, 0, 0, probailities);

    double maxValue = 6;
    double total = pow(maxValue, number);

    for (int i = 0; i < probailities.size(); i++) {
        probailities[i] /= total;   
    }

    return probailities;
}

int main(int argc, const char *argv[])
{
    vector<double> probailities;

    probailities = DicePointProbaility(11);

    double sum = 0;
    for (int i = 0; i < probailities.size(); i++) {
        sum += probailities[i];
        cout << probailities[i] << " ";
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
