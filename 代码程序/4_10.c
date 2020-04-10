// ֧�ֶ�̬������ջ
#define defstacksize 100
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
	int size;
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_a = (STDataType*)malloc(sizeof(STDataType));
	ps->_capacity = defstacksize;
	ps->size = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	if (ps->size >= ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)relloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
	ps->_a[ps->size++] = data;
	ps->_top = ps->_a[ps->size - 1];

	
}
// ��ջ 
void StackPop(Stack* ps)
{
	if (ps->size)
	{
		ps->size--;
	ps->_top = ps->_a[ps->size - 1];
    }
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	return ps->_top;
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->size;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	if (ps->size == 0)
		return 1;
	else
		return 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	if(ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->size = 0;
		ps->_capacity = 0;
	}
}

typedef int QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	struct QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;
QNode* creatNode(Queue* q, QDataType data)
{
	QNode* cur = (QNode*)malloc(sizeof(QNode));
	cur->_data = data;
	cur->_next = NULL;
	return cur;

}

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;

}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	QNode* cur = creatNode(data);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = cur;
	}
	else
	{
		q->_rear->_next = cur;
		q->_rear = cur;
	}

}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	if(q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front==NULL)
		{
			q->_rear = NULL;
		}
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	int num = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		num++;
		cur = cur->_next;
	}
	return num;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	
}
