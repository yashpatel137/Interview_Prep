class Solution {
public:
    bool solve(int src,vector<int>adj[],vector<int>&col)
    {
        if(col[src]==-1)
        {
            col[src]=1;
        }
        for(auto it:adj[src])
        {
            if(col[it]==-1)
            {
                col[it]=1-col[src];
                if(!solve(it,adj,col))
                {
                    return false;
                }
            }
            else if(col[it]==col[src])
            {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int v, vector<int>adj[])
	{
	    vector<int>col(v,-1);
	    for(int i=0;i<v;i++)
	    {
	        if(col[i]==-1)
	        {
	            if(!solve(i,adj,col))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};