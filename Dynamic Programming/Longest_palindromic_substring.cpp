class Solution{
  public:
    int solve(int i,int j,string a,string b,vector<vector<int>>&dp)
    {
        int take=0,nottake1=0,nottake2=0;
        if(i<0||j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(a[i]==b[j])
        {
            take=1+solve(i-1,j-1,a,b,dp);
        }
        nottake1=solve(i-1,j,a,b,dp);
        nottake2=solve(i,j-1,a,b,dp);
        return dp[i][j]=max({take,nottake1,nottake2});
    }
    int longestPalinSubseq(string A) 
    {
        int n=A.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        string s=A;
        reverse(A.begin(),A.end());
        return solve(n-1,n-1,s,A,dp);
    }
};