#include<iostream>
using namespace std;
//要考虑到数字可能为负值的情况
double PowB(double m, unsigned int n)
{
	double ret=1;
	for (int i = 0; i < n; i++)
	{
		ret *= m;
	}
	return ret;
}

//1.一般解法
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

//高效解法
double Pow(double m, unsigned int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return m;
	double ret = Pow(m, n >> 1);//n>>1表示n/2
	ret *= ret;
	if ((n&0x1)== 1)//表示n%2
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