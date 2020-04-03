// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist->head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* cur = BuySListNode(x);
	cur = *pplist->next;
	if (*pplist== NULL)
	{
		*pplist->data = x;
	}
	while (cur)
	{
		cur = cur->next;
	}
	cur->data = x;
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* cur = BuySListNode(x);
	if (*pplist == NULL)
	{
		*p->data = x;
	}
	cur->next = *pplist;
	*pplist = cur;
	
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	SListNode* prev = NULL;
	SListNode* cur = *pplist;

	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	if (*pplist == NULL)
	{
		return NULL;
	}
	prev->next = NULL;
	free(cur);


}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return NULL;
	}
	SListNode* cur = *pplist;
	*pplist = cur->next;
	free(cur);

}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
	{
		return NULL;
	}
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		return;
	}
	SListNode* cur = BuySListNode(x);
	cur->next = pos->next;
	pos->next = cur;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	SListNode* cur = pos->next;
	if(cur)
	pos->next = cur->next;
	free(pos->next);
}
// 单链表的销毁
void SListDestory(SList* plist)
{
	SListNode* cur = plist->head;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
