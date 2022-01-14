#include<iostream>
#include<algorithm>
using namespace std;
const int M = 100010, N = 10010;
char s[M], p[N];
int n, m;

int ne[N];
int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> n >> p + 1 >> m >> s + 1;
	//求net的过程
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && p[i] != p[j + 1]) 
			j = ne[j];
		if (p[i] == p[j + 1]) 
			j++;
		ne[i] = j;
	}
	//kmp匹配过程
	for (int i = 1, j = 0; i <= m; i++) 
	{
		while (j && s[i] != p[j + 1]) 
			j = ne[j];
		if (s[i] == p[j + 1]) 
			j++;
		if (j == n) 
		{
			cout << i - n << " ";
			j = ne[j];
		}
	}
	system("pause");
	return 0;
};