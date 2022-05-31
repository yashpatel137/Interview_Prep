class Solution{
    public:
    vector<vector<long long>> dp;
    long long solve(int a[],int i,int j,int n)
    {
        long long x=0,y=0;
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        x=a[i]+min(solve(a,i+2,j,n),solve(a,i+1,j-1,n));
        y=a[j]+min(solve(a,i+1,j-1,n),solve(a,i,j-2,n));
        return dp[i][j]=max(x,y);
    }
    long long maximumAmount(int arr[], int n)
    {
        dp.resize(n+1,vector<long long>(n+1,-1));
        return solve(arr,0,n-1,n);
    }
};