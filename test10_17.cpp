#include<iostream>
using namespace std;
class Date

{

public:

	// ��ȡĳ��ĳ�µ�����

	int GetMonthDay(int year, int month)
	{
		int arr[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 4 == 0 && year % 100 == 0) || year % 400 == 0)
		{
			return arr[month - 1];
		}
		else
		{
			if (month == 2)
				return arr[1] - 1;
			else
				return arr[month - 1];
		}
	}

	// ȫȱʡ�Ĺ��캯��

	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 1900 || month < 1 || month>12 || day<1 || day>GetMonthDay(year,month))
		{
			cout << "�Ƿ�����" << endl;
		}
		_year = year;
		_month = month;
		_day = day;
	}



	// �������캯��

  // d2(d1)

	Date(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}



	// ��ֵ���������

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}



	// ��������

	~Date()
	{
		cout << "~Date()" << endl;
	}



	// ����+=����

	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;

			}
		}
		return *this;
	}



	// ����+����

	Date operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
	}



	// ����-����

	Date operator-(int day)
	{
		Date tmp(*this);
		tmp -= day;
		return tmp;
	}



	// ����-=����

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
		
	}



	// ǰ��++

	Date& operator++()
	{
		return *this += 1;
	}



	// ����++

	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}



	// ����--

	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;

	}



	// ǰ��--

	Date& operator--()
	{
		return *this -= 1;
	}

	// >���������

	bool operator>(const Date& d)
	{
		if (_year < d._year)
			return false;
		else if(_year==d._year)
		{
			if (_month < d._month)
				return false;
			else if (_month == d._month)
			{
				if (_day <= d._day)
					return false;
			}
			else
				return true;
		}
		return true;
	}



	// ==���������

	bool operator==(const Date& d)
	{
		return (_year == d._year && _month == d._month && _day == d._day);
	}



	// >=���������

	inline bool operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	}



	// <���������

	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}



	// <=���������

	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}



	// !=���������

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}



	// ����-���� ��������

	int operator-(const Date& d)
	{
		Date tmp(*this);
		int count = 0, flag = 1;
		Date max = *this;
		Date min = d;
		if (max < min)
		{
			Date t = max;
			max = min;
			min = t;
			flag = -1;
		}
		while (min<max)
		{
			min++;
			count++;
			
		}
		return count*flag;
	}

private:

	int _year;

	int _month;

	int _day;

};


int main()
{
	return 0;
}