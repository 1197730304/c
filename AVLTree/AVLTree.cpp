template<class T>
struct AVLTreeNode
{
	
	T _data;
	//���Һ��ӵ�ָ��
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	//���ڵ�ָ��
	AVLTreeNode<T>* _parent;
	//ƽ������
	int _bf;

	AVLTreeNode(const T& val=T())
		:_data(val)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)

	{}

};

template<class T>
class AVLTree
{
public:
	typedef AVLTreeNode<T> Node;

	bool insert(const T& val)
	{
		//�������������ڵ�
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		//����
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data < val)
				cur = cur->_right;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				return false;
		}
		//����
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		//����parentָ��
		cur->_parent = parent;

		//����bf����

		while (parent)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			//�ж�parent��bf
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//��������
				cur = parent;
				parent = parent->_parent;
			}
			else
			{
				//���������������´ﵽƽ��
				//��ߵ���߸�
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					//����
					RotateR(parent);

				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					//�������ұߵ��ұ߸�
					RotateL(parent);
				}
				break;
			}
		}
		return true;


	}
	void RotateR(Node* parent)
	{
		//�������ĸ��ڵ�
		Node* subL = parent->_left;
		//���������������ĸ��ڵ�
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		//���parentΪ��������Ҫ���и��¡�
		Node* pparent = parent->_parent;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;

		}
		else
		{	
			
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		
			subL->_parent = pparent;

		}

		parent->_parent = subL;
		
		//����ƽ������
		pparent->_bf = subL->_bf = 0;

	}


	void RotateL(Node* parent)
	{
		//�������ĸ��ڵ�
		Node* subR = parent->_right;
		//���������������ĸ��ڵ�
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		//���parentΪ��������Ҫ���и��¡�
		Node* pparent = parent->_parent;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;

		}
		else
		{

			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;

			subR->_parent = pparent;

		}

		parent->_parent = subR;

		//����ƽ������
		pparent->_bf = subR->_bf = 0;

	}
private:
	Node* _root = nullptr;
};


void test()
{
	AVLTree<int> avl;
	avl.insert(60);
	avl.insert(30);
	avl.insert(65);
	avl.insert(15);
	avl.insert(20);
	avl.insert(10);
}

int main()
{
	test();
	return 0;
}