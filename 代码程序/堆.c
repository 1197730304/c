typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//交换函数
void swap(HPDataType* a, int child, int parent)
{
	int temp = a[child];
	a[child] = a[parent];
	a[parent] = temp;
}
//大堆的向下调整
void shiftDown(HPDataType* a,int n,int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1]&&child+1<n)
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			swap(a, parent, child);
			parent=child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	HPDataType* a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType) * n);
	hp->_capacity = n;
	hp->_size = n;
	//建堆,从最后一个非叶节点开始
	for (int parent = (n - 2) / 2; parent > 0; parent--)
	{
		shiftDown(hp->_a, n, parent);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_size = 0;
	hp->_capacity = 0;
	free(hp);
}

//大堆的向上调整
void shiftUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			swap(a, child, child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	//判断是否需要扩容
	if(hp->_capacity==hp->_size)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)calloc(hp->_a, hp->_capacity * sizeof(HPDataType));
	}

	//尾插
	hp->_a[hp->_size++] = x;
	shiftUp(hp->_a, hp->_size - 1);
}
// 堆的删除
void HeapPop(Heap* hp)
{
	if (hp->_size > 0)
	{
		//删除节点和队尾元素进行交换
		swap(hp->_a, 0, hp->_size - 1);
		//进行调整然后调整
		hp->_size--;
		shiftDown(hp->_a, hp->_size, 0);
	}

}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	if (hp->_size == 0)
		return 1;
	return 0;
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	
	//建堆
	for (int size = (n - 2) / 2; size >= 0; size--)
	{
		shiftDown(a, n,size);
	}
	//调整,循环尾删
	int sz = n;
	while (sz > 1)
	{
		swap(a, sz - 1, 0);
		sz--;
		shiftDown(a, sz, 0);
	}
}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	//建立含有前k个元素的大堆
	Heap hp;
	HeapCreate(&hp, a, n);
	for (int t = k ; t < n; t++)
	{
		if (a[t] < HeapTop(&hp))
		{
			HeapPop(&hp);
		    HeapPush(&hp, a[t]);
		}
	}

	for (int z = 0; z < k; z++)
	{
		printf("%d ",HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
}
void TestTopk()
{
	int n = 100000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100000;
	}
	PrintTopK(a, n, 3);
}
