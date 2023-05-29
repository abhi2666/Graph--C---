/*
BFS --> you have to go to the breadth first and pick element from there

TC -> O(V) + O(2Edges)
SC -> O(V)

we will use a queue data structure to store the neighbour elements of a particular nodes
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.

    void bfs(int val, vector<int>&ans, vector<int>&visited, vector<int> adj[])
    {
        // we will use a queue
        // put the first element in queue and go on till the queue is not empty
        // ans.push_back(val);
        queue<int>q;
        q.push(val);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            // put that elements neighbour into queue 
            ans.push_back(node);
            
            for(int i : adj[node])
            {
                if(!visited[i])
                {
                    //pick that shit up
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V, 0);
        bfs(0, ans, visited, adj);

        return ans;
    }
};