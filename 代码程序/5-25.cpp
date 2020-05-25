#include<iostream>
#include<stdio.h>
using namespace std;
class Data
{
public:

	int getmonthday(int year, int month)
	{
		int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = array[month];
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)&&month==2)
		{
			day += 1;
		}
		return day;
	}
	Data(int y = 2020, int m = 1, int d = 1)
	{
		if (y <= 0 || m< 1 || m>12 || d <= 0 || d > getmonthday(y, m))
		{
			cout << "数据有误，重置为2020-2-2" << endl;
			_year = 2020;
			_month = 2;
			_day = 2;
		}
		else
		{
			_year = y;
			_month = m;
			_day = d;
		}
	}

	void PrintD()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	//赋值运算符重载
	Data& operator=(const Data& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}


	//拷贝构造
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Data* operator& ()
	{
		return this;
	}

	const Data* operator&()const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test2()
{
	Data d1;
	Data* pd1 = &d1;
	const Data d2;
	const Data* pd2 = &d2;
}

void test1()
{
	Data d1;
	d1.PrintD();
	 Data d2(d1);
	 d2.PrintD();
	Data d3(2001, 3, 3);
	d3.PrintD();
	
}
int main()
{
	//test1();
	test2();
	return 0;
}