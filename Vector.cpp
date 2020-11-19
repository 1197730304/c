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

	//��С
	size_t size()const
	{
		return _finish - _start;
	}

	//����
	size_t capacity()const
	{
		return _endOfStorage - _start;
	}

	//β��
	void push_back(const T& val)
	{
		//�������
		/*if (_finish == _endOfStorage)
		{
			//����
			size_t newCapacity = _start == nullptr ? 1 : 2 * capacity();
			reserve(newCapacity);
		}
		//β��Ԫ��
		*_finish = val;
		//����λ��
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
			//���ռ�
			T* tmp = new T[n];
			//���ݿ�����ǳ����
			//memcpy(tmp, _start, size() * sizeof(T));
			for (int i = 0; i < size(); i++)
			{
				tmp[i] = _start[i];
			}
			//�ͷ�ԭ�пռ�
			delete[] _start;
			//����
			_start = tmp;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	T& operator[](size_t pos)
	{
		//�ж�pos�Ƿ�Ϸ�
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](size_t pos)const
	{
		//�ж�pos�Ƿ�Ϸ�
		assert(pos < size());
		return _start[pos];
	}

	//��������ʵ��
	typedef T* iterator;
	typedef const T* const_iterator;
	//��const����
	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	//const ���ͣ�ֻ�ܶ��������޸�

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
			//��[size,n]�ϵ�ֵ��Ϊval
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
			//��ȡƫ����
			size_t offset = pos - _start;
		//�������
		if (_finish==_endOfStorage)
		{
			size_t newC = _start == nullptr ? 1 : 2 * capacity;
			reserve(newC);
		}
		//���ݻᵼ�µ�����ʧЧ������pos
		pos = offset + _start;
		//Ԫ���ƶ�
		iterator it = end();
		while (it != pos)
		{
			*it = *(it - 1);
			it--;
		}

		//��������
		*pos = val;

		//����size
		++_finish;
	}

	//ɾ��ĳһλ�õ�Ԫ��
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
	T* _start;//Vector����Ԫ�ص�ַ
	T* _finish;//���һ��Ԫ�ص���һλ��
	T* _endOfStorage;//��ǰԪ�ؿռ��β��ַ


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