#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

void func1()
{
	int array[10] = { 0 };
	for (int& e : array)
	{
		cin >> e;
	}
	for (int p : array)
	{
		cout << p;
	}
}

//判断大小端字节序
//1.利用联合体
void func3()
{
	union u
     {
	int _a;
	char _c;
     };

	u myunion;
	myunion._a = 1;
	if (myunion._c == 1)
		cout << "littlt end" << endl;
	else
		cout << "big end" << endl;

}

void func2()
{
	int p = 1;
	char* pa = (char*)&p;
	if (*pa == 1)
		cout << "little sort" << endl;
	else
		cout << "big sort" << endl;
}
int main()
{
	//func1();
	cout << "指针强转：\n";
	func2();
	cout << "union result:\n";
	func3();
	return 0;
}

