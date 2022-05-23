class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> ans(1+x,vector<int> (1+y,0));
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    ans[i][j]=1+ans[i-1][j-1];
                }
                else
                {
                    ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
        return ans[x][y];
    }
};