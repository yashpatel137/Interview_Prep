class Solution
{
	public:
	long long int dp[201][201];
	long long int solve(int cost[],int n,int w)
	{
	    if(w==0)
	    {
	        return 0;
	    }
	    if(n==0||w<0)
	    {
	        return INT_MAX;
	    }
	    if(dp[n][w]!=-1)
	    {
	        return dp[n][w];
	    }
	    if(n<=w and cost[n-1]!=-1)
	    {
	        return dp[n][w]=min(cost[n-1]+solve(cost,n,w-n),solve(cost,n-1,w));
	    }
	    return dp[n][w]=solve(cost,n-1,w);
	}
	int minimumCost(int cost[], int N, int W) 
	{
	    memset(dp,-1,sizeof(dp));
	    long long int ans=solve(cost,N,W);
	    return ans>=INT_MAX?-1:(int)ans;
	} 
};