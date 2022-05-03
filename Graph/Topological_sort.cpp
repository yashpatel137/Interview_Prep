class Solution
{
	public: 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans(V,0),ind(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            ind[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(ind[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    int indg=0;
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        ans[indg++]=temp;
	        for(auto it:adj[temp])
	        {
	            ind[it]--;
	            if(ind[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};