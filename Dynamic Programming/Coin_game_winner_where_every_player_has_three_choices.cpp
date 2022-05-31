class Solution{

	public:
	int dp[1000001];
	int solve(int n,int x,int y)
	{
	    if(n==0)
	    {
	        return 0;
	    }
	    if(n==1)
	    {
	        return 1;
	    }
	    if(dp[n]!=-1)
	    {
	        return dp[n];
	    }
	    int res1=n-x>=0?solve(n-x,x,y):1;
	    if(res1==0)
	    {
	        return dp[n]=1;
	    }
	    int res2=n-y>=0?solve(n-y,x,y):1;
	    if(res2==0)
	    {
	        return dp[n]=1;
	    }
	    int res3=n-1>=0?solve(n-1,x,y):1;
	    if(res3==0)
	    {
	        return dp[n]=1;
	    }
	    return dp[n]=0;
	}
	int findWinner(int N, int X, int Y)
	{
	    memset(dp,-1,sizeof(dp));
	    return solve(N,X,Y);
	}
};