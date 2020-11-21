#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

struct Time
{
	Time(int h,int m,int s)
		:_h(h)
		,_m(m)
		,_s(s)
	{}
	int _m = 0;
	int _h = 0;
	int _s = 0;

	bool operator<(const Time& t)const
	{
		if (_h < t._h)
			return true;
		else if(_h==t._h)
		{
			if (_m < t._m)
				return true;
			else if(_m==t._m)
			{
				if (_s < t._s)
					return true;
			}
		}
		return false;
	}
	//����==
	bool operator==(const Time& t)const
	{
		return _h == t._h && _m == t._m && _s == t._s;
	}
	//����>
	bool operator>(const Time& t)const
	{
		return !(*this == t || *this < t);

	}
};
//�������������
ostream& operator<<(ostream& _cout,const Time& t)
{
	_cout << t._h<<"-"<<t._m<<"-"<<t._s<<endl;
	return _cout;
}



void test3()
{
	//�Զ������ͣ�����ѣ�����<
	//priority_queue<Time> pq;
	//��С�ѣ�����>
	priority_queue<Time, vector<Time>, greater<Time>> pq;
	pq.push(Time(18,19,20));
	pq.push(Time(23,24,25));
	pq.push(Time(15,16,18));

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
	cout << endl;

}
//ջû�е�����
template<class T>
class Stack
{
public:
	void push(const T& val)
	{
		_v.push_back(val);
	}

	void pop()
	{
		_v.pop_back();
	}

	T& top()
	{
		return _v.back();
	}


	size_t size()
	{
		return _v.size();
	}
	bool empty()
	{
		return _v.empty();
	}

private:
	vector<T> _v;
};

//ʵ�ֶ���

template<class T>
class Queue
{
public:
	void push(const T& val)
	{
		_li.push_back(val);
	}
	void pop()
	{
		_li.pop_front();
	}

	T& front()
	{
		return _li.front();
	}

	bool empty()
	{
		return _li.empty();
	}

	T& back()
	{
		return _li.back();
	}

	size_t size()
	{
		return _li.size();
	}

private:
	list<T> _li;


};
void test1()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

}

void test()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		//��ͷ����
		st.pop();
	}
	cout << endl;
	
}



void test2()
{	//Ĭ�ϴ��
	//priority_queue<int> pq;
	//�ĳ�С��
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1);
	pq.push(10);
	pq.push(3);
	pq.push(0);
	pq.push(9);

	while ((!pq.empty()))
	{
		//��ȡ�Ѷ�Ԫ��
		cout << pq.top() << " ";
		
		//����Զ�Ԫ��
		pq.pop();
	}
	cout << endl;
}
int main()
{
	test3();
}
/*void test()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

//ʵ����Сջ
template<class T>
class Minstack
{
public:
	Minstack()
	{
	}

	void push(const T& val)
	{
		st.push(val);
		if (minst.empty() || val <= minst.top())
		{
			minst.push(val);
		}
	}

	void pop()
	{
		if (st.top() == minst.top())
		{
			minst.pop();
		}
		st.pop();
	}

	int top()
	{
		return st.top();
	}

	int gettop()
	{
		return minst.top();
	}

	stack<int> st;
	stack<int> minst;

};
int main()
{
	test();
	return 0;
}*/