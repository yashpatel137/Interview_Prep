class Solution{
  public:
    int dp[1001][1001];
    bool solve(string a,string b,string c,int n,int m,int len)
    {
        if(len==0)
        {
            return 1;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        int x,y;
        x=y=0;
        if(n-1>=0 and a[n-1]==c[len-1])
        {
            x=solve(a,b,c,n-1,m,len-1);
        }
        if(m-1>=0 and b[m-1]==c[len-1])
        {
            y=solve(a,b,c,n,m-1,len-1);
        }
        return dp[n][m]=x or y;
    }
    bool isInterleave(string a, string b, string c) 
    {
        int n=a.length();
        int m=b.length();
        int len=c.length();
        if(n+m!=len)
        {
            return 0;
        }
        dp[n][m];
        memset(dp,-1,sizeof(dp));
        return solve(a,b,c,n,m,len);
    }
};