#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

vector<int> order;
void topo(int src, vector<int>&vis, vector<vector<pair<int, int>>>g)
{
  vis[src] = 1;
  for (auto it : g[src])
  {
    if (!vis[it.first])
    {
      topo(it.first, vis, g);
    }
  }
  order.push_back(src);
}
int main() {
  init_code();
  int v, e;
  cin >> v >> e;
  int src;
  cin >> src;
  vector<vector<pair<int, int>>>g(v);
  for (int i = 0; i < e; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({y, w});
  }
  vector<int> vis(v, 0);
  for (int i = 0; i < v; i++)
  {
    if (!vis[i])
    {
      topo(i, vis, g);
    }
  }
  vector<int> dist(v, INT_MIN);
  dist[src] = 0;
  for (int i = v - 1; i >= 0; i--)
  {
    if (dist[order[i]] != INT_MIN)
    {
      for (auto x : g[order[i]])
      {
        int v = dist[x.first];
        int w = x.second;
        int u = dist[order[i]];
        if (v < u + w)
        {
          dist[x.first] = u + w;
        }
      }
    }
  }
  for (int i = 0; i < v; i++)
  {
    if (i != src and dist[i] != INT_MIN)
    {
      cout << src << " --> " << i << " = " << dist[i] << endl;
    }
  }

  return 0;
}