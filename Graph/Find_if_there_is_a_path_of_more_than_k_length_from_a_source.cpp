#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}


bool solve(int src, int k, vector<pair<int, int>> g[], vector<int> &vis)
{
  vis[src] = 1;
  if (k <= 0)
  {
    return true;
  }
  for (auto x : g[src])
  {
    int u = x.first;
    int w = x.second;
    if (vis[u] == true)
    {
      continue;
    }
    if (w >= k)
    {
      return true;
    }
    if (solve(u, k - w, g, vis))
    {
      return true;
    }
  }
  vis[src] = false;
  return false;
}

int main() {
  init_code();
  int v, e;
  cin >> v >> e;
  int k;
  cin >> k;
  vector<pair<int, int>> g[v + 1];
  for (int i = 0; i < e; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  vector<int> vis(v + 1, 0);
  cout << solve(1, k, g, vis);

  return 0;
}