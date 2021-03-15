//class Solution {
//public:
//    vector<vector<int> > Print(TreeNode* pRoot) {
//        queue<TreeNode*> q;
//        vector<vector<int>> ret(0);
//        q.push(pRoot);
//        while (!q.empty())
//        {
//            int sz = q.size();
//            vector<int> tmp;
//            while (sz--)
//            {
//                TreeNode* node = q.front();
//                q.pop();
//                tmp.push_back(node->val);
//
//                if (node->left)
//                    q.push(node->left);
//                if (node->right)
//                    q.push(node->right);
//            }
//            ret.push_back(tmp);
//
//        }
//        return ret;
//
//    }
//
//};

//class Solution
//{
//public:
//    void push(int node) {
//        while (!st2.empty())
//        {
//            st1.push(st2.top());
//            st2.pop();
//        }
//        st1.push(node);
//    }
//
//    int pop() {
//        if (st1.size() == 0)
//            return NULL;
//        while (st1.size() > 1)
//        {
//            int top = st1.top();
//            st1.pop();
//            st2.push(top);
//
//        }
//        int tp = st1.top();
//        st1.pop();
//        while (!st2.empty())
//        {
//            int tmp = st2.top();
//            st2.pop();
//            st1.push(tmp);
//        }
//        return tp;
//
//    }
//
//private:
//    stack<int> st1;
//    stack<int> st2;
//};

