/*

Complexity Analysis :-

Time Complexity : O(V+E). It will take same time as required in DFS traversal.

Space Complexity : O(V). We need extra memory for visited vector which will cost O(V) memory.

*/


/*

Intution :-

Key idea here is we will remove the edge for which we have to check and then we will do a simple DFS from first given
node and check whether second given node is reachable or not if it is reachable then given edge is not a bridge edge,
if its not reachable then given edge is a bridge edge.

*/


void dfs(list<int> adj[], vector<bool>&visited, int src) {
    if (visited[src] == true) {
        return;
    }

    visited[src] = true;

    for (auto neighbour : adj[src]) {
        if (visited[neighbour] == false) {
            dfs(adj, visited, neighbour);
        }
    }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    vector<bool>visited(V, false);

    adj[s].remove(e);
    adj[e].remove(s);

    dfs(adj, visited, s);

    if (visited[e] == false) {
        return true;
    }

    return false;
}