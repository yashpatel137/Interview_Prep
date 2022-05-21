class Solution{
public:
    int solve(int arr[],int n, int sum,vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return 1;
        }
        if(n==0 and sum!=0)
        {
            return 0;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(arr[n-1]>sum)
        {
            return solve(arr,n-1,sum,dp);
        }
        return dp[n][sum]=solve(arr,n-1,sum,dp)||solve(arr,n-1,sum-arr[n-1],dp);
    }
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        {
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum/2,dp);
    }
};