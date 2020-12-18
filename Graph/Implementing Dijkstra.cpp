/*

Complexity Analysis :-

Time Complexity : O(V*V) or  O(E*Log(V)) .

If the input graph is represented using adjacency matrix then time it cost will be O(V*V) as we will be visiting each
and every cell of matrix. If the input graph is represented using adjacency list then it will cost O(E*Log(V)) time,
Since each insertion take logrithmic time in a heap and we will doing total E no of insertion and at max V no of element
can be there in min Heap so it will cost O(E*Log(V)) time.

Space Complexity : O(V).

We need extra memory for the visited array and min heap which will cost O(V) memory.

*/


/*

Intution :-

Key idea here is if we implement BFS traversal with the help of a priority queue(Min heap) instead of a normal queue
then our BFS traversal will work similar way as a dijkstra Algorithm work in other word if we implement BFS traversal
with the help of min heap and keep track of cost it will give us shortest path to that node from source node.

*/


vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
	vector<bool>visited(V, false);
	vector<int>distance(V);

	priority_queue<pair<int, int>, vector<pair<int , int>>, greater<pair<int, int>>>minHeap;
	minHeap.push({0, src});

	while (!minHeap.empty()) {
		int curCost = minHeap.top().first;
		int curNode = minHeap.top().second;

		minHeap.pop();

		if (visited[curNode] == true) {
			continue;
		}

		visited[curNode] = true;
		distance[curNode] = curCost;

		for (int neighbour = 0; neighbour < V; neighbour++) {
			if (visited[neighbour] == false && g[curNode][neighbour] != 0) {
				int newCost = curCost + g[curNode][neighbour];
				minHeap.push({newCost, neighbour});
			}
		}
	}

	return distance;
}