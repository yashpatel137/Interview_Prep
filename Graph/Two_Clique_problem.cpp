#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

int f = 0;
void bipartite(int src, int par, int col, vector<int> &color, vector<int> rev[])
{
  color[src] = 1;
  for (auto x : rev[src])
  {
    if (!color[x])
    {
      bipartite(x, src, 3 - col, color, rev);
    }
    else if (x != par and color[x] == col)
    {
      f = 1;
      break;
    }
  }
}
void solve()
{
  int v, e;
  cin >> v >> e;
  vector<int> g[v];
  for (int i = 0; i < e; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> rev[v];
  vector<int> vis(v, 0);
  for (int i = 0; i < v; i++)
  {
    vis[i] = 1;
    for (auto x : g[i])
    {
      vis[x] = 1;
    }
    for (int j = 0; j < v; j++)
    {
      if (vis[j] == 0)
      {
        rev[i].push_back(j);
        rev[j].push_back(i);
      }
    }
    vis.clear();
  }
  vector<int> color(v, 0);
  bipartite(0, 0, 1, color, rev);
  if (!f)
  {
    cout << "Two Clique!" << endl;
  }
  else
  {
    cout << "Not Possible!" << endl;
  }
}

int main() {
  init_code();
  solve();
  return 0;
}