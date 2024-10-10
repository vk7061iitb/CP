#include <bits/stdc++.h>
using namespace std;

void DFS(int vertex, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[vertex] = true;
    for (auto adjVx : graph[vertex])
    {
        cout << "Parent: " << vertex << " , Child: " << adjVx << "\t";
        cout << "Is vertex " << adjVx << " visted yet ? : ";
        cout << ((visited[adjVx]) ? "YES" : "NO") << endl;

        if (visited[adjVx])
            continue;
        cout << "Explore the vertex : " << adjVx << endl;
        DFS(adjVx, graph, visited);
    }
    cout << "BFS(" << vertex << ") is returned.\n";
    return;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    vector<bool> visited(V, 0);

    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (const auto &edge : graph[i])
        {
            cout << edge << " -> ";
        }
        cout << "NULL" << endl;
    }

    cout << endl;
    DFS(0, graph, visited);
    return 0;
}