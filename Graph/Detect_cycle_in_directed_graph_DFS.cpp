class Solution {
  public:
    bool checkCycle(int n,vector<int> adj[],vector<int> &vis, vector<int> &dfsvis)
    {
        vis[n]=1;
        dfsvis[n]=1;
        for(auto it:adj[n])
        {
            if(!vis[it])
            {
                if(checkCycle(it,adj,vis,dfsvis))
                {
                    return true;
                }
            }
            else if(dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[n]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0),dfsvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i,adj,vis,dfsvis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};