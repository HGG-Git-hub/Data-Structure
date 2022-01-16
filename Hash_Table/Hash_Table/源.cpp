#include<iostream>
using namespace std;

int main() 
{
	int a = -21, b = 2;

	cout << a % b << endl;
	cout << a % b + b << endl;
	cout << (a % b + b) % b << endl;

	return 0;
};