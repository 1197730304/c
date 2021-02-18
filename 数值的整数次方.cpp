#include<iostream>
using namespace std;
//Ҫ���ǵ����ֿ���Ϊ��ֵ�����
double PowB(double m, unsigned int n)
{
	double ret=1;
	for (int i = 0; i < n; i++)
	{
		ret *= m;
	}
	return ret;
}

//1.һ��ⷨ
//double Pow(double m, int n)
//{
//	bool flag = false;
//	if (n == 0)
//		return 1;
//	if (n == 1)
//		return m;
//	if (n < 0)
//	{
//		flag = true;
//		n *= -1;
//	}
//	double result = PowB(m, n);
//	if (flag)
//	{
//		result = 1 / result;
//	}
//	return result;
//
//}

//��Ч�ⷨ
double Pow(double m, unsigned int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return m;
	double ret = Pow(m, n >> 1);//n>>1��ʾn/2
	ret *= ret;
	if ((n&0x1)== 1)//��ʾn%2
		ret *= m;
	return ret;
}
int main()
{
	double m;
	int n;
	while (cin >> m >> n)
	{
		cout << Pow(m, n) << endl;
	}
	return 0;
}