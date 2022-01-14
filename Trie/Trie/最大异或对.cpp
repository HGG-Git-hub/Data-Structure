#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010, M = 3000000;

int son[M][2];//N行2列，即每行有2个数字 0或1
int idx;//当前用到的下标，下标是0的点，既是根结点，又是空结点
int n, a[N];
//将每一个数看成二进制数
/*从二进制的每一个最高位开始依次放入tire树中*/
void insert(int x) 
{
	int p = 0;
	//从30开始：默认一个数的二进制位最多有30位
	for (int i = 30; ~i; i--) //i>=0等价于~i 取反i
	{
		/*
		x >> i：是指x的二进制数向右移动i位，例如10010 >> 2得100
		注意：二进制位是从0开始
		x >> i & 1：移动后的第i位二进制数是0或1
		0 & 0 = 0
		0 & 1 = 0
		1 & 0 = 0
		1 & 1 = 1
		*/
		int& s = son[p][x >> i & 1];
		if (!s) 
			s = ++idx;
		p = s;
	}
}
int query(int x) 
{
	int res = 0, p = 0;
	for (int i = 30; ~i; i--)//从30开始：默认一个数的二进制位最多有30位， 
	{
		int s = x >> i & 1;
		if (son[p][!s])
		{
			res += 1 << i;
			p = son[p][!s];
		}
		else p = son[p][s];
	}
	return res;
}
int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	cin >> n;//3
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];//1 2 3
		insert(a[i]);
	}
	int res = 0;
	for (int i = 0; i < n; i++) 
		res = max(res, query(a[i]));
	cout << res << endl;
	
	system("pause");
	return 0;
};