int arr[] = {100, 1000, 100, 1000, 1};
int sum[10000];
int maxSumWO3Consec(int n)
{
	if(sum[n]!=-1)
	    return sum[n];
	if(n==0)
	    return sum[n] = 0;
	if(n==1)
	    return sum[n] = arr[0];	
	if(n==2)
	    return sum[n] = arr[1]+arr[0];
	return sum[n] = max(max(maxSumWO3Consec(n-1),maxSumWO3Consec(n-2) + arr[n]),arr[n] + arr[n-1] + maxSumWO3Consec(n-3));
}


//Two consecutive
class Solution{
public:	
	int findMaxSum(int *arr, int n) 
	{
	    vector<int> dp(n+1,-1);
	    dp[0]=0;
	    dp[1]=arr[0];
	    for(int i=2;i<=n;i++)
	    {
	        int take=arr[i-1]+dp[i-2];
	        int nottake=dp[i-1];
	        dp[i]=max(take,nottake);
	    }
	    return dp[n];
	}
};