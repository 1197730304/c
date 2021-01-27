//#include<utility>
#include<vector>
#include<iostream>
using namespace std;
//闭散列：线性探测

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

template<class k,class v>
struct Node
{
	pair<k, v> _kv=pair<k,v>();
	State _state = EMPTY;
};

template<class k, class v>
class HashTable
{
public:
	typedef HashTable<k, v> Node;
	HashTable(size_t n=5)
		:_size(0)
	{
		_ht.resize(n);
	}
	//插入
	bool insert(const pair<k, v>& kv)
	{
		//通过函数计算位置
		int idx = kv.first % _ht.size();
		//判断当前位置是否为空，不为空搜索
		while (_ht[idx]._state != EMPTY)
		{
			
			//判断键值是否存在
			if (_ht[idx]._state == EXIST && _ht[idx]._kv.first == kv.first)
				return false;

			++idx;

			//判断是否越界
			if (idx == _ht.size())
			{
				idx = 0;
			}

		}
		//为空直接插入
			_ht[idx]._kv = kv;
			_ht[idx]._state = EXIST;
			++_size;
			return true;
	}
	void checkCapacity()
	{
		//负载因子：元素个数/空间大小

		if (_size == 0||_size * 10 / _ht.size() >= 7)
		{
			//扩容
			int newC = _ht.size() == 0 ? 5 : 2 * _ht.size();
			HashTable<k, v> newHT(newC);
			
			//重新插入
			for (int i = 0; i < _ht.size(); i++)
			{
				if (_ht[i]._state == EXIST)
				{
					newHT.insert(_ht[i]._kv);
				}
			}
			//交换新表内容
			swap(_ht, newHT._ht);

		}
	}

	//搜索
	Node* find(const k& key)
	{
		//计算位置
		int idx = key % _ht.size();
		while (_ht[idx]._state != EMPTY)
		{
			if (_ht[idx]._state == EXIST&&_ht[idx]._kv.first==key)
			{
				return _ht[idx];
			}
			++idx;
			if (idx == _ht.size())
				idx = 0;
		}
		return nullptr;
	}

	bool erase(const k& key)
	{
		Node* node = find(key);
		if (node)
		{
			node->_state == DELETE;
			--_size;
			cout << key << "delete success!" << endl;
			return true;
		}
		return false;
	}

private:
	vector<Node> _ht;
	size_t _size;//表示实际元素的个数
};
