typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//��������
void swap(HPDataType* a, int child, int parent)
{
	int temp = a[child];
	a[child] = a[parent];
	a[parent] = temp;
}
//��ѵ����µ���
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

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	HPDataType* a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType) * n);
	hp->_capacity = n;
	hp->_size = n;
	//����,�����һ����Ҷ�ڵ㿪ʼ
	for (int parent = (n - 2) / 2; parent > 0; parent--)
	{
		shiftDown(hp->_a, n, parent);
	}
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_size = 0;
	hp->_capacity = 0;
	free(hp);
}

//��ѵ����ϵ���
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
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	//�ж��Ƿ���Ҫ����
	if(hp->_capacity==hp->_size)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)calloc(hp->_a, hp->_capacity * sizeof(HPDataType));
	}

	//β��
	hp->_a[hp->_size++] = x;
	shiftUp(hp->_a, hp->_size - 1);
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	if (hp->_size > 0)
	{
		//ɾ���ڵ�Ͷ�βԪ�ؽ��н���
		swap(hp->_a, 0, hp->_size - 1);
		//���е���Ȼ�����
		hp->_size--;
		shiftDown(hp->_a, hp->_size, 0);
	}

}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	if (hp->_size == 0)
		return 1;
	return 0;
}

// ��������ж�����
void HeapSort(int* a, int n)
{
	
	//����
	for (int size = (n - 2) / 2; size >= 0; size--)
	{
		shiftDown(a, n,size);
	}
	//����,ѭ��βɾ
	int sz = n;
	while (sz > 1)
	{
		swap(a, sz - 1, 0);
		sz--;
		shiftDown(a, sz, 0);
	}
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	//��������ǰk��Ԫ�صĴ��
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
