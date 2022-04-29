class Solution {
  public:
    vector<int> ans;
    vector<int> dfs(vector<int> adj[],int r,bool visited[])
    {
        visited[r]=true;
        ans.push_back(r);
        for(auto x:adj[r])
        {
            if(visited[x]==false)
            {
                dfs(adj,x,visited);
            }
            
        }
        return ans;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        bool visited[V+1]={false};
        return dfs(adj,0,visited);
    }
};