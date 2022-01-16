#include<iostream>
#include<cstring>
using namespace std;
//数组里的某个位置等于null=0x3f3f3f3f说明数组的这个位置没有数字
const int N = 200003, null = 0x3f3f3f3f;
int h[N];//槽，被映射

int find(int x) 
{
	int k = (x % N + N) % N;
	while (h[k] != null && h[k] != x) //有数据且不等于x
	{
		k++;//看下一个位置
		//k=N,表示已经查完了整个数组，需要从数组0的位置从新开始
		if (k == N) k = 0;
	}
	//k表示如果当前位置有元素返回下个位置的地址
	//当前位置没有元素，返回当前元素位置的地址
	return k;
}

int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	memset(h, 0x3f, sizeof(h));//初始化h数组
	while (n--)
	{
		string s;
		int x;
		cin >> s >> x;
		int k = find(x);
		if (s == "I")
			h[k] = x;
		else
			cout << (h[k] != null ? "Yes" : "No") << endl;
	}
	system("pause");
	return 0;
};