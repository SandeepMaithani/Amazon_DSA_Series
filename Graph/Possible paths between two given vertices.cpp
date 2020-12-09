/*

Complexity Analysis :-

Time Complexity: O(N!). If the graph is complete then there can be around N! recursive calls, so the time Complexity of our solution will be O(N!)

Space Complexity: O(1). Since no extra space is required.

*/


/*

Intution :-

Key idea here is we will visit all the possible path and after visiting each and every path if we reach to our final
destination using that path then that path must be a valid path and we will increase our valid path count each time
we reached at our destination after following a certain path.


*/


void pathHelper(list<int> g[], vector<bool>&visited, int src, int dest, int &countPath) {
    if (src == dest) {
        countPath++;
        return;
    }

    visited[src] = true;

    for (auto neighbour : g[src]) {
        if (visited[neighbour] == false) {
            pathHelper(g, visited, neighbour, dest, countPath);
        }
    }

    visited[src] = false;
}

int countPaths(list<int> g[], int V, int s, int d) {

    vector<bool>visited(V, false);
    int countPath = 0;

    pathHelper(g, visited, s, d, countPath);

    return countPath;
}