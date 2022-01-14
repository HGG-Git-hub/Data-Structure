#include<iostream>
using namespace std;

int main()
{
	int x = 4;
	int u = x >> 2 & 1;
	cout << u << endl;

	int a = 1;
	int b = !a;
	cout << b << endl;
	return 0;
};