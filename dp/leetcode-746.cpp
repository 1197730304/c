////ʹ����С������¥��
////leetcode 746
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        //dp[i]��ʾ�����i�����ݵ���ͻ���
//        vector<int> dp(cost.size());
//        //ȷ�����ƹ�ʽ
//        //dp[i]=min(dp[i-1],dp[i-2])+cost[i];
//        //��ʼ��
//        dp[0] = cost[0];
//        dp[1] = cost[1];
//        for (int i = 2; i < cost.size(); i++)
//        {
//            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//        }
//        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
//    }
//};