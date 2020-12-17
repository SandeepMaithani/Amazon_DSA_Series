/*

Complexity Analysis :-

Time Complexity: O(E*Log(V)). Since each insertion take logrithmic time in a heap and we will doing total E no of
insertion and at max V no of element can be there in min Heap so it will cost O(E*Log(V)) time.

Space Complexity: O(V). We need O(V) extra memory for the visited array and min heap.

*/


/*

Intution :-

Key idea here is use prims Algorithms to get the minimum spanning tree.


*/

void primsAlgo(vector<vector<int>>&graph, vector<bool>&visited, int &cost) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minHeap;
    minHeap.push({0, 0});

    while (!minHeap.empty()) {

        int nodeCost = minHeap.top().first;
        int curNode = minHeap.top().second;

        minHeap.pop();

        if (visited[curNode] == true) {
            continue;
        }

        cost = cost + nodeCost;
        visited[curNode] = true;

        for (int neighbour = 0; neighbour < graph[curNode].size(); neighbour++) {
            if (visited[neighbour] == false && graph[curNode][neighbour] != 0) {
                minHeap.push({graph[curNode][neighbour], neighbour});
            }
        }
    }
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<bool>visited(V, false);
    int cost = 0;

    primsAlgo(graph, visited, cost);

    return cost;
}