//删除链表的节点
//struct ListNode
//{
//	int _value;
//	ListNode* _pNext;
//};
//
//void DeleteNode(ListNode** pListHead, ListNode* del)
//{
//	if (!pListHead || !del)
//		return;
//	//要删除的节点不是尾结点
//	if (del->_pNext != nullptr)
//	{
//		ListNode* next = del->_pNext;
//		del->_value = next->_value;
//		del->_pNext = next->_pNext;
//
//		delete next;
//		next = nullptr;
//	}
//	//链表只有一个节点，删除头节点（尾结点）
//	else if (*pListHead == del)
//	{
//		delete del;
//		del = nullptr;
//		*pListHead = nullptr;
//	}
//	//链表中有多个节点，删除尾结点
//	else
//	{
//		ListNode* pNode = *pListHead;
//		while (pNode->_pNext != del)
//		{
//			pNode = pNode->_pNext;
//
//		}
//		pNode->_pNext = nullptr;
//		delete del;
//		del = nullptr;
//	}
//}