#include<iostream>
using namespace std;

const int N = 100010;

int q[N], hh, tt=-1,n;

int main() 
{
	cin >> n;
	while (n--) 
	{
		string str;
		int x;
		if (str == "push")
		{
			cin >> x;
			q[++tt] = x;
		}
		else if (str == "pop")
		{
			hh++;
		}
		else if (str == "query")
		{
			cout << q[hh] << endl;
		}
		else
			cout << (hh <= tt ? "NO" : "YES") << endl;
	}

	system("pause");
	return 0;
};