//ɾ������Ľڵ�
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
//	//Ҫɾ���Ľڵ㲻��β���
//	if (del->_pNext != nullptr)
//	{
//		ListNode* next = del->_pNext;
//		del->_value = next->_value;
//		del->_pNext = next->_pNext;
//
//		delete next;
//		next = nullptr;
//	}
//	//����ֻ��һ���ڵ㣬ɾ��ͷ�ڵ㣨β��㣩
//	else if (*pListHead == del)
//	{
//		delete del;
//		del = nullptr;
//		*pListHead = nullptr;
//	}
//	//�������ж���ڵ㣬ɾ��β���
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