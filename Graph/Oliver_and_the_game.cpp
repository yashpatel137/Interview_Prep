#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

vector<int> in, out;
int timer = 1;
void resize(int n)
{
  in.resize(n + 1);
  out.resize(n + 1);
}
void dfs(int src, int par, vector<int> g[])
{
  in[src] = timer++;
  for (auto x : g[src])
  {
    if (x != par)
    {
      dfs(x, src, g);
    }
  }
  out[src] = timer++;
}
bool check(int x, int y)
{
  if (in[x] > in[y] and out[x] < out[y])
  {
    return true;
  }
  return false;
}

int main() {
  init_code();
  int n;
  cin >> n;
  timer = 1;
  resize(n);
  vector<int> g[n + 1];
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0, g);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int type, x, y;
    cin >> type >> x >> y;
    if (!check(x, y) and !check(y, x))
    {
      cout << "NO\n";
      continue;
    }
    if (type == 0)
    {
      if (check(y, x))
      {
        cout << "YES\n";
      }
      else
      {
        cout << "NO\n";
      }
    }
    if (type == 1)
    {
      if (check(x, y))
      {
        cout << "YES\n";
      }
      else
      {
        cout << "NO\n";
      }
    }
  }

  return 0;
}