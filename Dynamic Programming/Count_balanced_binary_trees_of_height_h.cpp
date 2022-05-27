class Solution {
  public:
    long long int countBT(int h) 
    {
        int dp[h+1];
        long long int mod=1e9+7;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=h;i++)
        {
            dp[i]=(dp[i-1]*((2*dp[i-2])%mod+dp[i-1]%mod)%mod)%mod;
        }
        return dp[h];
    }
};