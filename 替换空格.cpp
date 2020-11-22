#include<iostream>
#include<string>
#include<stack>
using namespace std;

//void Replace(string& str)
//{
//	string str2;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ' ')
//		{
//			str.replace(i, 1, "%20");
//		}
//	}
//}

//string ReplaceBlank(string str)
//{
//	int i = 0, len = 0, blank = 0;
//	while (str[i] != '\0')
//	{
//		if (str[i] == ' ')
//		{
//			blank++;
//		}
//		else
//			len++;
//		i++;
//	}
//	 string str2(len + 3 * blank,0);
//	 int j = 0, k = 0;
//	 while(k<str.length())
//	{
//		if (str[k] != ' ')
//		{
//			str2[j++] = str[k];
//			
//		}
//		else
//		{
//			str2[j++] = '%';
//			
//			str2[j++] = '2';
//			
//			str2[j++] = '0';
//			
//		}
//		k++;
//	}
//	
//	return str2;
//}
//int main()
//{
//	string str("We are happy");
//	cout << str << endl;
//	//Replace(str);
//	cout << ReplaceBlank(str) << endl;
//	cout << str << endl;
//	return 0;
//}

//将链表反向打印出来而不修改链表的结构

//方法一：常规思路用栈进行实现
//struct ListNode
//{
//	int key;
//	ListNode* m_pnext;
//};
//
//void Print_Reverse(ListNode* pHead)
//{
//	stack<ListNode*> st;
//	ListNode* cur = pHead;
//	while (cur)
//	{
//		st.push(cur);
//		cur = cur->m_pnext;
//	}
//	
//	while (!st.empty())
//	{
//		cout << st.top()->key;
//		st.pop();
//	}
//	cout << endl;
//}


//方法二：采用递归方法进行

//void Print_Reverse(ListNode* pHead)
//{
//	if (pHead != nullptr)
//	{
//		if (pHead->m_pnext != nullptr)
//		{
//			Print_Reverse(pHead->m_pnext);
//		}
//		else
//			cout << pHead->key;
//	}
//	cout << endl;
//}


//二叉树的建树

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _Date;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
//{
//	if (a[*pi] != '#')
//	{
//		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
//		root->_Date = a[*pi];
//		(*pi)++;
//		root->left = BinaryTreeCreate(a, pi);
//		(*pi)++;
//		root->right = BinaryTreeCreate(a, pi);
//		return root;
//	}
//	else
//		return NULL;
//}

//判断二叉树的中序遍历时的下一个节点
//第一种情况：当当前节点有右子树时，下一节点为右子树的最左节点
//第二种情况：当没有右子树且为父节点的右子树时，此时必须向上遍历，直到找到不为父节点的右子树时，下一个节点就是父节点

//BinaryTreeNode* getNext(BinaryTreeNode* pHead)
//{
//	if (pHead == NULL)
//		return NULL;
//	BinaryTreeNode* next = nullptr;
//	if (pHead->right != nullptr)
//	{
//		BinaryTreeNode* p_right = pHead->right;
//		while (p_right)
//		{
//			p_right = p_right->left;
//		}
//		return p_right;
//	}
//	else if (pHead->parent != nullptr)
//	{
//		BinaryTreeNode* cur = pHead;
//		BinaryTreeNode* cur_parent = pHead->parent;
//		while (cur_parent->left != cur)
//		{
//			cur = cur_parent;
//			cur_parent = cur_parent->parent;
//		}
//		return cur_parent;
//	}
//
//}


//用两个栈实现队列
//template<class T> class CQueue
//{
//public:
//	CQueue(void);
//	~CQueue(void);
//	
//	void appendTail(const T& node);
//	T deleteHead();
//private:
//	stack<T> st1;
//	stack<T> st2;
//};
// 
//template<class T> void CQueue<T>::appendTail(const T& node)
//{
//	st1.push(node);
//}
//
//template<class T> T CQueue<T>::deleteHead()
//{
//	if (st2.empty())
//	{
//		while (!st1.empty())
//		{
//			st2.push(st1.top());
//			st1.pop();
//		}
//	}
//	if (st2.empty())
//		throw new exception("queue is empty");
//
//	T data = st2.top();
//	st2.pop();
//	return data;
//}

//斐波那契数列
//1 1 2 3 5 8 13 21 34 55 89
long long fabonaci(int n)
{
	long long sum;
	int arr[2] = { 0,1 };
	if (n < 2)
	{
		return arr[n];
	}
	else
	{
		long long one = 0;
		long long two = 1;
		long long rt = 0;
		for (int i = 2; i <= n; i++)
		{
			rt = one + two;
			one = two;
			two = rt;

		}
		return rt;
	}

}
int main()
{
	int n;
	cin >> n;
	long long ret = fabonaci(n);
	cout << ret << endl;
	return 0;
}