//��������1�ĸ���

#include<iostream>
using namespace std;
//�ⷨһ�����ܳ�����ѭ�������,�����������
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


//�ⷨ��������ⷨ
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

//�õĽⷨ

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