
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	
	if (a[*pi]!='#'&&(*pi)<n)
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreate(a, n, pi);
		root->_right = BinaryTreeCreate(a, n, pi);
	}
	else
		return NULL;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	BTNode* cur = *root;
	if (cur)
	{
		BinaryTreeDestory(cur->_left);
		BinaryTreeDestory(cur->_right);
		free(cur);
		*root = NULL;
	}
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL||k==0)
		return 0;
	if(k==1)
		return 1;
		return BinaryTreeLevelKSize(root->_left,k-1)+BinaryTreeLevelKSize(root->_right,k-1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
		if (root->_data == x)
			return root;
		BTNode* tmp=BinaryTreeFind(root->_left,x);
		if (tmp == NULL)
			return BinaryTreeFind(root->_right, x);
		else
			return tmp;
}
// ������ǰ����� 
//�ݹ�д��
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}

}
//�ǵݹ�д��
void BinaryTreePrevOrder(BTNode* root)
{
	stack st;
	stackInit(&st,10);
	BTNode* cur = root;
	while (cur || stackEmpty(&st) != 1)
	{
		while(cur)
		{
			printf("%c ", cur->_data);
			stackPush(&st,cur);
			cur = cur->_left;
		}
		BTNode* top = stackTop(&st);
		stackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}

// �������������
//�ݹ�д��
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);

		BinaryTreeInOrder(root->_right);
	}

}

//�ǵݹ�
void BinaryTreeInOrder(BTNode* root)
{
	stack st;
	stackInit(&st,10);
	BTNode* cur = root;
	while (cur || stackEmpty(&st) != 1)
	{
		while (cur)
		{
			stackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = stackTop(&st);
		printf("%c ", top->_data);
		stackPop(&st);
		cur = top->_right;
	}
	printf("\n");
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{

		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
	}		

}

//�ǵݹ�д��
void BinaryTreePostOrder(BTNode* root)
{
	stack st;
	stackInit(&st, 10);
	BTNode* cur = root;
	BTNode* prev = NULL;
	while (cur || stackEmpty(&st) != 1)
	{
		while(cur)
		{
			stackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = stackTop(&st);
		if (cur->_right == NULL || cur->_right == prev)
		{
			printf("%c ", cur->_data);
			prev = cur;
			stackPop(&st);
		}
		else
		{
			cur = cur->_right;
			
		}
	}
	printf("\n");
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	QueueInit(&qu);
	if (root)
		QueuePush(&qu,root);
	while (QueueEmpty(&qu) != 1)
	{
		BTNode* front = QueueFront(&qu);
		QueuePop(&qu);
		printf("%c ", front->_data);
		if (front->_left)
			QueuePush(&qu, root->_left);
		if (front->_right)
			QueuePush(&qu, root->_right);
	}
	printf("\n");
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	QueueInit(&qu);
	if (root)
		QueuePush(&qu, root);
	while (QueueEmpty(&qu) != 1)
	{
		BTNode* front = QueueFront(&qu);
		QueuePop(&qu);
		if (front)
		{
			QueuePush(&qu, front->_left);
		    QueuePush(&qu, front->_right);
		}
		else
			break;
	}
	while (QueueEmpty(&qu) != 1)
	{
		BTNode* front = QueueFront(&qu);
		QueuePop(&qu);
		if (front)
			return 0;
	}
	return 1;
}