// m-coloring
bool isPossibleToColor(int node,int color[],bool graph[101][101],int V,int col)
{
   for(int i=0;i<V;i++){
       if(i!=node and graph[node][i]==1 and color[i]==col)
           return false;
   }
   return true;
}
bool solve(int node ,bool graph[101][101],int m, int V,int color[])
{
   if(node==V) return true;
   
   for(int i=1;i<=m;i++){
       if(isPossibleToColor(node,color,graph,V,i)){
           color[node] = i;
           if(solve(node+1,graph,m,V,color)) return true;
           color[node] = 0;
       }
   }
   return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
   int color[V] = {0};
   if(solve(0,graph,m,V,color)==true) 
   {
       return true;
   }
   return false;
}

//Bipartite graph
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