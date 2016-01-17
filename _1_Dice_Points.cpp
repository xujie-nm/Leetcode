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

/// 这次的方法的复杂度为O(N^2)
vector<double> DicePointProbaility2(int number){
    vector<vector<double> > probailities(2, vector<double>(6*number + 1));
    if(number < 1)
        return probailities[0];

    // 用于循环两个数组
    int flag = 0;
    // 当有一个骰子
    for (int i = 1; i <= 6; i++) {
        probailities[flag][i] = 1;
    }

    // 从第二个骰子开始
    for (int k = 2; k <= number; k++) {
        // 把需要计算的骰子置为0
        for (int i = 0; i < k; i++) {
            probailities[1-flag][i] = 0;
        }

        // 计算当前骰子能取到的所有值
        for (int i = k; i <= 6 * k; i++) {
            probailities[1-flag][i] = 0;
            // 假设当前的骰子出现的次数为i
            // 那么他与上次骰子出现的次数的关系是：
            // cur[i] = pre[i-1] + pre[i-2] + pre[i-3] + pre[i-4] + pre[i-5] + pre[i-6]
            for (int j = 1; j <= i && j <= 6; j++) {
                probailities[1-flag][i] += probailities[flag][i-j];
            }
        }

        // 置换两个数组
        flag = 1-flag;
    }

    double maxValue = 6;
    double total = pow(maxValue, number);
    for (int i = number; i <= 6 * number; i++) {
        probailities[flag][i] /= total;
    }

    return probailities[flag];
}

int main(int argc, const char *argv[])
{
    vector<double> probailities;

    probailities = DicePointProbaility2(6);

    double sum = 0;
    for (int i = 0; i < probailities.size(); i++) {
        sum += probailities[i];
        cout << probailities[i] << " ";
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
