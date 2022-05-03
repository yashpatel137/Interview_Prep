class Solution {
  public:
    void mark(vector<vector<char>>&matrix,int x,int y,int r,int c)
    {
        if(x<0||x>=r||y<0||y>=c||matrix[x][y]!='1')
        {
            return;
        }
        matrix[x][y]='2';
        mark(matrix,x+1,y,r,c);
        mark(matrix,x,y+1,r,c);
        mark(matrix,x-1,y,r,c);
        mark(matrix,x,y-1,r,c);
        mark(matrix,x+1,y+1,r,c);
        mark(matrix,x+1,y-1,r,c);
        mark(matrix,x-1,y+1,r,c);
        mark(matrix,x-1,y-1,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row==0)
        {
            return 0;
        }
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    mark(grid,i,j,row,col);
                    count++;
                }
            }
        }
        return count;
    }
};