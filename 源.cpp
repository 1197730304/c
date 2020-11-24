
//组合问题
#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
    void pathback(int n, int k, int startindex)
    {
        //判出条件
        if (tmp.size() == k)
        {
            result.push_back(tmp);
             return;
        }

        for (int i = startindex; i <= n; i++)
        {
            tmp.push_back(i);
            pathback(n, k, i + 1);
            tmp.pop_back();

        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        tmp.clear();

        pathback(n, k, 1);
        return result;
    }


};

int main()
{
    Solution a;
     vector<vector<int>> ret=a.combine(4, 2);
     
}

//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
/*class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backing(k, n, 1);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    int pathsum;
    void backing(int k, int n, int startindex)
    {
        //剪枝
        if (pathsum > n)
            return;
        //判出条件
        if (k == path.size())
        {
            if (pathsum == n)
            {
                result.push_back(path);

            }
            return;
        }


        for (int i = startindex; i <= 9; i++)
        {
            path.push_back(i);
            pathsum += i;
            backing(k, n, i + 1);
            pathsum -= i;
            path.pop_back();
        }
    }

};*/