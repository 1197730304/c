//组合问题
/*#include<iostream>
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
*/
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


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        vector<bool> used(candidates.size(), false);
//        sort(candidates.begin(), candidates.end());
//        backtrick(candidates, target, 0, used);
//        return result;
//    }
//
//private:
//    vector<vector<int>> result;
//    vector<int> path;
//
//    int pathsum;
//    void backtrick(vector<int>& candidates, int target, int startIndex, vector<bool> used)
//    {
//        //判出条件
//        if (pathsum > target)
//            return;
//        if (pathsum == target)
//        {
//            result.push_back(path);
//            return;
//        }
//
//        for (int i = startIndex; i < candidates.size() && pathsum + candidates[i] <= target; i++)
//        {
//            //used[i-1]==false;同一树层被访问
//            //used[i-1]==true;同一树支被访问
//            //对相同元素进行跳过
//            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
//            {
//                continue;
//            }
//
//            path.push_back(candidates[i]);
//
//            pathsum += candidates[i];
//            used[i] = true;
//            backtrick(candidates, target, i + 1, used);
//            used[i] = false;
//            path.pop_back();
//            pathsum -= candidates[i];
//
//        }
//
//
//    }
//};


//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//返回 s 所有可能的分割方案。
//
//示例 :
//
//输入: "aab"
//输出 :
//    [
//        ["aa", "b"],
//        ["a", "a", "b"]
//    ]

/*class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtrick(s, 0);
        return result;
    }


private:
    vector<vector<string>> result;
    vector<string> path;
    bool ishuiwen(string s, int begin, int end)
    {
        int i = begin;
        int j = end;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrick(string s, int startIndex)
    {
        //终止条件
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }

        //循环判断
        for (int i = startIndex; i <= s.size(); i++)
        {
            if (ishuiwen(s, startIndex, i))
            {
                path.push_back(s.substr(startIndex, i - startIndex + 1));

            }
            else {
                continue;
            }
            backtrick(s, i + 1);
            path.pop_back();

        }
    }

};*/

//leetcode 93题
/*class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        backtrick(s, 0, 0);
        return result;
    }

private:
    vector<string> result;
    bool isval(const string& s, int start, int end)
    {
        if (start > end)
            return false;
        if (start != end && s[start] == '0')
        {
            return false;
        }

        long long int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }

            num = num * 10 + (s[i] - '0');
            if (num > 255)
            {
                return false;
            }
        }
        return true;
    }
    void backtrick(string& s, int startIndex, int point)
    {
        //判出条件
        if (point == 3)
        {
            //判断第四段是否合法，合法就放入
            if (isval(s, startIndex, s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            if (isval(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.');

                point++;
                backtrick(s, i + 2, point);
                point--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;

        }
    }
};*/

/*
* 从一个不含重复元素的数组中找出所有的子集
* leetcode  78题
* 
* class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrick(nums,0);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backtrick(vector<int>& nums,int startIndex)
    {
        result.push_back(path);
        //终止条件
        if(startIndex>=nums.size())
        {
            return;
        }

        for(int i=startIndex;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            backtrick(nums,i+1);
            path.pop_back();
        }
    }
};
*/

//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）
/*class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTrick(nums, 0, used);

        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backTrick(vector<int>& nums, int startIndex, vector<bool>& used)
    {
        result.push_back(path);


        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backTrick(nums, i + 1, used);
            used[i] = false;
            path.pop_back();

        }
    }
};*/


//递增子序列
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTrick(nums, 0);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backTrick(vector<int>& nums, int startIndex)
    {
        int used[201] = { 0 };
        //判出条件
        if (path.size() > 1)
        {
            result.push_back(path);
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && path.back() > nums[i]) || used[nums[i] + 100] == 1)
            {
                continue;
            }
            used[nums[i] + 100] = 1;//表示本层已经被用过了
            path.push_back(nums[i]);
            backTrick(nums, i + 1);
            path.pop_back();
        }
    }
};