//#include<iostream>
//#include<time.h>
//using namespace std;
//
//template<class T>
//struct BSTNode
//{
//	T _data;
//	BSTNode<T>* _left;
//	BSTNode<T>* _right;
//
//	BSTNode(const T& val = T())
//		:_data(val)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template<class T>
//class BSTree
//{
//public:
//	typedef BSTNode<T> Node;
//
//	Node* find(const T& val)
//	{
//		if (_root == nullptr)
//			return nullptr;
//		//从根节点开始搜索
//		Node* cur = _root;
//		while (cur)
//		{
//			//如果找到就返回
//			if (cur->_data == val)
//			{
//				cout << "success!" << endl;
//				return cur;
//			}
//			else if (cur->_data > val)
//				cur = cur->_left;
//			else
//				cur = cur->_right;
//		}
//
//		cout << "failed!" << endl;
//		return nullptr;
//	}
//
//	//插入
//	bool insert(const T& val)
//	{
//		Node* cur = _root;
//		Node* parent = nullptr;
//		//如果根节点为空，则创建根节点
//		if (_root == nullptr)
//		{
//			_root= new Node(val);
//			return true;
//		}
//
//		while (cur)
//		{
//			parent = cur;
//			if (cur->_data == val)
//				return false;
//			else if (val < (cur->_data))
//			{
//				cur = cur->_left;
//			}
//			else
//				cur = cur->_right;
//		}
//		cur = new Node(val);
//		//判断新节点在父节点的那一边
//		if (parent->_data > val)
//			parent->_left = cur;
//		else
//			parent->_right = cur;
//		return true;
//	}
//	void _inorder(Node* root)
//	{
//		if (root)
//		{
//			_inorder(root->_left);
//			cout << root->_data << " ";
//			_inorder(root->_right);
//		}
//	}
//	void inorder()
//	{
//		_inorder(_root);
//		cout << endl;
//	}
//
//private:
//	Node* _root = nullptr;
//
//};
//
//void test()
//{
//	srand((unsigned int)time(NULL));
//	cout << "插入的数字个数：" << endl;
//	int n;
//	cin >> n;
//	BSTree<int> bt;
//	for (int i = 0; i < n; i++)
//	{
//		bt.insert(rand());
//	}
//	cout << "中序遍历：" << endl;
//	bt.inorder();
//	cout << "请输入你要查找的数:" << endl;
//	int m;
//	cin >> m;
//	bt.find(m);
//
//}
//
//void func()
//{
//	BSTree<int> bt;
//	bt.insert(15);
//	bt.insert(10);
//	bt.insert(11);
//	bt.insert(1);
//	bt.insert(5);
//	bt.insert(7);
//	bt.insert(12);
//	bt.inorder();
//	bt.find(15);
//}
//
//
//
//int main()
//{
//	test();
//	//func();
//	return 0;
//}
