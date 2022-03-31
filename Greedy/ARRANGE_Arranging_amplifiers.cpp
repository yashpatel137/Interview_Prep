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
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n], one = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      if (arr[i] == 1)
      {
        one++;
      }
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < one; i++)
    {
      cout << "1 ";
    }
    if ((n - one) == 2 and arr[1] == 2 and arr[0] == 3)
    {
      cout << "2 3" << endl;
    }
    else
    {
      for (int i = 0; i < (n - one); i++)
      {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}