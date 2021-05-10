//根据前序和中序序列构建二叉树
//前序：[1,2,3,4,5,6,7]
//后序：[3,2,4,1,6,5,7]
//#include<iostream>
//#include<vector>
//using namespace std;
//struct TreeNode
//{
//    int val;
//    TreeNode* _left;
//    TreeNode* _right;
//    TreeNode(int x)
//        :val(x)
//        ,_left(nullptr)
//        ,_right(nullptr)
//    {}
//};
//    TreeNode* rebuild(vector<int>& pre, int l1, int r1, vector<int>& vin, int l2, int r2) {
//        //前序遍历数组为空
//        if (l1 > r1) return nullptr;
//
//        TreeNode* root = new TreeNode(pre[l1]);//pre[l1]:表示根节点
//        //在中序序列中找出根节点的位置
//        for (int i = l2; i <= r2; i++)
//        {
//            if (root->val == vin[i])
//            {
//                //递归查找
//                root->_left = rebuild(pre, l1 + 1, l1 + i - l2, vin, l2, i - 1);
//                root->_right = rebuild(pre, l1 + i - l2 + 1, r1, vin, i + 1, r2);
//            }
//        }
//        return root;
//    }
//
//    TreeNode* rebuiltBinTree(vector<int> pre, vector<int> vin)
//    {
//        return rebuild(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
//    }


    //
