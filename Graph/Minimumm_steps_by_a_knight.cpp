class Solution 
{
    public:
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int x1= KnightPos[0];
	    int x2= TargetPos[0];
	    int y1= KnightPos[1];
	    int y2= TargetPos[1];
	    
	    if(x1==x2 && y1==y2)
	    {
	        return 0; 
	    }
	    queue<pair<int,int>>q; 
	    q.push({x1-1,y1-1});
	    vector<vector<int>> visited(N,vector<int>(N,0)); 
	    visited[x1-1][y1-1]=0;
	    while(!q.empty())
	    {
	        auto curr= q.front();
	        q.pop();
	        int i= curr.first;
	        int j= curr.second;
	        if(i-2>=0 && j-1>=0 && i-2<N && j-1<N && visited[i-2][j-1]==0)
	        {
	            visited[i-2][j-1]= 1+visited[i][j];
	            q.push({i-2,j-1});
	        }
	        if(i-2>=0 && j+1>=0 && i-2<N && j+1<N && visited[i-2][j+1]==0)
	        {
	            visited[i-2][j+1]= 1+visited[i][j];
	            q.push({i-2,j+1});
	        }
	        if(i-1>=0 && j+2>=0 && i-1<N && j+2<N && visited[i-1][j+2]==0)
	        {
	            visited[i-1][j+2]= 1+visited[i][j];
	            q.push({i-1,j+2});
	        }
	        if(i+1>=0 && j+2>=0 && i+1<N && j+2<N && visited[i+1][j+2]==0)
	        {
	            visited[i+1][j+2]= 1+visited[i][j];
	            q.push({i+1,j+2});
	        }
	        
	        if(i+2>=0 && j-1>=0 && i+2<N && j-1<N && visited[i+2][j-1]==0)
	        {
	            visited[i+2][j-1]= 1+visited[i][j];
	            q.push({i+2,j-1});
	        }
	        if(i+2>=0 && j+1>=0 && i+2<N && j+1<N && visited[i+2][j+1]==0)
	        {
	            visited[i+2][j+1]= 1+visited[i][j];
	            q.push({i+2,j+1});
	        }
	        if(i-1>=0 && j-2>=0 && i-1<N && j-2<N && visited[i-1][j-2]==0)
	        {
	            visited[i-1][j-2]= 1+visited[i][j];
	            q.push({i-1,j-2});
	        }
	        if(i+1>=0 && j-2>=0 && i+1<N && j-2<N && visited[i+1][j-2]==0)
	        {
	            visited[i+1][j-2]= 1+visited[i][j];
	            q.push({i+1,j-2});
	        }
	    }
	    return visited[x2-1][y2-1];
	}
};