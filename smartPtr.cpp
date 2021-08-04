#include<iostream>
#include<mutex>
using namespace std;

struct Date
{
	int _y = 1;
	int _m = 2;
	int _d = 3;
};


template<class T> 
class smartPtr
{
public:
	smartPtr(T* ptr)
		:_ptr(ptr)
	{}


	~smartPtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
		cout << "~smarePtr()" << endl;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

void func()
{
	smartPtr<int> sp(new int);
	smartPtr<Date> sp2(new Date);
	Date d = *sp2;
	int y = sp2->_y;
	y = sp2.operator->()->_y;
	//错误的写法,会释放两次
	//int* p = new int;
	//smartPtr<int> sp2(p);
	//smartPtr<int> sp3(p);
}

template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}

	//拷贝：管理权转移
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}
	//赋值
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
			{
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}
private:
	T* _ptr;
};


template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr)
		:_ptr(ptr)
	{}
	//防拷贝
	UniquePtr(const UniquePtr<T>& up) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>& up) = delete;
	~UniquePtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

private:
	T* _ptr;
	
};


template<class T>
class sharePtr
{
public:
	sharePtr(T* ptr)
		:_ptr(ptr)
		,_countPtr(new size_t(1))
		,_mtx(new mutex)
	{}

	sharePtr(const sharePtr<T>& sp)
		:_ptr(sp._ptr)
		,_countPtr(sp._countPtr)
		,_mtx(sp._mtx)
	{
		addCount();
	}

	sharePtr<T>& operator=(const sharePtr<T>& sp)
	{
		//判断管理的是否同一份资源
		if (_ptr != sp._ptr)
		{
			//计数器自减
			//如果计数器为0，当前对象是最后一个管理资源的对象
			//负责对资源的释放
			if (subCount() == 0)
			{
				delete _ptr;
				delete _countPtr;
				delete _mtx;
			}
			_ptr = sp._ptr;
			_countPtr = sp._countPtr;
			addCount();
		}
		return *this;
	}


	~sharePtr()
	{
		if (subCount()==0)
		{
			delete _ptr;
			delete _countPtr;
			delete _mtx;
			_ptr = nullptr;
			_countPtr= nullptr;
			_mtx = nullptr;
		}
		cout << "~sharePtr()" << endl;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	size_t addCount()
	{
		_mtx->lock();
		++(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}

	size_t subCount()
	{
		_mtx->lock();
		--(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}

private:
	T* _ptr;
	size_t* _countPtr;
	mutex* _mtx;
};


int main()
{

}