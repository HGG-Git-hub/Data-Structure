#include<iostream>
using namespace std;

const int N = 100010;

//结点值，指向左边的指针，指向右边的指针，当前用到了哪个结点(指针)
int e[N], l[N], r[N], idx;
//初始化
void init() 
{
	//0表示左端点，1表示右端点
	/*当链表为空的时候，0的右边就是1，1的左边就是0*/
	r[0] = 1, l[1] = 0;
	idx = 2;//0号和1号位置已被占用，从2号位置开始
}
//在下标为k的结点的右边插入x
void add_right(int k, int x) 
{
	e[idx] = x;		//当前结点的元素值
	/*步骤：
	1.先将新结点的左右指针指向指向两边
	2.原来的k结点后面的结点的左指针指向新结点
	3.k结点的右指针指向插入的新结点
	*/
	r[idx] = r[k];	//当前结点的右指针指向k结点右边的结点
	l[idx] = k;		//当前结点的左指针指向k结点
	//注意：下面两个不能搞反！！！
	l[r[k]] = idx;	//原来的k结点后面的结点的左指针指向新结点
	r[k] = idx;		//k结点的右指针指向插入的新结点
}
//删除下标为的k结点
void del(int k) 
{
	l[r[k]] = l[k];	//第k个结点左指针指向的数的右指针指向第k个结点右指针指向的数
	r[l[k]] = r[k];	//第k个结点右指针指向的数的左指针指向第k个结点左指针指向的数
}


int main() 
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);


	system("pause");
	return 0;
};