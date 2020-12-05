/*

Complexity Analysis :-

Time Complexity: O(V+E). Time Complexity of our method is same as time complexity of DFS traversal which is O(V+E).

Space Complexity: O(V). To store the visited and recursion stack O(V) space is needed.

*/


/*

Intution :-

Key idea here is we will maintain a visited array and ancestor array to keep track of visited node and any node have
a neighbour which is also its ancestor it will result in cycle if it is not the case then we will check for all the
neighbour of that particular node this process we will do again and agian for all the unvisited nodes.

*/


bool cycleHelper(int V, vector<int> adj[], vector<bool> &visited, vector<bool> &ances, int start) {
    visited[start] = true;
    ances[start] = true;

    for (auto neighbour : adj[start]) {
        if (!visited[neighbour]) {
            if (cycleHelper(V, adj, visited, ances, neighbour)) {
                return true;
            }
        }
        else if (ances[neighbour]) {
            return true;
        }
    }

    ances[start] = false;

    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool>visited(V, false);
    vector<bool>ances(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (cycleHelper(V, adj, visited, ances, i)) {
                return true;
            }
        }
    }

    return false;
}