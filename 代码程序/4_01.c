// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

// �������ӡ
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
// ������β��
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
// �������ͷ��
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
// �������βɾ
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

// ������ͷɾ
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
// ���������
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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
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
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
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
// �����������
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
