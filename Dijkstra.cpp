/*
Dijkstra --> Dijkstra algo is used to find the shortest distance path from source node to all
other nodes.

We can do that by using set or priority queue with a traversal technique like BFS/DFS..

*/

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st; // this set will store the {distance, node}
        vector<int> visited(V, 1e9);

        // for the the soruce node its distance will 0 from itself
        visited[S] = 0;
        st.insert({0, S}); // {distance, node}

        while (!st.empty())
        {
            // pick the pair at the begining
            auto it = *(st.begin());
            // extract the Node and its distance
            int distance = it.first;
            int node = it.second;
            st.erase(it); // it will be holding the pair itself.. so it will delete that pair
            for (auto i : adj[node])
            {
                int edgeWeight = i[1];
                int adjNode = i[0];

                if (distance + edgeWeight < visited[adjNode])
                {
                    // check if there is any enteries already made
                    if (visited[adjNode] != 1e9)
                    {
                        st.erase({visited[adjNode], adjNode});
                    }

                    visited[adjNode] = edgeWeight + distance;
                    // put that in set also
                    st.insert({visited[adjNode], adjNode});
                }
            }
        }

        return visited;
    }
};