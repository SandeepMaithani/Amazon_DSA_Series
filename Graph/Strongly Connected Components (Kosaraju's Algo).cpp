/*

Complexity Analysis :-

Time Complexity : O(V+E). our algorithm calls DFS, finds reverse of the graph and again calls DFS. DFS takes O(V+E) for a graph represented
using adjacency list. Reversing a graph also takes O(V+E) time. For reversing the graph, we simple traverse all adjacency lists.

Space Complexity : O(V). We need extra memory for the stack and visited vector which will cost at max O(V) memory.

*/


void fillerDFS(int src, vector<int> adj[], vector<bool>&visited, stack<int>&componentHelper) {
    if (visited[src]) {
        return;
    }

    visited[src] = true;

    for (auto neighbour : adj[src]) {
        if (visited[neighbour] == false) {
            fillerDFS(neighbour, adj, visited, componentHelper);
        }
    }

    componentHelper.push(src);
}

void checkerDFS(int src, vector<int> rev[], vector<bool>&visited) {
    if (visited[src]) {
        return;
    }

    visited[src] = true;

    for (auto neighbour : rev[src]) {
        if (visited[neighbour] == false) {
            checkerDFS(neighbour, rev, visited);
        }
    }

}

int kosaraju(int V, vector<int> adj[])
{
    stack<int>componentHelper;
    vector<bool>visited(V, false);

    int componentCount = 0;

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            fillerDFS(i, adj, visited, componentHelper);
        }
    }

    vector<int> rev[V];
    vector<bool>newVisited(V, false);

    for (int i = 0; i < V; i++) {
        for (auto neighbour : adj[i]) {
            rev[neighbour].push_back(i);
        }
    }

    while (!componentHelper.empty()) {
        int newSrc = componentHelper.top();
        componentHelper.pop();

        if (newVisited[newSrc] == false) {
            checkerDFS(newSrc, rev, newVisited);
            componentCount++;
        }
    }

    return componentCount;

}