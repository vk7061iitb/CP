#include <bits/stdc++.h>
using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

void openfile()
{
    if (!in.is_open() || !out.is_open())
    {
        cout << "Error opening the file!";
    }
}

void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis)
{
    vis[node] = true;
    for (auto child : graph[node])
    {
        if (vis[child])
        {
            continue;
        }
        dfs(child, graph, vis);
    }
    return;
}

int main()
{
    openfile();
    int v, e;
    in >> v >> e;

    vector<vector<int>> graph(v);
    vector<bool> vis(v, 0);

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        in >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (vis[i])
            continue;
        dfs(i, graph, vis);
        count++;
    }
    out << "No. of CC: " << count;
    return 0;
}