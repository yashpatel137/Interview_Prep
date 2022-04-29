class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visit(V);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            visit[temp]=true;
            ans.push_back(temp);
            for(auto x:adj[temp])
            {
                if(visit[x]==false)
                {
                    q.push(x);
                    visit[x]=true;
                }
            }
        }
        return ans;
    }
};