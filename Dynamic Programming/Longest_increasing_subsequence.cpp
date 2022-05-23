class Solution
{
    public:
    int solve(int i,int j,int a[],int n,vector<vector<int>> &dp)
    {
        int len=0;
        if(j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==n||a[i]>a[j])
        {
            len=1+solve(j,j-1,a,n,dp);
        }
        len=max(len,solve(i,j-1,a,n,dp));
        return dp[i][j]=len;
    }
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(n,n-1,a,n,dp);
    }
};