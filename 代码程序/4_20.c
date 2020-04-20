//二叉树的最大深度
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;;
	int l = maxDepth(root->left) ;
	int r = maxDepth(root->right) ;
	return l > r ? l+1 : r+1;
}


//翻转二叉树
void invert(struct TreeNode* root)
{
	if (root)
	{
		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		invert(root->left);
		invert(root->right);
	}
}

struct TreeNode* invertTree(struct TreeNode* root) {
	invert(root);
	return root;
}


//对称二叉树
bool issy(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return issy(p->left, q->right) && issy(p->right, q->left) && (p->val == q->val);
}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	return issy(root->left, root->right);
}

//字子树

bool issametree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
		return true;
	if (s == NULL || t == NULL)
		return false;
	return issametree(s->left, t->left) && issametree(s->right, t->right) && (s->val == t->val);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {

	if (s == NULL && t != NULL)
		return false;
	return issametree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);

}

//双指针解决水缸问题
int maxArea(int* height, int heightSize) {
	int left, right;
	left = 0;
	right = heightSize - 1;
	int sum = 0, max = 0;
	while (left < right)
	{
		if (height[left] < height[right])
		{
			sum = (right - left) * height[left];
			left++;
		}
		else
		{
			sum = (right - left) * height[right];
			right--;
		}
		max = max > sum ? max : sum;
	}
	return max;
}


//跳跃游戏
bool canJump(int* nums, int numsSize) {
	int i = 0, m = 0;
	if (numsSize == 0 || numsSize == 1)
		return true;
	while (i < numsSize - 1)
	{
		if (nums[i] == 0)
		{
			for (m = 0; m < i; m++)
			{
				if (nums[m] + m > i)
				{
					break;
				}
			}
			if (m == i)
				return false;

		}
		i++;
	}
	return true;
}
