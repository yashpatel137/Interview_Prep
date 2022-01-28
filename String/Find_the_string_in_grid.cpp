class Solution {
public:
    bool find(int i,int j,int n,int m,vector<vector<char>> &grid,int idx,string word,int x,int y)
    {
        if(idx==word.length())
        {
            return true;
        }
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=word[idx])
        {
            return false;
        }
        return find(i+x,j+y,n,m,grid,idx+1,word,x,y);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    int x[8]={1,-1,0,0,1,-1,1,-1};
	    int y[8]={1,-1,1,-1,0,0,-1,1};
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==word[0])
	            {
	                for(int k=0;k<8;k++)
	                {
	                    if(find(i,j,n,m,grid,0,word,x[k],y[k]))
	                    {
	                        ans.push_back({i,j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return ans;
	}
};