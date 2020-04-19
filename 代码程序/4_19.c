double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    double median = 0;
    int* num = (int*)malloc(sizeof(int) * n);
    int i = 0, j = 0, k = 0, count = 0;
    while (k < n)
    {
        if (i < nums1Size && j < nums2Size)
        {
            if (nums1[i] < nums2[j])
            {
                num[k] = nums1[i];
                i++;
                count++;

            }
            else
            {
                num[k] = nums2[j];
                j++;
                count++;
            }
        }
        else if (i < nums1Size)
        {
            num[k] = nums1[i];
            i++;
            count++;
        }
        else if (j < nums2Size)
        {
            num[k] = nums2[j];
            j++;
            count++;
        }
        if (count == n / 2 + 1)
            break;
        k++;
    }
    if (n % 2 == 0)
    {
        double d1 = num[k];
        double d2 = num[k - 1];
        median = (d1 + d2) / 2;

    }
    else
    {
        median = num[k];
    }
    return median;
}



//二叉树的先序遍历
int getsize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getsize(root->left) + getsize(root->right) + 1;
}

void inorderT(struct TreeNode* root, int* array, int* dex)
{
    if (root)
    {
        array[*dex] = root->val;
        (*dex)++;
        inorderT(root->left, array, dex);
        
        inorderT(root->right, array, dex);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getsize(root));
    *returnSize = 0;
    inorderT(root, array, returnSize);
    return array;
}

//二叉树的中序遍历
void getsize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getsize(root->left) + getsize(root->right) + 1;
}

void inorderT(struct TreeNode* root,int* array,int* index)
{
    if (root)
    {
    inorderT(root->left, array, index);
    array[*index] = root->val;
    *index++;
    inorderT(root->right, array, index);
    }
}
int* inorderTravel(struct TreeNode* root,int* returnsize)
{
    int* array = (int*)malloc(sizeof(int) * getsize(root);
    *returnsize = 0;
    inorderT(root, array, returnsize);
    return array;
}

//二叉树的后序遍历
int getsize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getsize(root->left) + getsize(root->right) + 1;
}

void inorderT(struct TreeNode* root, int* array, int* dex)
{
    if (root)
    {
        inorderT(root->left, array, dex);

        inorderT(root->right, array, dex);
        array[*dex] = root->val;
        (*dex)++;
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getsize(root));
    *returnSize = 0;
    inorderT(root, array, returnSize);
    return array;
}



//单值二叉树
bool isu(struct TreeNode* root, int key)
{
    if (root == NULL)
        return true;
    return root->val == key && isu(root->left, key) && isu(root->right, key);
}
bool isUnivalTree(struct TreeNode* root) {
    return isu(root, root->val);

}

