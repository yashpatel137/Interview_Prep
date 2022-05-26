class Solution{
    public:
    int solve(int i,int j,int arr[],int n,int k,vector<vector<int>> &dp)
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
        if(arr[i]-arr[j]<k)
        {
            take=arr[i]+arr[j]+solve(j-1,j-2,arr,n,k,dp);
        }
        nottake=solve(i-1,j-1,arr,n,k,dp);
        return dp[i][j]=max(take,nottake);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        sort(arr,arr+N);
        return solve(N-1,N-2,arr,N,K,dp);
    }
};