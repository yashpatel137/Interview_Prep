#include <bits/stdc++.h>

using namespace std;

void findpaths(int x,int y,int rows,int cols,vector<vector<int>> mat,vector<vector<bool>>&visited,vector<int> path,vector<vector<int>>&allpaths)
{
    if(x==rows-1 && y==cols-1)
    {
        path.push_back(mat[x][y]);
        allpaths.push_back(path);
        return;
    }
    
    if(x<0 || x>=rows || y<0 || y>=cols || visited[x][y])
        return;
    
    path.push_back(mat[x][y]);
    visited[x][y]=true;
    findpaths(x,y+1,rows,cols,mat,visited,path,allpaths);
    findpaths(x+1,y,rows,cols,mat,visited,path,allpaths);
    visited[x][y]=false;
    path.pop_back();
    
}
int main()
{
    int rows,cols;
    cin>>rows>>cols;
	vector<vector<int>> mat(rows,vector<int> (cols,0));
	vector<vector<bool>> visited(rows,vector<bool> (cols,false));
	
	for(int i=0;i<rows;++i)
	{
	    for(int j=0;j<cols;++j)
	    {
	        cin>>mat[i][j];
	    }
	}
	

	vector<int> path;
	vector<vector<int>> allpaths;
	findpaths(0,0,rows,cols,mat,visited,path,allpaths);
	cout<<allpaths.size()<<endl;
	for(int i=0;i<allpaths.size();++i)
	{
	    for(int j=0;j<allpaths[i].size();++j)
	    {
	        cout<<allpaths[i][j]<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}

