class Solution{
  public:
/*You are required to complete this method*/
    int solve(string p,string s,int i,int j,vector<vector<int>> &ans)
    {
        if(i==-1 && j==-1)
        {
            return 1;
        }
        if(j==-1)
        {
            for(int k=0;k<i;k++)
            {
                if(p[k]!='*')
                {
                    return 0;
                }
            }
            return 1;
        }
        if(i==-1)
        {
            return 0;
        }
        if(ans[i][j]!=-1)
        {
            return ans[i][j];
        }
        if(p[i]==s[j] || p[i]=='?')
        {
            return ans[i][j]=solve(p,s,i-1,j-1,ans);
        }
        if(p[i]=='*')
        {
            int op1=solve(p,s,i-1,j,ans);
            int op2=solve(p,s,i,j-1,ans);
            return ans[i][j]=op1 or op2;
        }
        return ans[i][j]=0;
    }
    int wildCard(string pattern,string str)
    {
        int n=pattern.length();
        int m=str.length();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        int sol=solve(pattern,str,n-1,m-1,ans);
        return sol==1?1:0;
    }
};