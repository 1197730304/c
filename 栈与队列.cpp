#include<iostream>
//#include<stack>
#include<queue>
using namespace std;

//用两个栈实现队列
//实现尾插与头删
//template<class T>
//
//class Queue
//{
//public:
//	Queue()
//	{}
//
//	~Queue()
//	{}
//
//	void push(const T& node)//尾插
//	{
//		st1.push(node);
//	}
//	T pop()//头删
//	{
//		if (st2.empty())
//		{
//			while (!st1.empty())
//			{
//				st2.push(st1.top());
//				st1.pop();
//			}
//		}
//		if (st2.empty())
//			throw new exception("queue is empty");
//		T head = st2.top();
//		st2.pop();
//		return head;
//	}
//	
//private:
//	stack<T> st1;
//	stack<T> st2;
//};


//队列实现栈

template<class T>
class Stack
{
public:
	Stack()
	{}

	~Stack()
	{}

	void push(const T& node)
	{
		q1.push(node);
	}

	T pop()
	{
		if (q2.empty())
		{
			while(q1.size()!=1)
			{
				T tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
		}
		T top = q1.front();
		q1.pop();
		return top;
	}




private:
	queue<T> q1;
	queue<T> q2;
	
};