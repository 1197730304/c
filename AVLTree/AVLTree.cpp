template<class T>
struct AVLTreeNode
{
	
	T _data;
	//左右孩子的指针
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	//父节点指针
	AVLTreeNode<T>* _parent;
	//平衡因子
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
		//空树，创建根节点
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		//搜索
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
		//插入
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		//连接parent指针
		cur->_parent = parent;

		//更新bf因子

		while (parent)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			//判断parent的bf
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else
			{
				//调整搜索树，重新达到平衡
				//左边的左边高
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					//右旋
					RotateR(parent);

				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					//左旋，右边的右边高
					RotateL(parent);
				}
				break;
			}
		}
		return true;


	}
	void RotateR(Node* parent)
	{
		//左子树的根节点
		Node* subL = parent->_left;
		//左子树的右子树的根节点
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		//如果parent为根，则需要进行更新、
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
		
		//更新平衡因子
		pparent->_bf = subL->_bf = 0;

	}


	void RotateL(Node* parent)
	{
		//右子树的根节点
		Node* subR = parent->_right;
		//右子树的左子树的根节点
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		//如果parent为根，则需要进行更新、
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

		//更新平衡因子
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