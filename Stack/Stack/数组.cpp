#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

//数组模拟栈，下标
int stk[N], tt;
/*
//添加一个元素
stk[ ++ tt] = x;

//删除一个元素
tt--;

//判断栈是否为空
if (tt > 0)
{
	not empty;
}
else
{
	empty;
}

//栈顶元素
stk [tt];
*/

int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) 
	{
		string st;
		cin >> st;
		if (st == "push") //插入元素
		{
			int x;
			cin >> x;
			stk[++tt] = x;
		}
		else if (st == "pop") //删除元素
		{
			tt--;
		}
		else if (st == "query") //查询栈顶元素
		{
			cout << stk[tt] << endl;
		}
		else //查询是否为空
		{
			if (tt)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	system("pause");
	return 0;
};