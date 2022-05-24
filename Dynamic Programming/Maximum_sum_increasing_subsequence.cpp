class Solution
{
	public:
	int dp[1009][1009];
	int solve(int arr[],int i,int j,int n,int dp[1009][1009])
	{
	    int take=0,nottake=0;
	    if(j<0)
	    {
	        return 0;
	    }
	    if(dp[i][j]!=-1)
	    {
	        return dp[i][j];
	    }
	    if(i==n||arr[i]>arr[j])
	    {
	        take=arr[j]+solve(arr,j,j-1,n,dp);
	    }
	    nottake=solve(arr,i,j-1,n,dp);
	    return dp[i][j]=max(take,nottake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    memset(dp,-1,sizeof(dp));
	    return solve(arr,n,n-1,n,dp);
	}  
};