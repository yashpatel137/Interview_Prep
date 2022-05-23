class Solution
{
    public:
    int solve(int n,int x,int y,int z,vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int x1=INT_MIN,x2=INT_MIN,x3=INT_MIN;
        if(n>=x)
        {
            x1=solve(n-x,x,y,z,dp);
        }
        if(n>=y)
        {
            x2=solve(n-y,x,y,z,dp);
        }
        if(n>=z)
        {
            x3=solve(n-z,x,y,z,dp);
        }
        return dp[n]=1+max(x1,max(x2,x3));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(10001,-1);
        int ans=solve(n,x,y,z,dp);
        if(ans<0)
        {
            return 0;
        }
        return ans;
    }
};