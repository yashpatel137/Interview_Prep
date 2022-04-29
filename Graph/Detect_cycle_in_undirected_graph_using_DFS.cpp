class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkDFS(int n, int par, vector<int>&vis, vector<int> adj[])
    {
        vis[n]=1;
        for(auto it:adj[n])
        {
            if(vis[it]==0)
            {
                if(checkDFS(it,n,vis,adj))
                {
                    return true;
                }
            }
            else if(it!=par)
            {
                return true;
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
                if(checkDFS(i,-1,vis,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};