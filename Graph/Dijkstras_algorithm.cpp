class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(V,INT_MAX);
        ans[S]=0;
        pq.push({0,S});
        while(!pq.empty())
        {
            int gap=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            for(auto &it:adj[prev])
            {
                int next=it[0];
                int nextd=it[1];
                if(ans[next]>ans[prev]+nextd)
                {
                    ans[next]=ans[prev]+nextd;
                    pq.push({ans[next],next});
                }
            }
        }
        return ans;
    }
};