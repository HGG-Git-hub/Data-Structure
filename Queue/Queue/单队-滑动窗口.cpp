#include<iostream>
using namespace std;
const int N = 100010;
//原数组 单调队列
int a[N], q[N];

int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	//数组长度和滑动窗口的长度
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	//对头，队尾 初始化队列
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i++) 
	{
		//判断整个对头是否在滑动窗口中，如果不在，删除
		if (hh <= tt && q[hh] < i - k + 1)
			hh++;
		/*
		判断一下要插入队尾的元素和已经在队尾的元素大小，
		如果已经在队尾的元素大于要插入队尾的元素，删除后再插入
		*/ 
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			cout << a[q[hh]] << ' ';
	}
	cout << endl;

	//窗口中的最大值
	hh = 0, tt = -1;
	for (int i = 0; i < n; i++) 
	{
		if (hh <= tt && q[hh] < i - k + 1) { hh++; }
		while (hh <= tt && a[q[tt]] <= a[i]) { tt--; }
		q[++tt] = i;
		if (i >= k - 1) { cout << a[q[hh]] << ' '; }
	}
	system("pause");
	return 0;
};