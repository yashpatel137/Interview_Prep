class Solution{
public:
    int solve(int i,int j,int n,int m,vector<vector<int>> &M,vector<vector<int>> &dp)
    {
        if(i<0||j<0||i>=n||j>=m)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=M[i][j]+solve(i-1,j+1,n,m,M,dp);
        int right=M[i][j]+solve(i,j+1,n,m,M,dp);
        int down=M[i][j]+solve(i+1,j+1,n,m,M,dp);
        return dp[i][j]=max(max(up,right),down);
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=max(sum,solve(i,0,n,m,M,dp));
        }
        return sum;
    }
};