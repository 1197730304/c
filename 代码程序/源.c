//����ͷָ��
Node* creatNode(Type data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->next = NULL;
	return node;
}

//��ӡ
void singleListPrint(SingleList* sl)
{
	Node* cur = sl->head;
	while (cur)
	{
		printf("%d", cur->date);
		cur = cur->next;
	}
	printf("\n");
}

//ͷ��
void singleListPushFront(SingleList* sl, Type data)
{
	Node* node = creatNode(data);
	if (node->next == NULL)
	{
		sl->head = node;
	}
	node->next = sl->head;
	sl->head = node;
}

void singleListPushBack(SingleList* sl, Type data)
{
	//β��
	Node* node = creatNode(data);
	if (sl->head == NULL)
		sl->head = node;
	Node* last = node->next;
	while (last->next)
	{
		last = last->next;
	}
	last->next = node;
}