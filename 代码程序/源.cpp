//#include<iostream>
//#include<stdio.h>
//using namespace std;
//class Data
//{
//public:
//    Data(int year = 1, int month = 1, int day = 1, int data = 0)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//        _data = data;
//    }
//    int getmonthday(int year, int month)
//    {
//        int sum = 0;
//        int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        sum = array[month];
//        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//        {
//            sum += 1;
//        }
//        return sum;
//    }
//
//    void getdate()
//    {
//        _day += _data;
//        while (_day > getmonthday(_year, _month))
//        {
//            _day -= getmonthday(_year, _month);
//            _month++;
//            if (_month == 13)
//            {
//                _month = 1;
//                _year++;
//            }
//        }
//
//    }
//
//    void printd()
//    {
//        if (_month < 10)
//        {
//            if (_day < 10)
//            {
//                cout << _year << "-0" << _month << "-0" << _day << endl;
//            }
//            else
//            {
//                cout << _year << "-0" << _month << "-" << _day << endl;
//            }
//        }
//        else
//            if (_day < 10)
//            {
//                cout << _year << "-" << _month << "-0" << _day << endl;
//            }
//            else
//            {
//                cout << _year << "-" << _month << "-" << _day << endl;
//            }
//
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    int _data;
//};
//
//
//int main()
//{
//    int m, year, month, day;
//    int num = 0;
//    cin >> m;
//    while (m--)
//    {
//        cin >> year >> month >> day >> num;
//        Data p1(year, month, day, num);
//        p1.getdate();
//        p1.printd();
//
//    }
//
//
//    return 0;
//}
//

//#include<iostream>
//#include<stdio.h>
//using namespace std;
//class Data
//{
//public:
//    Data(int year = 2000, int month = 1, int day = 1, int date = 1)
//        :_year(year),
//        _month(month),
//        _day(day),
//        _date(date)
//    {}
//
    //int getmonthday(int year, int month)
    //{
    //    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    //    int num = arr[month];
    //    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
    //    {
    //        num += 1;
    //    }
    //    return num;
    //}
//    void getdata()
//    {
//        _day += _date;
//        while (_day > getmonthday(_year, _month))
//        {
//            _day -= getmonthday(_year, _month);
//            _month++;
//            if (_month == 13)
//            {
//                _month = 1;
//                _year++;
//            }
//
//        }
//    }
//
//
//    void printd()
//    {
//        if (_month < 10)
//        {
//            if (_day < 10)
//            {
//                cout << _year << "-0" << _month << "-0" << _day << endl;
//            }
//            else
//            {
//                cout << _year << "-0" << _month << "-" << _day << endl;
//            }
//        }
//        else
//            if (_day < 10)
//            {
//                cout << _year << "-" << _month << "-0" << _day << endl;
//            }
//            else
//            {
//                cout << _year << "-" << _month << "-" << _day << endl;
//            }
//
//    }
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    int _date;
//};
//
//int main()
//{
//    int year;
//    int date = 0;
//
//    while (1)
//    {    cin >> year >> date;
//        Data p(year, 1, 1, date);
//        p.getdata();
//        p.printd();
//    }
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int getmonthday(int year, int month)
//{
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//     int num = arr[month];
//     if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
//	    {
//	   num += 1;
//	    }
//	   return num;
//}
//
//int main()
//{	int year = 0,month=1,day=1, date = 0;
//	while(scanf("%d%d",&year,&date)!=EOF)
//	{
//		month = 1, day = 1;
//	while (date > getmonthday(year, month))
//	{
//		date -= getmonthday(year, month);
//		month++;
//		if (month == 13)
//		{
//			month = 1;
//			year++;
//		}
//	}
//	printf("%04d-%02d-%02d\n", year, month, date);
// }
//	return 0;
//}
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//bool isleap(int year)
//{
//    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//    {
//        return 1;
//    }
//    else
//        return 0;
//}
//int getmonthday(int year, int month)
//{
//    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int num = arr[month];
//    if (isleap(year) && month == 2)
//    {
//        num += 1;
//    }
//    return num;
//}
//int number(int year, int month, int day)
//{
//    int date = 1;
//    int y = year;
//    for (int i = 0; i < y; i++)
//    {
//        if (isleap(year))
//        {
//            date += 366;
//        }
//        else
//            date += 365;
//    }
//    for (int j = 1; j < month; j++)
//    {
//        date += getmonthday(y, j);
//    }
//    date += day;
//    return date;
//}
//int main()
//{
//    int year1 = 0, month1 = 1, day1 = 1;
//    int year2 = year1, month2 = month1, day2 = day1;
//    int num = 0;
//    while (scanf("%04d%02d%02d", &year1, &month1, &day1) != EOF)
//    {
//        scanf("%04d%02d%02d", &year2, &month2, &day2);
//        int a = number(year1, month1, day1);
//        int b = number(year2, month2, day2);
//        int c = abs(a - b) + 1;
//        cout << c << endl;
//    }
//    return 0;
//}


//#include<iostream>
//#include<stdlib.h>
//#include<stdio.h>
//using namespace std;
//bool isleap(int year)
//{
//    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//    {
//        return 1;
//    }
//    else
//        return 0;
//}
//int getmonthday(int year, int month)
//{
//    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int num = arr[month];
//    if (isleap(year) && month == 2)
//    {
//        num += 1;
//    }
//    return num;
//}
//int iConverDateToDay(int year, int month, int day)
//{
//    int num = 0;
//    int m = month;
//    for (int i = 1; i < m; i++)
//    {
//        num += getmonthday(year, i);
//    }
//    num += day;
//    return num;
//}
//int main()
//{
//    int year = 0, month = 0, day = 0;
//    while (cin >> year >> month >> day)
//    {
//        cout << iConverDateToDay(year, month, day) << endl;
//    }
//}


class Solution {
public:

    class Sum
    {
    public:
        Sum()
        {
            _sum += _num;
            ++_num;
        }
    };
    int Sum_Solution(int n) {
        _sum = 0;
        _num = 1;
        Sum sumarray[n];
        return _sum;
    }
private:
    static int _sum;
    static int _num;
};
int Solution::_sum = 0;
int Solution::_num = 1;

