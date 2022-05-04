class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        int ans=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int key=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            if(vis[key])
            {
                continue;
            }
            ans+=weight;
            vis[key]=1;
            for(auto x:adj[key])
            {
                int wt=x[1];
                int k=x[0];
                if(!vis[k])
                {
                    pq.push({wt,k});
                }
            }
        }
        return ans;
    }
};