class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> parent(V, -1);
        vector<bool> mst(V, false);
        vector<int> key(V, INT_MAX);
        key[0] = 0;
        parent[0] = -1;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0,0}); // node 0 and its key value -> 0
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            mst[u] = true;
            for(auto it: adj[u])
            {
                int v = it[0];
                int wt = it[1];
                if(mst[v] == false && wt < key[v])
                {
                    key[v] = wt;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        int sum = accumulate(key.begin(), key.end(), 0LL);
        return sum;
    }
};