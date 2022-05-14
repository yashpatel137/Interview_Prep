int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
    set<vector<int>> st;
    vector<int> distance(n, n);
    vector<vector<vector<int>>> graph(n);
    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0], v = edgeList[i][1];
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 1});
    }
    distance[start] = 0;
    st.insert({0, start});
    while (st.empty() == false)
    {
        vector<int> u = *st.begin();
        st.erase(u);
        int node = u[1];
        for (int i = 0; i < graph[node].size(); i++)
        {
            int v = graph[node][i][0], weight = graph[node][i][1];
            if (distance[v] > distance[node] + weight)
            {

                if (distance[v] != n)
                {
                    st.erase({distance[v], v});
                }
				
                distance[v] = distance[node] + weight;
                st.insert({distance[v], v});
            }
        }
    }

    return distance[end];
}