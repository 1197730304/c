//二进制中1的个数

#include<iostream>
using namespace std;
//解法一，可能出现死循环的情况,负数的情况下
//int Number(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n & 1 == 1)
//			count++;
//		n=n >> 1;
//	}
//	return count;
//}


//解法二：常规解法
//int Number(int n)
//{
//	int count = 0;
//	unsigned int tmp = 1;
//	while (tmp)
//	{
//		if (n & tmp)
//		{
//			count++;
//		}
//		tmp=tmp << 1;
//		
//	}
//	return count;
//}

//好的解法

//int Number(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = (n - 1) & n;
//
//	}
//	return count;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << Number(n) << endl;
//	}
//	return 0;
//}