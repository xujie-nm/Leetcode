#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
    int i = 0;
    int j = height.size() - 1;
    int max_area = 0;
    while(i < j){   
    int temp;
    temp = (j-i)*(min(height[i],height[j]));
    //计算当前面积
    if(temp > max_area)
        max_area = temp;
        //保留最大面积
    if(height[i] > height[j])
        j--;
    else
        i++;      
                //这里有个小trick
                //最初的想法是的复杂度是平方的
                //但是这个trick可以帮助降低复杂度
                //就是如果当前已经记录了最大面积
                //下一步如果面积还继续变大的话必须满足
                //得到比之前更大的height（而且j-i变小了）
                //所以下一步我们就让可能height变大的哪一方移位
    }   
    return max_area; 
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
