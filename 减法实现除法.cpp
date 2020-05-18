#include<stdio.h>
#include<iostream>
using namespace std;

//用减法实现除法
double Divide(double x, double y,int count)
{
	if (y == 0 || x == 0)
		return 0;
	double ax = abs(x);
	double ay = abs(y);
	double ret = 0;
	int i;
	for ( i=0; ax >=ay; ax -= ay)
	{
		i++;
	}
	ret = i;
	double p = 0;
	if (ax>0&&count>0)
	{
		double re = ax * 10;
		count--;
	    p=Divide(re, ay,count-1);
		p *= 0.1;
	}
	ret += p;
	
	return (x>0&&y<0)||(x<0&&y>0)==1?-ret:ret;

}
int main()
{
	double x, y;
	cout << "请输入除数：\n";
	cin >> x;
	cout << "请输入被除数：\n";
	cin >> y;
	double ret = Divide(x, y, 30);
	cout << ret << endl;
	return 0;
}

