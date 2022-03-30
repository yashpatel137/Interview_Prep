#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

int main() {
  init_code();
  int n;
  cin >> n;
  while (true)
  {
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    vector<pair<int, int>> buy, sell;
    for (int i = 0; i < n; i++)
    {
      if (a[i] > 0)
      {
        buy.push_back({a[i], i});
      }
      else
      {
        sell.push_back({a[i], i});
      }
    }
    int ans = 0, i = 0, j = 0;
    while (i < buy.size() and j < sell.size())
    {
      int x = min(buy[i].first, -sell[j].first);
      buy[i].first -= x;
      sell[j].first += x;
      int diff = abs(buy[i].second - sell[j].second);
      ans += x * diff;
      if (buy[i].first == 0)
      {
        i++;
      }
      if (sell[j].first == 0)
      {
        j++;
      }
    }
    cout << ans << endl;
    cin >> n;
    if (n == 0)
    {
      break;
    }
  }
  return 0;
}