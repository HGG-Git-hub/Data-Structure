#include<iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;
int a;
void init() 
{
	head = -1;
	idx = 0;
}
void add_head(int x) 
{
	e[idx] = x;
	ne[idx] = head;
	head = idx++;
}
void add(int k, int x) 
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
}
void remove(int k) 
{
	ne[k] = ne[ne[k]];
}

int main() 
{
	init();

	cin >> a;
	while (a--)
	{
		string op;
		int k, x;
		cin >> op;
		if (op == "H")
		{
			cin >> x;
			add_head(x);
		}
		else if (op == "D") 
		{
			cin >> k;
			if (k==0)
				head = ne[head];
			remove(k-1);
		}
		else 
		{
			cin >> k >> x;
			add(k-1, x);
		}
	}
	for (int i = head; i != -1; i = ne[i]) 
	{
		cout << e[i] << " ";
	}
	system("pause");
	return 0;
};