class Solution {
  public:
    bool checkBFS(int n, int V, vector<int>&vis, vector<int> adj[])
    {
        queue<pair<int,int>> q;
        vis[n]=1;
        q.push({n,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it != par)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkBFS(i,-1,vis,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};