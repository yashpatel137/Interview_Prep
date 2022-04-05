#include<bits/stdc++.h>

using namespace std;

int solve(int row,int col,set<pair<int,int>>&st,vector<vector<bool>> visited,int i,int j,int cnt)
{
    if(i==row || i<0 || j<0 || j==col || st.count({i,j}) || visited[i][j])
        return INT_MAX;
        
    if(j==col-1)
        return cnt;
    
    visited[i][j]=true;    
    int l1=solve(row,col,st,visited,i+1,j,cnt+1);
    int l2=solve(row,col,st,visited,i-1,j,cnt+1);
    int l3=solve(row,col,st,visited,i,j+1,cnt+1);
    int l4=solve(row,col,st,visited,i,j-1,cnt+1);
    visited[i][j]=false;
    
    return min({l1,l2,l3,l4});
}

int main()
{
   int row,col;
   cin>>row>>col;
   vector<vector<int>> mat(row,vector<int>(col));
   vector<vector<bool>> visited(row,vector<bool>(col,false));
   for(int i=0;i<row;++i)
   {
       for(int j=0;j<col;++j)
       {
           cin>>mat[i][j];
       }
   }
   
   set<pair<int,int>> st;
   for(int i=0;i<row;++i)
   {
       for(int j=0;j<col;++j)
       {
           if(mat[i][j]==0)
           {
               pair<int,int> p{i,j};
               st.insert(p);
               
                if(i+1<row)
                {
                    pair<int,int> p{i+1,j};
                    st.insert(p);
                }
                
                if(i-1>=0)
                {
                    pair<int,int> p{i-1,j};
                    st.insert(p);
                }
                
                if(j+1<col)
                {
                    pair<int,int> p{i,j+1};
                    st.insert(p);
                }
                
                if(j-1>=0)
                {
                    pair<int,int> p{i,j-1};
                    st.insert(p);
                }
           }
       }
   }
   
   int ans=INT_MAX;
   for(int i=0;i<row;++i)
   {
       if(st.count({i,0})==0){
           int length=solve(row,col,st,visited,i,0,0);
           cout<<i<<" "<<length<<endl;
           ans=min(ans,length);
       }
   }
   
   cout<<ans;
   
   return 0;
}

//Space
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

bool isSafe(int mat[R][C], int visited[R][C],
            int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y])
        return false;
 
    return true;
}
bool isValid(int x, int y)
{
    if (x < R && y < C && x >= 0 && y >= 0)
        return true;
 
    return false;
}
void markUnsafeCells(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 0)
            {
              for (int k = 0; k < 4; k++)
                if (isValid(i + rowNum[k], j + colNum[k]))
                    mat[i + rowNum[k]][j + colNum[k]] = -1;
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
}
void findShortestPathUtil(int mat[R][C], int visited[R][C], int i, int j, int &min_dist, int dist)
{
    if (j == C-1)
    {
        min_dist = min(dist, min_dist);
        return;
    }
    if (dist > min_dist)
        return;
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + rowNum[k], j + colNum[k]) && isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
        {
            findShortestPathUtil(mat, visited, i + rowNum[k],j + colNum[k], min_dist, dist + 1);
        }
    }
    visited[i][j] = 0;
}
void findShortestPath(int mat[R][C])
{
    int min_dist = INT_MAX;
    int visited[R][C];
    markUnsafeCells(mat);
    for (int i = 0; i < R; i++)
    {
        if (mat[i][0] == 1)
        {
            memset(visited, 0, sizeof visited);
            findShortestPathUtil(mat, visited, i, 0, min_dist, 0);
 
            if(min_dist == C - 1)
                break;
        }
    }
 
    if (min_dist != INT_MAX)
        cout << "Length of shortest safe route is "
             << min_dist;
 
    else 
        cout << "Destination not reachable from "
             << "given source";
}
int main()
{
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    findShortestPath(mat);
 
    return 0;
}