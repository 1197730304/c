typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->_data = NULL;
	pHead->_next = pHead->_prev = pHead;
	return pHead;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	ListNode* cur, * next;
		cur= pHead->_next;
	if (cur == pHead)
	{
		return NULL;
	}
	while (cur != pHead)
	{
		next = cur->_next;
		printf("%d ", cur->_data);
		cur = next;
	}
	printf("\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{

	ListNode* cur = ListCreate(x);
	assert(pHead);
	ListNode* last = pHead->_prev;
	last->_next = cur;
	cur->_prev = last;
	cur->_next = pHead;
	pHead->_prev = cur;
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* last = pHead->_prev;
	ListNode* lastprev = last->_prev;
	lastprev->_next = pHead;
	pHead->_prev = lastprev;
	free(last);
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newh = ListCreate(x);
	ListNode* first = pHead->_next;
	pHead->_next = newh;
	newh->_prev = pHead;
	newh->_next = first;
	first->_prev = newh;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur, * next;
	cur = pHead->_next;
	next = cur->_next;
	pHead->_next = next;
	next->_prev = pHead;
	free(cur);
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			return 1;
		}
		cur = cur->_next;
	}
	return 0;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* node = ListCreate(x);
	ListNode* prev = pos->_prev;
	node->_next = pos;
	pos->_prev = node;
	prev->_next = node;
	node->_prev = prev;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev, * next;
	prev = pos->_prev;
	next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);

}