//Method 1
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        int n=str.length();
        vector<vector<long long int>> ans(n,vector<long long int>(n));
        for(int d=0;d<n;d++)
        {
            for(int i=0,j=d;j<n;i++,j++)
            {
                if(d==0)
                {
                    ans[i][j]=1;
                }
                else if(d==1)
                {
                    ans[i][j]=str[i]==str[j]?3:2;
                }
                else
                {
                    if(str[i]==str[j])
                    {
                        ans[i][j]=(ans[i+1][j]+ans[i][j-1]+1)%1000000007;
                    }
                    else
                    {
                        ans[i][j]=(ans[i+1][j]+ans[i][j-1]-ans[i+1][j-1])%1000000007;
                    }
                }
                if(ans[i][j]<0)
                {
                    ans[i][j]+=1000000007;
                }
            }
        }
        return ans[0][n-1]%1000000007;
    }
     
};

//Method 2
long long dp[1001][1001];
    int mod = 1e9+7;
    long long int  countPS(string str)
    {
        memset(dp, -1, sizeof dp);
        return solve(str, 0, str.size() - 1);
    }
    long long solve(string& str, int i, int j) {
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str[i]==str[j]) return dp[i][j] = (1 + solve(str, i+1, j) + solve(str, i, j-1))%mod;
        else return dp[i][j] = (mod + solve(str, i+1, j) + solve(str, i, j-1) - solve(str, i+1, j-1))%mod;
    }