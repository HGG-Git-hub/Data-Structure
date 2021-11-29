#include<iostream>
using namespace std;

const int N = 10010;
//头结点(指针)，节点值，下一个节点的指针，当前用到了哪个结点(指针)
int head, e[N], ne[N],idx;	

//初始化链表
void init() 
{
	head = -1;	//头结点指向空，表示链表为空
	idx = 0;	//表示可以从0号结点开始
}

//------------------单链表的插入操作-------------
//头结点位置插入一个结点
void add_to_head(int x)
{
	//当前结点存储数据x
	e[idx] = x;
	//将头结点指针的指向给新加入的结点，新加入的结点成为了0号结点
	ne[idx] = head;	
	//将头结点head指针指向idx
	head = idx;
	//idx指向下一个可以使用的结点
	idx++;
}
//插到k结点的后面
void add(int k, int x)
{
	//2 5 6		8 9
	//0 1 k	 	. .

	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}

//------------------单链表的删除操作-------------
//删除下标为k后面的结点
void del(int k) 
{
	ne[k] = ne[ne[k]];
}

int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	

	system("pause");
	return 0;
};