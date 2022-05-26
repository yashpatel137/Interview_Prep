class Solution{
public:
    int solve(int i,int j,int n,vector<vector<int>> &mat,vector<vector<int>> &dp)
    {
        int p1=0,p2=0,p3=0;
        if(i<0||j<0||i>=n||j>=n)
        {
            return 0;
        }
        if(i==n-1)
        {
            return mat[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        p1=mat[i][j]+solve(i+1,j,n,mat,dp);
        p2=mat[i][j]+solve(i+1,j-1,n,mat,dp);
        p3=mat[i][j]+solve(i+1,j+1,n,mat,dp);
        return dp[i][j]=max(p1,max(p2,p3));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        int large=0;
        for(int i=0;i<N;i++)
        {
            large=max(large,solve(0,i,N,Matrix,dp));
        }
        return large;
    }
};