bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
        else if (*i != parent)
           return true;
    }
    return false;
}

bool Graph::isTree()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    if (isCyclicUtil(0, visited, -1))
             return false;
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
 
    return true;
}
