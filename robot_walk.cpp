class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //dp[i][j]:表示从（0，0）到（i,j）有dp[i][j]条不相同的路径
        //确定递推方程
        //dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //初始化
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m&&obstacleGrid[i][0]==0;i++) dp[i][0]=1;
        for(int j=0;j<n&&obstacleGrid[0][j]==0;j++) dp[0][j]=1;

        //循环遍历
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1) continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
