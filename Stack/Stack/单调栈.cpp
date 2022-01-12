#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

const int N = 100010;
//n个数，数组，栈顶指针
int n, stk[N], tt;

int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		int x;
		cin >> x;
		while (tt && stk[tt] > x) //非空且栈里元素大于输入
		{
			tt--;
		}
		if (tt)//栈非空
		{
			cout << stk[tt] << ' ';
		}
		else//栈空
		{
			cout << -1 << ' ';
		}	
		stk[++tt] = x;
	}
	system("pause");
	return 0;
};