class Solution{
    public:
    long long int mod=1e9+7;
    long long int dp[1001][1001];
    long long int solve(int i,int j,string s)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==j)
        {
            return dp[i][j]=1;
        }
        else if(s[i]==s[j])
        {
            return dp[i][j]=(1+solve(i+1,j,s)+solve(i,j-1,s))%mod;
        }
        else
        {
            return dp[i][j]=(solve(i+1,j,s)+solve(i,j-1,s)-solve(i+1,j-1,s))%mod;
        }
    }
    long long int  countPS(string str)
    {
        int n=str.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,str);
    }
     
};