#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<bool>> adjM(V, vector<bool>(V, 0)); // adjacency matrix
    vector<vector<int>> adjL(V);                      // adjacency list

    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adjM[v1][v2] = 1;
        adjM[v2][v1] = 1;

        adjL[v1].push_back(v2);
        adjL[v2].push_back(v1);
    }

    cout << "Adjacency Matrix: \n";
    for (const auto &row : adjM)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (const auto &edge : adjL[i])
        {
            cout << edge << " -> ";
        }
        cout << "NULL" << endl;
    }

    // check i and j are connected or not
    // if adjM[i][j] == 1 //connected vetices
    // for(auto child:adjL[i]){
    //      if(child == j){
    //          // connected
    //      }
    //}

    return 0;
}
