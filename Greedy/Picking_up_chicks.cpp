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
  int t;
  cin >> t;
  int c = 1;
  while (t--)
  {
    int swaps = 0, n, k;
    long long b, t;
    cin >> n >> k >> b >> t;
    vector<long long> start, speed;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      start.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      speed.push_back(x);
    }
    int count = 0, cant = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      long long dist = b - start[i];
      long long cancover = t * speed[i];
      if (dist <= cancover)
      {
        count++;
        if (cant > 0)
        {
          swaps += cant;
        }
      }
      else
      {
        cant++;
      }
      if (count == k)
      {
        break;
      }
    }
    if (count < k)
    {
      cout << "Case #" << c++ << ": " << "IMPOSSIBLE" << endl;
    }
    else
    {
      cout << "Case #" << c++ << ": " << swaps << endl;
    }
  }
  return 0;
}