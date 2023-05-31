/*
You have to find total no. of proviences in a graph
(you have to find disconnected graphs)

Note: A province is a group of directly or indirectly
connected cities and no other cities outside of the group.
*/

class Solution
{
private:
  void dfs(int val, int visited[], vector<int> &adj[])
  {
    visited[val] = 1;

    for (int i : adj[val])
    {
      if (!visited[i])
      {
        dfs(i, visited, adj);
      }
    }
  }

public:
  int numProvinces(vector<vector<int>> adj, int V)
  {
    // for every vertex, you have to traverse the graph and for traversal increase the
    // counter

    // convert adjecency matrix into adjecency list
    vector<int> adjList[V]; // because for each node there can be V neighbours
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (adj[i][j] == 1 && i != j)
        {
          // this is an undirected graph
          adjList[i].push_back(j);
          adjList[j].push_back(i);
        }
      }
    }

    // now for each element perform DFS/BFS
    int visited[V] = {0};
    int count = 0;
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        count++;
        dfs(i, visited, adjList);
      }
    }

    return count;
  }
};
