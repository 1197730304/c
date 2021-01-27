//#include<utility>
#include<vector>
#include<iostream>
using namespace std;
//��ɢ�У�����̽��

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
	//����
	bool insert(const pair<k, v>& kv)
	{
		//ͨ����������λ��
		int idx = kv.first % _ht.size();
		//�жϵ�ǰλ���Ƿ�Ϊ�գ���Ϊ������
		while (_ht[idx]._state != EMPTY)
		{
			
			//�жϼ�ֵ�Ƿ����
			if (_ht[idx]._state == EXIST && _ht[idx]._kv.first == kv.first)
				return false;

			++idx;

			//�ж��Ƿ�Խ��
			if (idx == _ht.size())
			{
				idx = 0;
			}

		}
		//Ϊ��ֱ�Ӳ���
			_ht[idx]._kv = kv;
			_ht[idx]._state = EXIST;
			++_size;
			return true;
	}
	void checkCapacity()
	{
		//�������ӣ�Ԫ�ظ���/�ռ��С

		if (_size == 0||_size * 10 / _ht.size() >= 7)
		{
			//����
			int newC = _ht.size() == 0 ? 5 : 2 * _ht.size();
			HashTable<k, v> newHT(newC);
			
			//���²���
			for (int i = 0; i < _ht.size(); i++)
			{
				if (_ht[i]._state == EXIST)
				{
					newHT.insert(_ht[i]._kv);
				}
			}
			//�����±�����
			swap(_ht, newHT._ht);

		}
	}

	//����
	Node* find(const k& key)
	{
		//����λ��
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
	size_t _size;//��ʾʵ��Ԫ�صĸ���
};
