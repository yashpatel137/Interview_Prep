#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

void dfs(int src, vector<int>&vis, vector<int>g[], int &counter)
{
  vis[src] = 1;
  counter++;
  for (auto it : g[src])
  {
    if (!vis[it])
    {
      dfs(it, vis, g,counter);
    }
  }
}
int main() {
  init_code();
  int v, e;
  cin >> v >> e;
  vector<int>g[v];
  for (int i = 0; i < e; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
  }
  vector<int> vis(v, 0);
  vector<int>sol;
  for (int i = 0; i < v; i++)
  {
    if (!vis[i])
    {
      int counter=0;
      dfs(i, vis, g,counter);
      sol.push_back(counter);
    }
  }
  int val=(v*(v-1))/2;
  for (int i = 0; i < sol.size(); i++)
  {
    int x=(sol[i]*(sol[i]-1))/2;
    val=val-x;
  }
  cout<<val;
  return 0;
}