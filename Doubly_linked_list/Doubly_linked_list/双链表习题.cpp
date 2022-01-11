#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
//	当前值，左边指针，右边指针，下标
int e[N], l[N], r[N], indx;

//初始化链表
void init() 
{
	r[0] = 1, l[1] = 0;
	indx = 2;
}
//下表为k的结点右边插入x
void add(int k, int x) 
{
	e[indx] = x;
	r[indx] = r[k];
	l[indx] = k;
	l[r[k]] = indx;
	r[k] = indx;
	indx++;
}
void remove(int k) 
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}

int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int m;
	cin >> m;

	init();

	while (m--) 
	{
		string op;
		int k, x;
		cin >> op;
		if (op == "L")
		{
			cin >> x;
			add(0, x);
		}
		else if (op == "R") 
		{
			cin >> x;
			add(l[1], x);
		}
		else if (op == "D")
		{
			cin >> k;
			remove(k + 1);
		}
		else if (op == "IL") 
		{
			cin >> k >> x;
			add(l[k + 1], x);
		}
		else
		{
			cin >> k >> x;
			add(k+1, x);
		}
	}

	for (int i = r[0]; i != 1; i = r[i]) 
	{
		cout << e[i] << ' ';	
	}
	cout << endl;

	return 0;
};