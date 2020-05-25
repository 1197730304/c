#include<iostream>
#include<stdio.h>
using namespace std;

class Date
{
public:   
	int GetMonthDay(int year, int month)
	{
		int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int Day = day[month];
		if (((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)&&month==2)
		{
			Day++;
		}
		return Day;
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year > 0 && month > 0 && month < 13 && day>0 && day < GetMonthDay(year, month))
		{
		_Year = year;
		_Month = month;
		_Day = day;
		}
		else
		{
			cout << "参数错误:" << endl;
			cout << "参数重置为2000-01-01" << endl;
			_Year = 2000;
			_Month = 1;
			_Day = 1;
		}

	}

//拷贝构造函数
	Date(const Date& d)
	{
		_Year = d._Year;
		_Month = d._Month;
		_Day = d._Day;

	}
//赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
		_Year = d._Year;
		_Month = d._Month;
		_Day = d._Day;
		}
		return *this;
	}


	~Date()
	{
		//cout << "~Date"<<endl;

	}

//  +=
	Date& operator+=(int day)
	{
		_Day += day;
		while (_Day > GetMonthDay(_Year, _Month))
		{
			_Day -= GetMonthDay(_Year, _Month);
			_Month++;
			if (_Month==13)
			{
				_Month =1;
				_Year++;

			}
		}
		return *this;
	}

//日期+ 天数
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}


	Date operator-(int day)
	{
		Date ret=*this;
		ret -= day;
		return ret;
	}

	//-=
	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;

		_Day -= day;
		while (_Day < 0)
		{
			_Month--;
			if (_Month == 0)
				{
					_Month = 12;
					_Year--;
				}
			_Day += GetMonthDay(_Year, _Month);
		}
		return *this;
	}


	// 前置++
	Date& operator++()
	{
		return *this +=1;
		//return (*this).operator+=(1);
	}
	//后置++
	Date operator++ (int)
	{
		Date p(*this);
		*this += 1;
		return p;
	}


	// 后置--
	Date operator--(int)
	{
		Date p2(*this);
		*this -= 1;
		return p2;
	}

	// 前置--

	Date& operator--()
	{
		return *this -= 1;
		//return (*this).operator-=(1);
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		return (_Year > d._Year) || (_Year == d._Year && _Month > d._Month) ||
			(_Year == d._Year && _Month == d._Month && _Day > d._Day);
	}


	// ==运算符重载

	bool operator==(const Date& d)
	{
		return (_Year == d._Year && _Month == d._Month && _Day == d._Day);
	}

	// >=运算符重载

	inline bool operator >= (const Date& d)
	{
		//return (_Year >= d._Year) || (_Year == d._Year && _Month >= d._Month) ||
		//	(_Year == d._Year && _Month == d._Month && _Day >= d._Day);
		return (*this > d)||(*this==d);
	}


	bool operator < (const Date& d)
	{
		//return (_Year < d._Year) || (_Year == d._Year && _Month < d._Month) ||
		//	(_Year == d._Year && _Month == d._Month && _Day < d._Day);
		return !((*this > d)|| (*this == d));
	}


	bool operator <= (const Date& d)
	{
		//return (_Year <= d._Year) || (_Year == d._Year && _Month <= d._Month) ||
		//	(_Year == d._Year && _Month == d._Month && _Day <= d._Day);
		return (*this < d || *this == d);
	}

	bool operator != (const Date& d)
	{
		return !(_Year == d._Year && _Month == d._Month && _Day == d._Day);
	}


	int operator-(const Date& d)
	{
		int day = 0;
		Date cur = *this;
		if (cur > d)
		{
			while (cur > d)
			{
				day++;
				cur--;
			}
		}
		else
		{
			while (cur < d)
			{
				day--;
				cur++;
			}
		}
		return day;
	}


void printD()
{
	cout << _Year << " " << _Month << " " << _Day << endl;
}

private:
	int _Year;
	int _Month;
	int _Day;
};

void test1()
{
	Date d1(2020, 1, 20);
	Date d2(2021, 1, 30);
	Date d3(2020, 1, 25);
	cout << (d1 <= d2) << endl;
	cout << (d3 > d2) << endl;
}

void test2()
{
	Date p1(2012, 1, 20);
	Date p2(2011, 12, 25);
	Date p3 = p1 - 40;
	cout << (p1 - p3) << endl;
	cout << (p3 - p1) << endl;
}
void test()
{
	Date p1(2020, 1, 20);
	//p1.operator+(50);
	Date p2 = p1 + 20;
	p2.printD();
	p2 = p1 - 20;
	p2.printD();
	Date p4(2020, 12, 20);
	int ret = p1 - p4;
	cout << ret << endl;
	(++p1).printD();
	(p1--).printD();
	(p1++).printD();
	(--p1).printD();
	Date p3=p1 ;
	
	cout << p1.operator>=(p3) << endl;
	//p1.printD();
	//p1.printD();
}

int main()
{
	//test1();
	test2();
	return 0;
}