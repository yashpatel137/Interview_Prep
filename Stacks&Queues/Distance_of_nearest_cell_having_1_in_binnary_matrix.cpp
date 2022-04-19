class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                ans[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        int x=q.front().first;
	        int y=q.front().second;
	        if(x-1>=0 && ans[x][y]+1<ans[x-1][y])
	        {
	            ans[x-1][y]=ans[x][y]+1;
	            q.push({x-1,y});
	        }
	        if(x+1<n && ans[x][y]+1<ans[x+1][y])
	        {
	            ans[x+1][y]=ans[x][y]+1;
	            q.push({x+1,y});
	        }
	        if(y-1>=0 && ans[x][y]+1<ans[x][y-1])
	        {
	            ans[x][y-1]=ans[x][y]+1;
	            q.push({x,y-1});
	        }
	        if(y+1<m && ans[x][y]+1<ans[x][y+1])
	        {
	            ans[x][y+1]=ans[x][y]+1;
	            q.push({x,y+1});
	        }
	        q.pop();
	    }
	    return ans;
	}
};