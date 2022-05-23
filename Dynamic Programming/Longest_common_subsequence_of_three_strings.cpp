int dp[21][21][21];
int solve(int i,int j,int k,string s1,string s2,string s3)
{
    if(i<0||j<0||k<0)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    if(s1[i]==s2[j] and s2[j]==s3[k])
    {
        return 1+solve(i-1,j-1,k-1,s1,s2,s3);
    }
    return dp[i][j][k]=max({solve(i-1,j,k,s1,s2,s3),solve(i,j-1,k,s1,s2,s3),solve(i,j,k-1,s1,s2,s3)});
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    memset(dp,-1,sizeof(dp));
    int i=n1-1,j=n2-1,k=n3-1;
    return solve(i,j,k,A,B,C);
}