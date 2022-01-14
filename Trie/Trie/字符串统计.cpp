#include<iostream>
using namespace std;

const int N = 100010;
		  
int son[N][26];//N行26列，即每行有26个数字

int cnt[N];//以当前结点结尾的单词有多少个
int idx;//当前用到的下标，下标是0的点，既是根结点，又是空结点

char str[N];

//插入操作
void insert(char str[]) 
{
	int p = 0;//表示根节点
	for (int i = 0; str[i]; i++) 
	{
		/*a-z的acsll码是97-122，需要映射成0-25，减去'a'即可*/
		int u = str[i] - 'a';//保存当前子结点的编号
		if (!son[p][u]) //表示p结点没有u子结点，
		{
			son[p][u] = ++idx;
		}
		p = son[p][u];
	}
	cnt[p]++;//以当前结点结尾的单词加一
}
//查询操作
int query(char str[]) 
{
	int p = 0;
	for (int i = 0; str[i]; i++) 
	{
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;//不存在返回0
		p = son[p][u];
	}
	return cnt[p];
}
int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) 
	{
		char op[2];
		cin >> op >> str;
		if (op[0] == 'I')
			insert(str);
		else
			cout << query(str) << endl;
	}
	system("pause");
	return 0;
};