#include<iostream>
using namespace std;

const int N = 100010;

int n,m;
int p[N];//存储每个节点的父节点

int find(int x) //返回x所在集合的编号，即根节点，包含了路径优化
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m;
	/*最开始，每一个元素都是一个集合，对应在树中，即只有根节点
	根节点也是自己，即p[i]=[i];*/
	for (int i = 1; i <= n; i++) p[i] = i;
	while (m--) 
	{
		char op[2];
		int a, b;
		cin >> op >> a >> b;
		if (op[0] == 'M') //合并操作
			p[find(a)] = find(b);
		else 
			cout << (find(a) == find(b) ? "Yes" : "No") << endl;
	}
	system("pause");
	return 0;
};