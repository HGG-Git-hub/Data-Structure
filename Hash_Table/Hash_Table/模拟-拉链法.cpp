#include<iostream>
#include<algorithm>
#include<cstring>//memset
using namespace std;
const int N = 100003;//哈希表中一般取质数

int h[N];//槽，被映射
int idx; //表示当前位置
int e[N], ne[N];//链表，一个存放数据，一个存放下一个节点的位置
//将x插入
void insert(int x) 
{
	//k为哈希值
	int k = (x % N + N) % N;//实现无论x正负得到k的值都为整数
	//链表的插入操作
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}
//查找x是否存在
bool find(int x) 
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i]) 
	{
		if (e[i] = x)
			return true;
	}
	return false;
}
int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	memset(h, -1, sizeof h);//memset初始化函数,-1表示空指针
	while (n--) 
	{
		string s;
		int x;
		cin >> s >> x;
		if (s == "I")
			insert(x);
		else
			cout << (find(x) ? "Yes" : "No") << endl;
	}
	system("pause");
	return 0;
};