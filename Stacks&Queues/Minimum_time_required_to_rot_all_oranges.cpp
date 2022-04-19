class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int x, int y)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
        {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0,ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(q.empty() && fresh==0)
        {
            return 0;
        }
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto curr=q.front();
                q.pop();
                if(isSafe(grid,curr.first+1,curr.second)==true && grid[curr.first+1][curr.second]==1)
                {
                    q.push({curr.first+1,curr.second});
                    grid[curr.first+1][curr.second]=2;
                    fresh--;
                }
                if(isSafe(grid,curr.first-1,curr.second)==true && grid[curr.first-1][curr.second]==1)
                {
                    q.push({curr.first-1,curr.second});
                    grid[curr.first-1][curr.second]=2;
                    fresh--;
                }
                if(isSafe(grid,curr.first,curr.second+1)==true && grid[curr.first][curr.second+1]==1)
                {
                    q.push({curr.first,curr.second+1});
                    grid[curr.first][curr.second+1]=2;
                    fresh--;
                }
                if(isSafe(grid,curr.first,curr.second-1)==true && grid[curr.first][curr.second-1]==1)
                {
                    q.push({curr.first,curr.second-1});
                    grid[curr.first][curr.second-1]=2;
                    fresh--;
                }
            }
            ans++;
        }
        return fresh==0?ans-1:-1;
    }
};