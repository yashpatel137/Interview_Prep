class Solution
{
	public:
	void dfs(int n,stack<int> &st,vector<int> &vis, vector<int> adj[])
	{
	    vis[n]=1;
	    for(auto x:adj[n])
	    {
	        if(!vis[x])
	        {
	            dfs(x,st,vis,adj);
	        }
	    }
	    st.push(n);
	}
	void redfs(int node, vector<int> &vis,vector<int> trans[])
	{
	    vis[node]=1;
	    for(auto x:trans[node])
	    {
	        if(!vis[x])
	        {
	            redfs(x,vis,trans);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,st,vis,adj);
            }
        }
        vector<int> trans[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto x:adj[i])
            {
                trans[x].push_back(i);
            }
        }
        int count=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                redfs(node,vis,trans);
                count++;
            }
        }
        return count;
    }
};