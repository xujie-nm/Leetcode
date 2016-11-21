#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//TLE
int lastRemaining(int n)
{
	stack<int> stack1, stack2;
	for (int i = n; i >0; --i)
	{
		stack1.push(i);
	}
	while(stack1.size() != 1 && stack2.size() != 1)
	{
		int i = 0;
		if(stack1.size() != 0)
		{
			while(stack1.size() > 0)
			{
				int temp = stack1.top();
				stack1.pop();
				if(i % 2 != 0){
					stack2.push(temp);
				}
				i++;
			}
		}
		else
		{
			while(stack2.size() > 0)
			{
				int temp = stack2.top();
				stack2.pop();
				if(i % 2 != 0){
					stack1.push(temp);
				}
				i++;
			}
		}
	}

	return stack1.size() == 0 ? stack2.top() : stack1.top();
}

// faster
int lastRemaining2(int n)
{
	long k;
	if(n == 1){
		return n;
	}
	if(n % 2 == 1)
	{
		k = n-1;
	}
	else
	{
		k = n;
	}

	long sum = k*(k+1)/2, num = k;
	bool flag = false;
	int count = 1;
	while(num > 1)
	{
		if(num % 2 == 1)
		{
			sum = (sum/num)*(num/2);

		}
		else
		{
			if(flag == false)
			{
				sum = (sum + num*count/2)/2;
			}
			else
			{
				sum = (sum - num*count/2)/2;
			}
		}

		count *= 2;
		flag = !flag;
		num /= 2;
	}

	return sum;
}

int main(int argc, char const *argv[])
{

	cout << lastRemaining(100000) << endl;
	cout << lastRemaining2(100000) << endl;
	return 0;
}
