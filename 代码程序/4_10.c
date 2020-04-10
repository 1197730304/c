// 支持动态增长的栈
#define defstacksize 100
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
	int size;
}Stack;
// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = (STDataType*)malloc(sizeof(STDataType));
	ps->_capacity = defstacksize;
	ps->size = 0;
}
// 入栈 
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
// 出栈 
void StackPop(Stack* ps)
{
	if (ps->size)
	{
		ps->size--;
	ps->_top = ps->_a[ps->size - 1];
    }
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	return ps->_top;
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->size;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	if (ps->size == 0)
		return 1;
	else
		return 0;
}
// 销毁栈 
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
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	struct QDataType _data;
}QNode;

// 队列的结构 
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

// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;

}
// 队尾入队列 
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
// 队头出队列 
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}
// 销毁队列 
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
