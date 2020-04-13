//实现循环队列
typedef struct {
    int front;
    int rear;
    int size;
    int k;
    int* array;

} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->array = (int*)malloc(sizeof(int) * k);
    obj->front = obj->rear = 0;
    obj->size = 0;
    obj->k = k;
    return obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->k == obj->size)
        return false;
    obj->array[obj->rear++] = value;
    if (obj->rear == obj->k)
        obj->rear = 0;
    obj->size++;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0)
        return false;
    obj->front++;
    if (obj->front == obj->k)
        obj->front = 0;
    obj->size--;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;
    else
        return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;
    if (obj->rear == 0)
        return obj->array[obj->k - 1];
    return obj->array[obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->size == 0)
        return true;
    else
        return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->size == obj->k)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->array);
    free(obj);
}


//用队列实现栈


typedef int QDataType;

typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;

void queueInit(Queue* q);

QNode* creatNode(QDataType data);

void queuePush(Queue* q, QDataType data);

void queuePop(Queue* q);

QDataType queueFront(Queue* q);

QDataType queueBack(Queue* q);

int queueSize(Queue* q);

int queueEmpty(Queue* q);

void queueDestory(Queue* q);


void queueInit(Queue* q)
{
	//初始化空队列
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

QNode* creatNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//队尾入队
void queuePush(Queue* q, QDataType data)
{
	QNode* node = creatNode(data);
	//空队列
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}

//队头出队
void queuePop(Queue* q)
{
	if (q->_front)
	{
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//删除之后是否为空表
		if (q->_front == NULL)
			q->_rear = NULL;
		--q->_size;
	}
}

//获取队头元素
QDataType queueFront(Queue* q)
{
	return q->_front->_data;
}
//获取队尾元素
QDataType queueBack(Queue* q)
{
	return q->_rear->_data;
}

int queueSize(Queue* q)
{
	/*
	int num = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		++num;
		cur = cur->_next;
	}
	return num;
	*/
	return q->_size;
}

int queueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	return 0;
}

void queueDestory(Queue* q)
{
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

typedef struct {
	Queue q;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&ms->q);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	queuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret;
	int size = queueSize(&obj->q);
	while (size > 1)
	{
		int front = queueFront(&obj->q);
		queuePop(&obj->q);
		queuePush(&obj->q, front);
		size--;
	}
	ret = queueFront(&obj->q);
	queuePop(&obj->q);
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return queueBack(&obj->q);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
}

void myStackFree(MyStack* obj) {
	queueDestory(&obj->q);
	free(obj);
}


//用栈实现队列
typedef int Type;

typedef struct Stack
{
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, Type data);
void stackPop(Stack* st);
Type stackTop(Stack* st);

size_t stackSize(Stack* st);
int stackEmpty(Stack* st);

void stackDestory(Stack* st);


void stackInit(Stack* st, size_t n)
{
	st->_array = (Type*)malloc(sizeof(Type) * n);
	st->_capacity = n;
	st->_size = 0;
}

void stackPush(Stack* st, Type data)
{
	//检查容量
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
	}
	//尾插
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
	//尾删
	if (st->_size)
		--st->_size;
}
Type stackTop(Stack* st)
{
	return st->_array[st->_size - 1];
}

size_t stackSize(Stack* st)
{
	return st->_size;
}
int stackEmpty(Stack* st)
{
	if (st->_size == 0)
		return 1;
	return 0;
}

void stackDestory(Stack* st)
{
	free(st->_array);
	st->_array = NULL;
	st->_size = st->_capacity = 0;
}
typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&mq->pushST, 10);
	stackInit(&mq->popST, 10);
	return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int ret;
	if (stackEmpty(&obj->popST))
	{
		while (stackEmpty(&obj->pushST) != 1)
		{
			int Top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, Top);
		}
	}
	ret = stackTop(&obj->popST);
	stackPop(&obj->popST);
	return ret;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (stackEmpty(&obj->popST))
	{
		while (stackEmpty(&obj->pushST) != 1)
		{
			int Top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, Top);
		}
	}
	return stackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return stackEmpty(&obj->popST) && stackEmpty(&obj->pushST);
}

void myQueueFree(MyQueue* obj) {
	stackDestory(&obj->pushST);
	stackDestory(&obj->popST);
	free(obj);
}