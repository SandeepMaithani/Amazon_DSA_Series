/*

Method 1 :- Using DFS + Stack                                     Verdict : Accepted

Complexity Analysis :-

Time Complexity : O(V+E). The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is O(V + E).

Space Complexity : O(V). The extra space is needed for the stack.

*/


/*

Intution :-

The Key idea here is we can modify DFS to find Topological Sorting of a graph. In DFS, we start from a vertex, we
first print it and then recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary
stack. We don't print the vertex immediately, we first recursively call topological sorting for all its adjacent
vertices, then push it to a stack. Finally, print contents of stack. Note that a vertex is pushed to stack only when
all of its adjacent vertices (and their adjacent vertices and so on) are already in stack.

*/


void topoHelper(int start, vector<int> adj[], vector<bool>&visited, stack<int>&order) {
    visited[start] = true;

    for (auto neighbour : adj[start]) {
        if (visited[neighbour] != true) {
            topoHelper(neighbour, adj, visited, order);
        }
    }

    order.push(start);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int>order;
    vector<bool>visited(V, false);
    vector<int>solution;

    for (int i = 0; i < V; i++) {
        if (visited[i] != true) {
            topoHelper(i, adj, visited, order);
        }
    }

    while (!order.empty()) {
        solution.push_back(order.top());
        order.pop();
    }

    return solution;
}