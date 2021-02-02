#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	BinaryTreeNode* _parent;
};

//�ҳ������������������һ�ڵ�
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;
	BinaryTreeNode* pNext = nullptr;
	if (pNode->_right != nullptr)
	{
		BinaryTreeNode* pRight = pNode->_right;
		while (pRight->_left != nullptr)
		{
			pRight = pRight->_left;
		}
		pNext = pRight;
	}
	else if (pNode->_parent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* parent = pNode->_parent;
		while (parent != nullptr && pCurrent == parent->_right)
		{
			pCurrent = parent;
			parent = parent->_parent;
		}
		pNext = parent;

	}
	return pNext;
}