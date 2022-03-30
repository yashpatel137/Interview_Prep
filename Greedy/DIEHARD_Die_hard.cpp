#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

int dp[1001][1001];

int solve(int h, int a, int i)
{
  if (h <= 0 or a <= 0)
  {
    return 0;
  }
  if (dp[h][a] != -1)
  {
    return dp[h][a];
  }
  int x = 0, y = 0, z = 0;
  if (i != 1)
  {
    x = 1 + solve(h + 3, a + 2, 1);
  }
  if (i != 2)
  {
    y = 1 + solve(h - 5, a - 10, 2);
  }
  if (i != 3)
  {
    z = 1 + solve(h - 20, a + 5, 3);
  }
  return dp[h][a] = max({x, y, z});
}

int main() {
  init_code();
  int t;
  cin >> t;
  while (t--)
  {
    int h, a;
    cin >> h >> a;
    memset(dp, -1, sizeof(dp));
    cout << max({solve(h + 3, a + 2, 1), solve(h - 5, a - 10, 2), solve(h - 20, a + 5, 3)}) << endl;
  }
  return 0;
}