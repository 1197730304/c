#include<iostream>
using namespace std;

//1.第一种递归方法
//int Fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	if (n > 2)
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}


//第二种非递归
//long long Fibonacci(int n)
//{
//	long long int sum = 0;
//	long long int a = 1, b = 1;
//	if (n == 1 || n == 2)
//		return 1;
//	else
//	{
//		for (int i = 3; i <= n; i++)
//		{
//			sum = a + b;
//			a = b;
//			b = sum;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << Fibonacci(n) << endl;
//	}
//
//	return 0;
//}


//青蛙跳台阶问题,一次只能跳1节或者2节

//int Func(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 2;
//	else
//		return Func(n - 1) + Func(n - 2);
//
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << Func(n) << endl;
//	}
//}

//青蛙跳台阶问题,一次能跳1、2、3....n节台阶
//根据数据归纳法可以得出结论：f(n)=2^(n-1);



