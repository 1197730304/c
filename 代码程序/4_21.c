bool isbalance(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	int l = geth(root->left);
	int r = geth(root->right);
	int h = abs(l - r);
	return h < 2&& isbalance(root->left) &&
		isbalance(root->right);
}


int numberK(struct TreeNode* root,int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return numberK(root->left, k - 1) + numberK(root->right, k - 1);

}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
	{
		return root;
	}
	BinaryTreeFind(root->left, x);
	BinaryTreeFind(root->right, x);
}