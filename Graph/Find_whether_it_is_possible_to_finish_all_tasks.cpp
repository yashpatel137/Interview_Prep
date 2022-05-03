class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) 
	{
	    vector<vector<int>> adj(n);
	    int num=pre.size();
	    for(int i=0;i<num;i++)
	    {
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    vector<int> ind(n,0);
	    queue<int> q;
	    for(int i=0;i<n;i++)
	    {
	        for(auto it:adj[i])
	        {
	            ind[it]++;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(ind[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    int cnt=0;
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[temp])
	        {
	            ind[it]--;
	            if(ind[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    if(cnt==n)
	    {
	        return true;
	    }
	    else
	    {
	        return false;
	    }
	}
};