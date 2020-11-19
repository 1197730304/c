#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

template<class T>
class Vector
{
public:
	
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{
	}

	//大小
	size_t size()const
	{
		return _finish - _start;
	}

	//容量
	size_t capacity()const
	{
		return _endOfStorage - _start;
	}

	//尾插
	void push_back(const T& val)
	{
		//检查容量
		/*if (_finish == _endOfStorage)
		{
			//增容
			size_t newCapacity = _start == nullptr ? 1 : 2 * capacity();
			reserve(newCapacity);
		}
		//尾插元素
		*_finish = val;
		//更新位置
		++_finish;
		*/

		insert(end(), val);

	}

	void pop_back()
	{
		erase(end() - 1);
	}

	void reserve(size_t n)
	{
		size_t sz = size();
		if (n > capacity())
		{
			//开空间
			T* tmp = new T[n];
			//内容拷贝，浅拷贝
			//memcpy(tmp, _start, size() * sizeof(T));
			for (int i = 0; i < size(); i++)
			{
				tmp[i] = _start[i];
			}
			//释放原有空间
			delete[] _start;
			//更新
			_start = tmp;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	T& operator[](size_t pos)
	{
		//判断pos是否合法
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](size_t pos)const
	{
		//判断pos是否合法
		assert(pos < size());
		return _start[pos];
	}

	//迭代器的实现
	typedef T* iterator;
	typedef const T* const_iterator;
	//非const类型
	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	//const 类型，只能读，不能修改

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	//resize()
	void resize(size_t n,const T& val=T())
	{
		if (n > capacity())
		{
			reserve(n);
		}
		if (n > size())
		{
			//将[size,n]上的值赋为val
			iterator end = _start + n;
			while (_finish != end)
			{
				*_finish = val;
				++_finish;
			}
		}
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		assert(pos >= begin() && pos <= end())
			//获取偏移量
			size_t offset = pos - _start;
		//检查容量
		if (_finish==_endOfStorage)
		{
			size_t newC = _start == nullptr ? 1 : 2 * capacity;
			reserve(newC);
		}
		//增容会导致迭代器失效，更新pos
		pos = offset + _start;
		//元素移动
		iterator it = end();
		while (it != pos)
		{
			*it = *(it - 1);
			it--;
		}

		//插入数据
		*pos = val;

		//更新size
		++_finish;
	}

	//删除某一位置的元素
	iterator erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		iterator it = pos + 1;
		while (it != end())
		{
			*(it - 1) = *it;
			++it;
		}
		--_finish;
		return pos;
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;

		}
	}

private:
	T* _start;//Vector的首元素地址
	T* _finish;//最后一个元素的下一位置
	T* _endOfStorage;//当前元素空间的尾地址


};

void Print(const Vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
int main()
{

}