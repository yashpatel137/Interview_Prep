class Solution {
public:
    bool solve(int src,int k,vector<bool> &vis,vector<pair<int,int>>graph[])
    {
        vis[src]=true;
        if(k<=0)
        {
            return true;
        }
        for(auto it:graph[src])
        {
            int v=it.first;
            int w=it.second;
            if(vis[v]==true)
            {
                continue;
            }
            if(w>=k)
            {
                return true;
            }
            if(solve(v,k-w,vis,graph))
            {
                return true;
            }
        }
        vis[src]=false;
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       vector<pair<int,int>> graph[V];
       for(int i=0;i<E*3;i+=3)
       {
           graph[a[i]].push_back({a[i+1],a[i+2]});
           graph[a[i+1]].push_back({a[i],a[i+2]});
       }
       vector<bool> vis(V+1,false);
       return solve(0,k,vis,graph);
    } 
};