//#include<iostream>
//#include<vector>
//using namespace std;
//
////01背包问题
////n个物品，w为背包容量
//
//void test_01bag()
//{
//	vector<int> weight = { 1,3,4 };
//	vector<int> value = { 15,20,30 };
//	int bagweight = 4;
//	//定义数组
//	//dp[i][j]:表示从0-i个物品中装进背包大小为j的最大价值
//	vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
//	//初始化
//
//	for (int j = bagweight; j >= weight[0]; j--)
//	{
//		dp[0][j] = dp[0][j - weight[0]] + value[0];
//	}
//
//	//递推公式
//	//dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
//
//	for (int i =1; i <=weight.size() - 1; i++)
//	{
//		for (int j = 0;j <= bagweight; j++)
//		{
//			if (j < weight[i]) dp[i][j] = dp[i - 1][j];
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//		}
//	}
//	cout << dp[weight.size() - 1][bagweight] << endl;;
//}
//int main()
//{
//	int w, n;
//	//cin >> n >>w;
//	test_01bag();
//
//
//}