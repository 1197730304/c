typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->_data = NULL;
	pHead->_next = pHead->_prev = pHead;
	return pHead;
}
// 双向链表销毁
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
// 双向链表打印
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
// 双向链表尾插
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
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* last = pHead->_prev;
	ListNode* lastprev = last->_prev;
	lastprev->_next = pHead;
	pHead->_prev = lastprev;
	free(last);
}
// 双向链表头插
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
// 双向链表头删
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
// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
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