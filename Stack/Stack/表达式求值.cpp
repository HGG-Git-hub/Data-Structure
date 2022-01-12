#include<iostream>
#include<cstring>
#include<unordered_map>//哈希表
#include<stack>

using namespace std;

stack<int>num;	//存放数字
stack<char>op;	//存放运算符

void eval()
{
	auto b = num.top(); num.pop();
	auto a = num.top(); num.pop();
	auto c = op.top(); op.pop();
	int x;
	if (c == '+')x = a + b;
	else if (c == '-')x = a - b;
	else if (c == '*')x = a * b;
	else x = a / b;
	num.push(x);
}
int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	//定义优先级,+-优先级为一，最小，*/优先级为2
	unordered_map<char, int>pr{ {'+',1},{'-',1},{'*',2},{'/',2} };

	string str;
	cin >> str;//输入(2+2)*(1+1)
	for (int i = 0; i < str.size(); i++) 
	{
		//获取str中当前的值
		auto c = str[i];
		if (isdigit(c)) //isdigit() 用来检测一个字符是否是十进制数字
		{
			//如果是数字
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
			{
				x = x * 10 + str[j++] - '0';//将字符型转换成数字
			}
			//放入num栈中，for循环i要++，因此此处i应该为j - 1
			i = j - 1;
			num.push(x);//获取到的数字放入栈中
		}
		else if (c == '(') op.push(c);
		else if (c == ')') //需要将右括号左边全部的值操作一遍
		{
			while (op.top() != '(') 
			{
				eval();//末尾的运算符操作一下末尾的两个数
			}
			op.pop();
		}
		else 
		{
			//op栈非空且栈顶元素的优先级大于当前元素
			while(op.size() && pr[op.top()] >= pr[c]) 
			{
				eval();
			}
			op.push(c);
		}	
	}
	while (op.size())
	{
		eval();
	}
	cout << num.top() << endl;
	system("pause");
	return 0;
};