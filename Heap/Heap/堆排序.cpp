#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int n, m;
//数组存放堆的元素，size表示当前数组有多少元素
int h[N], Size;

void down(int u) 
{
	//t表示一个节点和它的左右两个节点最小值的节点编号
	int t = u;
	if (u * 2 < Size && h[u * 2] < h[t])
		t = u * 2;
	if (u * 2 + 1 < Size && h[u * 2 + 1] < h[t])
		t = u * 2 + 1;
	if (u != t) 
	{
		swap(h[u], h[t]);
		down(t);
	}
}
void up(int x) 
{
	while (x / 2 && h[x / 2] > h[x]) 
	{
		swap(h[x / 2], h[x]);
		x /= 2;
	}
}
int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	Size = n;
	for (int i = n / 2; i; i--) 
		down(i);
	while (m--) 
	{
		cout << h[1]<<' ';	//输出堆顶元素
		h[1] = h[Size]; //堆的最后一个元素将丢顶元素覆盖
		Size--;
		down(1);
	}
	system("pause");
	return 0;
};