////使用最小花费爬楼梯
////leetcode 746
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        //dp[i]表示到达第i个阶梯的最低花费
//        vector<int> dp(cost.size());
//        //确定递推公式
//        //dp[i]=min(dp[i-1],dp[i-2])+cost[i];
//        //初始化
//        dp[0] = cost[0];
//        dp[1] = cost[1];
//        for (int i = 2; i < cost.size(); i++)
//        {
//            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//        }
//        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
//    }
//};