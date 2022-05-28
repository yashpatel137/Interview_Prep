class Solution{
public:
    int dp[1002][1002];
    int solve(int n,int w,int val[],int wt[])
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[w][n]!=-1)
        {
            return dp[w][n];
        }
        if(w>=wt[n-1])
        {
            return dp[w][n]=max(val[n-1]+solve(n,w-wt[n-1],val,wt),solve(n-1,w,val,wt));
        }
        else
        {
            return dp[w][n]=solve(n-1,w,val,wt);
        }
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(N,W,val,wt);
    }
};