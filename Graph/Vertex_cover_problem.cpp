#include<bits/stdc++.h>
int vertexCover(int n, vector<pair<int, int>> &edges) 
{
	vector<int> g[n];
	for(int i=0;i<edges.size();i++)
	{
		g[edges[i].first].push_back(edges[i].second);
		g[edges[i].second].push_back(edges[i].first);
	}
	vector<int>vis(n,0);
	list<int>::iterator i;
	for(int j=0;j<n;j++)
	{
		if(vis[j]==0)
		{
			for(i=g[j].begin();i!=g[j].end();i++)
			{
				int k=*i;
				if(vis[k]==0)
				{
					vis[j]=1;
					vis[k]=1;
					break;
				}
			}
		}
	}
	int count=0;
	for(int j=0;j<n;j++)
	{
		if(vis[j])
		{
			count++;
		}
	}
	return count;
}