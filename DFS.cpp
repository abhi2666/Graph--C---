class Solution {
  public:

    void dfs(int value, int V, int visited[], vector<int> adj[], vector<int>&ls)
    {
        // take its value and mark it as visited
        ls.push_back(value);
        visited[value] = 1;

        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                dfs(it, V, visited, adj, ls);
            }
        }
        return;
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int visited[V] = {0};
        vector<int> ls;
        dfs(0 V, visited, adj, ls);

        return ls;
    }
};