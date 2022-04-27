#include <iostream>
//Method 1
#include <vector>
using namespace std;
struct Edge {
    int src, dest;
};
class Graph
{
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " ——> ";
        for (int v: graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
    int n = 6;
    Graph graph(edges, n);
    printGraph(graph, n);
 
    return 0;
}
//Method 2
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
	vector<int> graph[n];
	for(int i = 0; i < edges.size(); i++)
    {
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}
	vector<vector<int>> adjacencyList(n);

	for(int i = 0; i < n; i++) {
		adjacencyList[i].push_back(i);

		for(int j = 0; j < graph[i].size(); j++) {
			adjacencyList[i].push_back(graph[i][j]);
		}
	}

	return adjacencyList;
}