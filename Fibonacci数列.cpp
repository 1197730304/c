#include<iostream>
using namespace std;

//1.��һ�ֵݹ鷽��
//int Fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	if (n > 2)
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}


//�ڶ��ַǵݹ�
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


//������̨������,һ��ֻ����1�ڻ���2��

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

//������̨������,һ������1��2��3....n��̨��
//�������ݹ��ɷ����Եó����ۣ�f(n)=2^(n-1);



