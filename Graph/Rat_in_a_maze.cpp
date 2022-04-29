class Solution{
    public:
    void dfs(int i,int j,string s,vector<vector<int>> m,int n,vector<vector<int>> &vis,vector<string> &ans)
    {
        if(i<0 || j<0 || i>=n || j>=n)
        {
            return;
        }
        if(m[i][j]==0 || vis[i][j]==1)
        {
            return;
        }
        if(i==n-1 and j==n-1)
        {
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        dfs(i-1,j,s+'U',m,n,vis,ans);
        dfs(i+1,j,s+'D',m,n,vis,ans);
        dfs(i,j-1,s+'L',m,n,vis,ans);
        dfs(i,j+1,s+'R',m,n,vis,ans);
        vis[i][j]=0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n));
        if(m[0][0]==0 || m[n-1][n-1]==0)
        {
            return ans;
        }
        string s="";
        dfs(0,0,s,m,n,vis,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};