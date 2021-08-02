#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

class Date
{
public:
	Date(int y, int m, int d)
		:_y(y)
		,_m(m)
		,_d(d)
	{
	}

	bool operator<(const Date& date)const
	{
		if (_y < date._y)
			return true;
		else if (_y == date._y)
		{
			if (_m < date._m)
				return true;
			else if (_m == date._m)
			{
				if (_d < date._d)
					return false;

			}
		}
		return false;
	}
private:
	int _y;
	int _m;
	int _d;
};

struct cmp
{
	bool operator()(const Date& d1, const Date& d2)
	{
		return d1 < d2;
	}
};

void test()
{
	vector<Date> v;
	v.push_back(Date(2011, 1, 1));
	v.push_back(Date(2012, 11, 1));
	v.push_back(Date(2021, 12, 21));
	v.push_back(Date(2001, 4, 21));
	v.push_back(Date(2004, 7, 20));
	
	//sort(v.begin(), v.end(),less<Date>());
	//sort(v.begin(), v.end(), cmp());

}
int main()
{

	return 0;
}