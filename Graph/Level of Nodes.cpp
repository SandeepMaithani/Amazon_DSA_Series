/*

Complexity Analysis :-

Time Complexity: O(N). In BFS traversal every node is visited only once, so Time Complexity is O(N).

Space Complexity: O(N). The space is required to store the nodes in a queue.

*/


/*

Intution :-

Key idea here is to use BFS(Breadth-First Search) traversal, it is a graph traversal technique where a node
and its neighbours are visited first and then the neighbours of neighbours. In simple terms, it traverses
level-wise from the source. First, it traverses level 1 nodes (direct neighbours of source node) and then
level 2 nodes (neighbours of source node) and so on. We will mark each node to its respective level from source
node and using that marking BFS can be used to determine the level of each node from a given source node.

*/


int levels(vector<int> g[], int N, int X)
{
    queue<pair<int, int>>bfsHelper;
    vector<bool>visited(N, false);

    bfsHelper.push({0, 0});

    while (!bfsHelper.empty()) {
        int currNode = bfsHelper.front().first;
        int currLevel = bfsHelper.front().second;
        bfsHelper.pop();

        if (visited[currNode] == true) {
            continue;
        }

        visited[currNode] = true;

        if (currNode == X) {
            return currLevel;
        }

        for (auto neighbour : g[currNode]) {
            if (visited[neighbour] == false) {
                bfsHelper.push({neighbour, currLevel + 1});
            }
        }
    }

    return -1;
}