//创建头指针
Node* creatNode(Type data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->next = NULL;
	return node;
}

//打印
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

//头插
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
	//尾插
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