
//�������
#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
    void pathback(int n, int k, int startindex)
    {
        //�г�����
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

//�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�
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
        //��֦
        if (pathsum > n)
            return;
        //�г�����
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