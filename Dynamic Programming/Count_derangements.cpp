//Method 1 TC=O(n^2) SC=O(logn)
#include <bits/stdc++.h>
using namespace std;
 
int countDer(int n)
{
  if (n == 1) return 0;
  if (n == 2) return 1;
  return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}

//Method 2 TC=O(n) SC=O(n)
//DP
int countDer(int n)
{
    int der[n + 1] = {0};
    der[1] = 0;
    der[2] = 1;
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]);
    return der[n];
}

//Method 3 TC=O(n) SC=O(1)
int countDer(int n)
{
    if (n == 1 or n == 2) {
        return n - 1;
    }
    int a = 0;
    int b = 1;
    for (int i = 3; i <= n; ++i) {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }
    return b;
}