#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

#define V 4

int countTriangle(int g[V][V], bool isDirected)
{
  int count = 0;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      for (int k = 0; k < V; k++)
      {
        if (g[i][j] and g[j][k] and g[k][i])
        {
          count++;
        }
      }
    }
  }
  return isDirected ? count /= 3 : count /= 6;
}

int main() {
  init_code();
  int graph[][V] = { {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
  };
  int digraph[][V] = { {0, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 1, 0, 0},
    {0, 0, 1, 0}
  };
  cout << "The Number of triangles in undirected graph : " << countTriangle(graph, false);
  cout << "\n\nThe Number of triangles in directed graph : " << countTriangle(digraph, true);

  return 0;
}