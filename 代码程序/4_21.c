//平衡二叉树

int geth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int l = geth(root->left);
    int r = geth(root->right);
    return l > r ? l + 1 : r + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int l = geth(root->left);
    int r = geth(root->right);
    return (abs(l - r) < 2) && isBalanced(root->left) &&
        isBalanced(root->right);
}


//二叉树的遍历oj
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
}TreeNode;

//建树,先序遍历
TreeNode* TreeNodeCreat(char* str, int* idx)
{
    if (str[*idx] != '#')
    {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = str[*idx];
        (*idx)++;
        root->left = TreeNodeCreat(str, idx);
        (*idx)++;
        root->right = TreeNodeCreat(str, idx);
        return root;
    }
    else
        return NULL;
}
//中序遍历
void TreeNodemid(TreeNode* root)
{
    if (root)
    {
        TreeNodemid(root->left);
        printf("%c ", root->val);
        TreeNodemid(root->right);

    }


}

int main()
{
    char str[101] = { 0 };
    int idx = 0;
    scanf("%s", str);
    TreeNode* root = TreeNodeCreat(str, &idx);
    TreeNodemid(root);
    return 0;

}
